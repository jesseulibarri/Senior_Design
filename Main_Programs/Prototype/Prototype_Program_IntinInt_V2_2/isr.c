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
#define PIRATE          0xFE
#define NO_INPUT		0xFF
#define MAX_CUR  		30
#define TRUE			1
#define FALSE   		0

#define out_min  		0
#define in_max   		184
#define in_min   		36

/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER3_OVF_vect) {
	
	cli();
	
    // Get analog throttle input
    ADCSRA |= (1<<ADSC);
    while(!bit_is_set(ADCSRA, ADIF)) { }
    ADCSRA |= (1<<ADIF);
    float motor_current = 0;
    volatile uint16_t thr_in = ADC;

    // Get button input	
	uint8_t user_mode = PINF | 0x9F; //Mask everything out except PORTF
	
    switch(user_mode){ 
    //All button released
	case NO_INPUT:
		if(thr_in >= 36){
			//Calculate and send current proportional to the ADC throttle input
			motor_current = thr_in*(MAX_CUR)/(in_max-in_min)-(MAX_CUR/(in_max-in_min))*in_min;
			
			if(motor_current >= MAX_CUR) { motor_current = MAX_CUR; }
				bldc_interface_set_current(motor_current);} 
			else{
				motor_current = 0;
				bldc_interface_set_current(0);	
			}
		break;
       
    //Accelerate button is pushed
	case ACCELERATE:
		motor_current = motor_current + 0.6;
		if(motor_current > MAX_CUR)
			motor_current = MAX_CUR;
		bldc_interface_set_current(motor_current);		
        break;	

    }//End switch
		
    if(!(PINE & (1 << PE4))){
		bldc_interface_set_current(0);
		pirate_mode();
    }
	
	sei();
	
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
