/********************************************************
 * File Name: conversions.h
 *
 *
 * *****************************************************/

#ifndef UART_H
#define UART_H

void uart0_init();
void uart1_init();
void uart0_uchar(unsigned char* packet);
void uart1_uchar(unsigned char* packet);

#endif
