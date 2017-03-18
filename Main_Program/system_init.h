/***************************************************
 * File Name: system_init.h
 * Author: Jesse Ulibarri
 * Date: 1/4/17
 *
 * Description: Header file for the system 
 *  initialization.
***************************************************/

#ifndef SYSTEM_INIT
#define SYSTEM_INIT

#define ON  1
#define OFF 0
#define TIRE_DIAM       22
#define SPROCKET_TEETH  42
#define ACCELERATE_B    6
#define CRUISE_B        7
#define PIRATE_SWITCH   0
#define PC_ON_OFF       5
#define PACKET_SIZE     4

#define USART_BAUDRATE 76800  
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

#define USART1_BAUDRATE 115200  
#define BAUDVALUE_1  ((F_CPU/(USART1_BAUDRATE * 16UL)) - 1 )

extern float tire_circ;
extern float distance_per_pulse;

void system_init();

//uint8_t datalogging;

#endif
