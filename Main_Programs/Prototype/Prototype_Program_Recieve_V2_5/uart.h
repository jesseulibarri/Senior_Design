/*******************************************************
 * File Name: uart.h
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description:
********************************************************/

#include<stdint.h>

#ifndef UART_H
#define UART_H
void uart0_init(unsigned char);
void uart1_init(unsigned char);
void send_packet(unsigned char *data, unsigned int len);
void bldc_val_received(mc_values *val);
void USART1_RX(uint8_t* rx_buf, uint8_t n);
void USART0_RX(uint8_t* rx_buf, uint8_t n);
#endif
