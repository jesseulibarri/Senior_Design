
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "uart.h"
#include "system_init.h"

/**************************************************************************************
 * Name: uart0_init
 *
 * Description: RXD0 is PORT E bit 0
 *              TXD0 is PORT E bit 1
 *************************************************************************************/
void uart0_init(unsigned char ubrr){
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    //UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00) | (1<<USBS0);
    UBRR0H = (unsigned char)(ubrr >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR0L =  (unsigned char)ubrr;       //load lower byte of the baud rate into UBRR 
}//uart0_init

/**************************************************************************************
 * Name: uart1_init
 *
 * Description: RXD1 is PORT D bit 2
 *              TXD1 is PORT D bit 3
 *************************************************************************************/
void uart1_init(unsigned char ubrr){
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1); //INTERRUPTS ENABLED
   // UCSR1B |= (1<<RXEN1) | (1<<TXEN1);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10) | (1<<USBS1);
    UBRR1H = (unsigned char)(ubrr >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR1L =  (unsigned char)ubrr;       //load lower byte of the baud rate into UBRR 
}//uart1_init
//******************************************************************

/**************************************************************************************
 * Name: uart0_uchar_transmit
 *
 * Description: 
 *************************************************************************************/
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


/**************************************************************************************
 * Name: uart1_uchari_transmit
 *
 * Description: 
 *************************************************************************************/
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

/***************************************************************************************
* Name: uart0_uint8_transmit
*
* Description:
*
****************************************************************************************/
void uart0_uint8_transmit(uint8_t data_array[], int n){

	int i = 0;
	
	//Wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0))) {}

	for(i=0; i<n; i++){
		UDR0 = data_array[i];
	while(!(UCSR0A & (1<<UDRE0))) {}
	_delay_us(100);
	}
}//uart1_transmit

/***************************************************************************************
* Name: uart1_uint8_transmit
*
* Description:
****************************************************************************************/
void uart1_uint8_transmit(uint8_t data_array[], int n){

	int i = 0;
	
	//Wait for empty transmit buffer
	while(!(UCSR1A & (1<<UDRE1))) {}

	for(i=0; i<n; i++){
		UDR1 = data_array[i];
	while(!(UCSR1A & (1<<UDRE1))) {}
	_delay_us(100);
	}
}//uart1_transmit

/*****************************************************************************************
 *  Name: uart1_uint8_receive
 *
 *  Description: Recieve an unsigned 8 bit int from matlab that will simulate a feedback
 *      speed.
 ****************************************************************************************/
void uart1_uint8_receive(){



}



