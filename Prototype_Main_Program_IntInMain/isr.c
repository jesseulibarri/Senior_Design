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

volatile float motor_current = 0.0;

/*********************************************************************
 * ISR: timer1
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
