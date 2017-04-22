/*******************************************************
 * File Name: system_init.h
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description: Header file for the system 
 * initialization.
********************************************************/

#ifndef SYSTEM_INIT
#define SYSTEM_INIT

#define ON  1
#define OFF 0
#define ACCELERATE_B    7
#define PIRATE_SWITCH   0
#define PC_ON_OFF       5

#define USART_BAUDRATE 76800  
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16)) - 1 )

#define USART1_BAUDRATE 115200  
#define BAUDVALUE_1  ((F_CPU/(USART1_BAUDRATE * 16)))

void system_init();
void enable_timer();
void disable_timer();

//uint8_t datalogging;

#endif
