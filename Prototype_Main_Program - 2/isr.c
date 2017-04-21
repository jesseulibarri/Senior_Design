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

#define ACCELERATE      0xBF
#define CRUISE          0x9F
#define PIRATE          0xFE
#define MAX_TORQUE_CUR  20
#define TRUE	1
#define FALSE   0

volatile float motor_current = 0.0;

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
        motor_current = 0;
        bldc_interface_set_current(0);
        break;
       
    //Accelerate button is pushed
	case ACCELERATE:
		motor_current = motor_current + 0.6;
		if(motor_current > MAX_TORQUE_CUR)
			motor_current = MAX_TORQUE_CUR;
		bldc_interface_set_current(motor_current);		
        break;	

	default:
        motor_current = 0; 
        bldc_interface_set_current(0);
        break;
    }//End switch
		
    if(!(PINE & (1 << PE4))){
		bldc_interface_set_current(0);
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
