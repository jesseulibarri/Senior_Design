#include <stdio.h>
#include <string.h>
#include "stm32l4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "uart.h"
#include "pin.h"
#include "frame.h"
#include "datatypes.h"
#include "commands.h"

static volatile struct DataFrame_t isr_buf;
static volatile struct DataFrame_t rx_frame;

static void uart1_dma_init();
static void uart1_dma_load(uint32_t source, uint16_t len);

static BaseType_t xHigherPriorityTaskWoken;
static TaskHandle_t RX_Task_Handle;
static TaskHandle_t TX_Task_Handle;

static void UART1_RX_Task(void *param);
static void UART1_TX_Task(void *param);

/* this is pretty damn big... */
static struct UART_Buffer_t {
    struct DataFrame_t      data[16];
    uint8_t                   front;
    uint8_t                    back;
	uint8_t                    size;
    BUFFER_STATUS            status;
} uart1_tx_buffer;

static void uart1_buffer_write(struct UART_Buffer_t *buf, struct DataFrame_t *frame);
static void uart1_buffer_read(struct UART_Buffer_t *buf, struct DataFrame_t **frame);
static void uart1_buffer_init(struct UART_Buffer_t *buf);

void uart1_buffer_init(struct UART_Buffer_t *buf){
    buf->front = 0;
    buf->back = 0;
    buf->size = 16;
    buf->status = BUFFER_EMPTY;
}

void uart1_buffer_write(struct UART_Buffer_t *buf, struct DataFrame_t *frame){
    uint8_t next_index = (((buf->back)+1) % buf->size);
    if(buf->status != BUFFER_FULL){
        /* copy to buffer */
        struct DataFrame_t *tmp = &(buf->data[buf->back]);
        memcpy(tmp->data, frame->data, frame->length);
        tmp->length = frame->length;
        tmp->crc = frame->crc;
        /* move back up one */
        buf->back = next_index;
        if(next_index == buf->front)
            buf->status = BUFFER_FULL;
        else
            buf->status = BUFFER_READY;
    }
}

void uart1_buffer_read(struct UART_Buffer_t *buf, struct DataFrame_t **frame){
    if (buf->status != BUFFER_EMPTY){
        /* copy from buffer */
        *frame = &(buf->data[buf->front]);
        buf->data[buf->front].status = FRAME_STATUS_OK;
        /* move to next item */
        buf->front = (((buf->front)+1) % buf->size);
        if (buf->back == buf->front)
            buf->status = BUFFER_EMPTY;
    }
    else{
        *frame = NULL;
    }
}

