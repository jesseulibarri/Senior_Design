#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define PACKET_SIZE 4

#define USART_BAUDRATE 76800
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

#define USART1_BAUDRATE 76800 
#define BAUDVALUE_1  ((F_CPU/(USART1_BAUDRATE * 16UL)) - 1 )


uint8_t i = 0;
char rx_buf[4];
unsigned char num_bytes[4];
float number;

//******************************************************************
//                            uart_init
//
//RXD0 is PORT E bit 0
//TXD0 is PORT E bit 1
//Jumpers J14 and J16 (mega128.1) or Jumpers J7 and J9 (mega128.2)
//must be in place for the MAX232 chip to get data.

void uart_init(){
//rx and tx enable, receive interrupt enabled, 8 bit characters
UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
//UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

//async operation, no parity,  one stop bit, 8-bit characters
  UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
  UBRR0H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
  UBRR0L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 

}
//******************************************************************

//******************************************************************
//                            uart1_init
//
//RXD0 is PORT E bit 0
//TXD0 is PORT E bit 1
//Jumpers J14 and J16 (mega128.1) or Jumpers J7 and J9 (mega128.2)
//must be in place for the MAX232 chip to get data.

void uart1_init(){
//rx and tx enable, receive interrupt enabled, 8 bit characters
UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1); //INTERRUPTS ENABLED
//UCSR1B |= (1<<RXEN1) | (1<<TXEN1);               //INTERRUPS DISABLED

//async operation, no parity,  one stop bit, 8-bit characters
  UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10);
  UBRR1H = (BAUDVALUE_1 >>8 ); //load upper byte of the baud rate into UBRR 
  UBRR1L =  BAUDVALUE_1;       //load lower byte of the baud rate into UBRR 

}
//******************************************************************


 void uart0_uchar_transmit(unsigned char packet[]) {
    //make sure that nothing else is sending
    while(!(UCSR0A & (1<<UDRE0))) { }
    int8_t i;
    for(i = 0; i < PACKET_SIZE; i++) {
        UDR0 = packet[i];
        while(!(UCSR0A & (1<<UDRE0))) { }
        _delay_us(20);
    }
/*    //send terminator
    UDR0 = '\n';
    while(!(UCSR0A & (1<<UDRE0))) { } 
*/
}//uart0_uchar

void uart1_uchar_transmit(unsigned char packet[]) {
   //make sure that nothing else is sending
   while(!(UCSR1A & (1<<UDRE1))) { }
   int8_t i;
   for(i = 0; i < PACKET_SIZE; i++) {
       UDR1 = packet[i];
       while(!(UCSR1A & (1<<UDRE1))) { }
       _delay_us(20);
   }
/*    //send terminator
    UDR1 = '\n';
    while(!(UCSR1A & (1<<UDRE1))) { } 
*/
}


void float_to_bytes(float* src, unsigned char* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = *src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes

void bytes_to_float(char* src, float* dest) {
    union {
        float a;
        char bytes[4];
    } u;
    memcpy(u.bytes, src, 4);
    *dest = u.a;
}

ISR(TIMER0_OVF_vect) {
    float_to_bytes(&number, num_bytes);
    uart1_uchar_transmit(num_bytes);
}

ISR(USART0_RX_vect) {
    static uint8_t i;
    char data  = UDR0;
    if(data == 'G') {
        i = 0;
        number = atof(rx_buf);
        //bytes_to_float(rx_buf, &number);

    } else {
        rx_buf[i] = data;
        i++;
    }

}//ISR


int main() {

    /******** System Timer *********/
    //Initialize 16 bit Timer/Counter 1 for Fast PWM, TOP=24,999
    //  16MHz, pre-scale=64, TOP=24,999, freq=10Hz, period=100mS
    TCCR1A |= (1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM13)|(1<<WGM12);
    //Set Prescalar to 64
    TCCR1B |= (1<<CS11)|(1<<CS10);
    //Set Output Comare Match A Value (TOP value)
    OCR1A = 24999; 
    //Interrupt on timer overflow (at TOP value)
    TIMSK |= (1<<TOIE1);

uart1_init();
sei();

    while(1) { }//while
return 0;
}//main
