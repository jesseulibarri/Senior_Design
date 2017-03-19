/********************************************************
 * File Name: uart.h
 *
 *
 * *****************************************************/

#include<stdint.h>

#ifndef UART_H
#define UART_H

void uart0_init(unsigned char);
void uart1_init(unsigned char);
void uart0_uchar_transmit(unsigned char* packet, float f_num);
void uart1_uchar_transmit(unsigned char* packet, float f_num);
void uart1_package_transmit(unsigned char* torque_l, unsigned char* torque_r, unsigned char* angle, float torque_right, float torque_left, float steer_angle);
void uart0_uint8_transmit(uint8_t data_array[], int n);
void uart1_uint8_transmit(uint8_t data_array[], int n);
unsigned char USART_Receive( void );
void USART0_RX(uint8_t* rx_buf, uint8_t n);
#endif
