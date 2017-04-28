/*******************************************************
 * File Name: uart.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description:
********************************************************/

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "uart.h"
#include "system_init.h"
#include "conversions.h"

//VESC Specific header files (some may not be needed)
#include "bldc_interface.h"
#include "bldc_interface_uart.h"
#include "datatypes.h"
#include "buffer.h"
#include "packet.h"
#include "crc.h"

/**************************************************************************************
 * Name: uart0_init
 *
 * Description: RXD0 is PORT E bit 0
 *              TXD0 is PORT E bit 1
 *************************************************************************************/
void uart0_init(unsigned char ubrr){
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);            //INTERRUPTS ENABLED
    //UCSR0B |= (1<<RXEN0) | (1<<TXEN0);                        //INTERRUPS DISABLED

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
    UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1);             //INTERRUPTS ENABLED
    //UCSR1B |= (1<<RXEN1) | (1<<TXEN1);                         //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10) | (1<<USBS1);
    UBRR1H = (unsigned char)(ubrr >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR1L =  (unsigned char)ubrr;       //load lower byte of the baud rate into UBRR 
}//uart1_init
//******************************************************************

void bldc_val_received(mc_values *val){
	float WattHrDrawn = val.watt_hours;
	USART0_RX(WattHrDrawn, 1);
}

/************************************************************************************************
 * Name: send_packet
 *
 * Description: This function takes a pointer to the start of an 8-bit data array 'data',
 * and the length of the array 'len', as an input argument. UART Implementation of 
 * VESC "send_packet" function, to be used with Prototype vehicle control system.
 * NOTE: Data is sent via UART1 at a baudrate of 115200. High logic level = 3.3Vdc. 
 ************************************************************************************************/
void send_packet(unsigned char *data, unsigned int len){
    
	int i = 0;
	
    //Wait for empty transmit buffer
    while(!(UCSR1A & (1<<UDRE1))) { }
	
	//Send a packet of length 'len'
    for(i = 0; i < len;i++) {
        UDR1 = data[i];
		//Wait for byte to be sent before sending next byte
		while(!(UCSR1A & (1<<UDRE1))) { }
		//Delay may not be needed anymore
		//_delay_us(10);
    }
}//send_packet

/*****************************************************************************************
 *  Name: USART0_RX
 *
 *  Description: Recieve an unsigned 8-bit variable size array on USART0
 ****************************************************************************************/
void USART0_RX(uint8_t* rx_buf, uint8_t n){
	
    int i = 0;

	//Wait for data to be received	
	while (!(UCSR0A & (1<<RXC0))) {}
	
	//Get and return received data to rx_buf 	
	for(i=0; i<n; i++){
		uint8_t data = UDR0;
        rx_buf[i] = data;
		while (!(UCSR0A & (1<<RXC0))) {}	
	}
}//USART0_RX

/*****************************************************************************************
 *  Name: USART1_RX
 *
 *  Description: Recieve an unsigned 8-bit variable size array on USART1
 ****************************************************************************************/
void USART1_RX(uint8_t* rx_buf, uint8_t n){
	
	int i = 0;
	
	//Wait for data to be received 
	while (!(UCSR1A & (1<<RXC1))) {}

	//Get and return received data to rx_buf
	for(i=0; i<n; i++){
		uint8_t data = UDR1;
		rx_buf[i] = data;
		while (!(UCSR1A & (1<<RXC1))) {}
	}
}//USART1_RX

