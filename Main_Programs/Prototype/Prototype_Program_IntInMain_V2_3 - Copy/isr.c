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

//VESC Specific header files (some may not be needed)
#include "bldc_interface.h"
#include "bldc_interface_uart.h"

volatile extern uint8_t Tx_flag = 0;
volatile extern uint8_t eco_accel = 0;
volatile extern float motor_current = 0.0;

/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt turns off the constant button
 * 	acceleration.
 *********************************************************************/
ISR(TIMER1_COMPA_vect){
	disable_timer();	
	eco_accel = 0;
	motor_current = 0.0;

}//timer1_ISR

/*********************************************************************
 * ISR: timer3
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER3_OVF_vect){
	Tx_flag = 1;	
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
