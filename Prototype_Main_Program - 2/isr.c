/*******************************************************
 * File Name: isr.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description:
********************************************************/

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "system_init.h"
#include "pirate.h"
#include "conversions.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>

//VESC Specific header files (some may not be needed)
#include "bldc_interface.h"
#include "bldc_interface_uart.h"
#include "buffer.h"
#include "packet.h"
#include "crc.h"

#define ACCELERATE      0xBF
#define CRUISE          0x9F
#define PIRATE          0xFE
#define MAX_TORQUE_CUR  20
#define TRUE	1
#define FALSE   0

float motor_torque = 0.0;
unsigned char motor_torque_bytes[4];
float speed = 0.0;
unsigned char speed_bytes[4];
float base_torque;
unsigned char base_torque_bytes[4];
uint16_t timestamp_dif = 20000;

/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER3_OVF_vect) {

	uint8_t user_mode = PINF | 0x9F; //Mask everything out except PORTF
	
    switch(user_mode){ 
    //All button released
	case NO_INPUT:
        motor_torque = 0;
        bldc_interface_set_current(0);
        break;
       
    //Accelerate button is pushed
	case ACCELERATE:
		base_torque = base_torque + 0.6;
		if(base_torque > MAX_TORQUE_CUR)
			base_torque = MAX_TORQUE_CUR; 
        break;	

	default:
		base_torque = 0.001;
        motor_torque = 0; 
        uart1_uchar_transmit(motor_torque_bytes, motor_torque, 'V');
        break;
    }//End switch
		
    if(!(PINE & (1 << PE4))){
        pirate_mode();
    }
}//timer1_ISR

/*********************************************************************
 * ISR: pirate_mode
 *
 *********************************************************************/
ISR(INT0_vect){
    EIMSK &= ~(1<<INT0);
}//ISR

/*********************************************************************
 * ISR: USART Receieve Interrupt ISR
 *
 * Description: 
 *********************************************************************/
/**ISR(USART0_RX_vect){
	
}//ISR
*/
