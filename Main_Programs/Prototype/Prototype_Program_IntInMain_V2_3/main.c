/*******************************************************
 * File Name: main.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description: This is the main loop for the SEM Urban
 * Concept vehicle.
 *****************************************************/

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
#define NO_INPUT		0xFF
#define MAX_CUR  		30
#define TRUE			1
#define FALSE   		0

#define out_min  		0
#define in_max   		184
#define in_min   		36

volatile float motor_current;
volatile uint8_t Tx_flag;

int main(){
	//Initialize the system
	system_init();
	//delay for 1 sec to ensure motor controller is functional
	_delay_ms(1000);
	
	while(1){
		
		if(Tx_flag){
			
			//cli();
			
			// Get analog throttle input
			ADCSRA |= (1<<ADSC);
			while(!bit_is_set(ADCSRA, ADIF)) { }
			ADCSRA |= (1<<ADIF);
			volatile uint16_t thr_in = ADC;

			// Get button input	
			uint8_t user_mode = PINF | 0x9F; //Mask everything out except PORTF
			
			switch(user_mode){ 
			//All button released
			case NO_INPUT:
				if(thr_in >= 36){
					//Calculate and send current proportional to the ADC throttle input
					float motor_current = thr_in*(MAX_CUR)/(in_max-in_min)-(MAX_CUR/(in_max-in_min))*in_min;
					
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

			default:
				motor_current = 0; 
				bldc_interface_set_current(0);
				break;
			}//End switch
				
			if(!(PINE & (1 << PE4))){
				bldc_interface_set_current(0);
				pirate_mode();
			}
			
			Tx_flag = 0;
			//sei();
		}		
		
	}
	
	return 0;
}//main