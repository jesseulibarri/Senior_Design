#include "stm32l4xx.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "datatypes.h"

#define BAUDRATE1        115200 
#define BAUDRATE3        9600 

#define TX1_PORT         GPIOB
#define RX1_PORT         GPIOB
#define TX1_PIN          6 
#define RX1_PIN          7 
#define TX1_AF           7
#define RX1_AF           7

#define TX3_PORT         GPIOC
#define RX3_PORT         GPIOC
#define TX3_PIN          4 
#define RX3_PIN          5 
#define TX3_AF           7
#define RX3_AF           7

xSemaphoreHandle tx_new_data_semp;
xSemaphoreHandle tx_tc_semp;
xSemaphoreHandle tx_dma_semp;

void uart1_task_init();
void uart1_init();
void uart1_sendl(char* to_send);
void uart1_rx_isr_callback();
BUFFER_STATUS uart1_send_frame(struct DataFrame_t *frame);

void uart3_init();
void uart3_sendl(char* to_send);

/* move to helpers header */
void UART1_RxTask(void *param);
void UART1_TxTask(void *param);