void uart1_rx_isr_callback(){

    unsigned char tmp = USART1->RDR;
    /* found the end of the frame. copy frame for processing */
    if(tmp == 0x00){
        memcpy((char *)rx_frame.data, (char *)isr_buf.data, isr_buf.length);
        rx_frame.length = isr_buf.length;
        isr_buf.length = 0;
        xHigherPriorityTaskWoken = pdFALSE;
        if(RX_Task_Handle != NULL){
            vTaskNotifyGiveFromISR(RX_Task_Handle, &xHigherPriorityTaskWoken);
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    }
    else{
        /* if buffer is full... just start rewriting. something
         * went wrong, protocol will figure it out */
        if(isr_buf.length == DATAFRAME_SIZE){
            isr_buf.length = 0;
        }
        isr_buf.data[isr_buf.length] = tmp;
        isr_buf.length++;
    }

}

void uart1_task_init(){

    uart1_init();
    /* initialize rx isr buffer */
    frame_init((struct DataFrame_t *)&isr_buf);
    /* initialize tx buffer */
    uart1_buffer_init(&uart1_tx_buffer);

    xTaskCreate(UART1_TX_Task, "UART1 TX", 100, NULL, 3, &TX_Task_Handle);
    xTaskCreate(UART1_RX_Task, "UART1 RX", 100, NULL, 3, &RX_Task_Handle);
}

static void UART1_RX_Task(void *param){

    RX_Task_Handle = xTaskGetCurrentTaskHandle();
    while(1){
        /* wait for a new frame */
        uint32_t flag = ulTaskNotifyTake(pdTRUE, 100);
        if(flag){
            RX_Task_Handle = xTaskGetCurrentTaskHandle();
            /* valid frame needs: 
             *   - 1 command byte
             *   - at least 1 data byte 
             *   - 2 CRC bytes */
            if(rx_frame.length >= 4){
                rx_frame.operation = FRAME_OP_DECODE;
                /* dataframe and pointer to callback function for responding */
                frame_process((struct DataFrame_t *)&rx_frame);
                if(rx_frame.status == FRAME_STATUS_DECODED){
                    command_process((struct DataFrame_t *)&rx_frame);
                }
            }
            /*RX_Task_Handle = xTaskGetCurrentTaskHandle();*/
        }
    }
}

BUFFER_STATUS uart1_send_frame(struct DataFrame_t *frame){
    if(uart1_tx_buffer.status != BUFFER_FULL){
        uart1_buffer_write(&uart1_tx_buffer, frame);
        xTaskNotifyGive(TX_Task_Handle);
        return BUFFER_OK;
    }
    else{
        return BUFFER_FULL;
    }
}

static void UART1_TX_Task(void *param){

    struct DataFrame_t *frame;
    uart1_dma_init();

    /* initialize binary semaphors */
    vSemaphoreCreateBinary(tx_new_data_semp);
    vSemaphoreCreateBinary(tx_dma_semp);
    vSemaphoreCreateBinary(tx_tc_semp);
    /* this has to be here. can't go in uart init for some reason */
    USART1->CR1 |= USART_CR1_TCIE;

    while(1){
        uint32_t flag = ulTaskNotifyTake(pdFALSE, 100);	
        if(flag){
            /* set data length and enable DMA channel */
            uart1_buffer_read(&uart1_tx_buffer, &frame);
            if(frame){
                /* block on waiting for DMA 'available/complete' semaphore */
                xSemaphoreTake(tx_dma_semp, portMAX_DELAY);
                /* block on waiting for TC (transmission complete) semaphore */
                xSemaphoreTake(tx_tc_semp, portMAX_DELAY);
                /* add trailing 0x00 for end of frame */
                frame->data[frame->length] = 0x00;
                frame->length++;
                uart1_dma_load((uint32_t)&(frame->data[0]), frame->length);
            }
        }
    }
}

static void uart1_dma_load(uint32_t source, uint16_t len){
    DMA1_Channel4->CCR &= ~DMA_CCR_EN;
    DMA1_Channel4->CMAR = source;
    DMA1_Channel4->CNDTR = len;
    DMA1_Channel4->CCR |= DMA_CCR_EN;
}

static void uart1_dma_init(){
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
    /* DMA1 Channel 4 set to uart1 TX */
    DMA1_CSELR->CSELR |= 0x02 << 12;
    /* set destination */
    DMA1_Channel4->CPAR = (uint32_t)&(USART1->TDR);
    /* auto increment memory pointer */
    DMA1_Channel4->CCR |= DMA_CCR_MINC; 
    /* read from memory -> transfer to peripheral */
    DMA1_Channel4->CCR |= DMA_CCR_DIR; 
    DMA1_Channel4->CCR |= DMA_CCR_PL_0; 
    /* enable transfer complete interrupt */
    NVIC_SetPriority(DMA1_Channel4_IRQn, 9);
    NVIC_EnableIRQ(DMA1_Channel4_IRQn);
    DMA1_Channel4->CCR |= DMA_CCR_TCIE; 
    DMA1_Channel4->CCR |= DMA_CCR_TEIE; 

}

void uart1_init(){

    /* enable peripheral */
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    /* set gpios */
    pin_af_init(TX1_PORT, TX1_PIN, TX1_AF, PULLUP);
    pin_af_init(RX1_PORT, RX1_PIN, RX1_AF, PULLUP);

    /* by default: word length 8-bit, 1 stop bit */
    uint32_t usartdiv = (uint32_t)(SystemCoreClock/BAUDRATE1);
    uint32_t brrtemp = usartdiv;

    USART1->BRR = brrtemp;

    /* DMA for transmit */
    USART1->CR3 |= USART_CR3_DMAT;

    /* enable USART */
    USART1->CR1 |= USART_CR1_UE;

    /* enable transmitter */
    USART1->CR1 |= USART_CR1_TE;

    /* enable receiver */
    USART1->CR1 |= USART_CR1_RE;

    /* register error interrupt */
    NVIC_SetPriority(USART1_IRQn, 8);
    NVIC_EnableIRQ(USART1_IRQn);

    /* enable RX interrupt */
    USART1->CR1 |= USART_CR1_RXNEIE;
}

void uart1_sendl(char* to_send){
    
    for(uint8_t i=0; i < strlen(to_send); i++){
        while(!(USART1->ISR & USART_ISR_TXE));
        USART1->TDR = to_send[i];
    }

    char new_line[] = "\r\n";
    for(uint8_t i=0; i < strlen(new_line); i++){
        while(!(USART1->ISR & USART_ISR_TXE));
        USART1->TDR = new_line[i];
    }

    while(!(USART1->ISR & USART_ISR_TC));
}

void uart3_init(){

    /* enable peripheral */
    RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN;

    /* set gpios */
    pin_af_init(TX3_PORT, TX3_PIN, TX3_AF, PULLUP);
    pin_af_init(RX3_PORT, RX3_PIN, RX3_AF, PULLUP);

    /* by default: word length 8-bit, 1 stop bit */
    uint32_t usartdiv = (uint32_t)(SystemCoreClock/BAUDRATE1);
    uint32_t brrtemp = usartdiv;

    USART3->BRR = brrtemp;

    /* enable USART */
    USART3->CR1 |= USART_CR1_UE;

    /* enable transmitter */
    USART3->CR1 |= USART_CR1_TE;

    /* enable receiver */
    USART3->CR1 |= USART_CR1_RE;

    /* register interrupt */
    /* priority cannot be set lower than 5*/
    NVIC_SetPriority(USART3_IRQn, 8);
    NVIC_EnableIRQ(USART3_IRQn);
    USART3->CR1 |= USART_CR1_RXNEIE;
}


void uart3_sendl(char* to_send){
    
    for(uint8_t i=0; i < strlen(to_send); i++){
        while(!(USART3->ISR & USART_ISR_TXE));
        USART3->TDR = to_send[i];
    }

    char new_line[] = "\n";
    for(uint8_t i=0; i < strlen(new_line); i++){
        while(!(USART3->ISR & USART_ISR_TXE));
        USART3->TDR = new_line[i];
    }

    while(!(USART3->ISR & USART_ISR_TC));
}
