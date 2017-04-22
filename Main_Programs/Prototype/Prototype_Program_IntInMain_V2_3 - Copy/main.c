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
#include "buffer.h"
#include "packet.h"
#include "crc.h"

#define ACCELERATE      0xBF
#define CRUISE          0x9F
#define PIRATE          0xFE
#define NO_INPUT		0xFF
#define MAX_CUR  		30.0
#define TRUE			1
#define FALSE   		0

#define OUT_MIN  		0
#define IN_MAX   		184
#define IN_MIN   		36

float motor_current = 0.0;
volatile uint8_t Tx_flag;
uint8_t eco_accel;
int WaitCount = 0;
int main(){
	//Initialize the system
	system_init();
	//delay for 1 sec to ensure motor controller is functional
	_delay_ms(1000);
	
	while(1){
		
		if(Tx_flag){

			// Get button input	
			uint8_t user_mode = PINF | 0x9F; //Mask everything out except PORTF

			if(eco_accel && user_mode == ACCELERATE) {
				
					if(motor_current >= MAX_CUR) {
						bldc_interface_set_current(MAX_CUR);
						
					}
					else {
						motor_current = motor_current + 0.6;
						bldc_interface_set_current(motor_current);
						if(motor_current >= MAX_CUR) {
							TCCR1B |= (1<<CS12)|(1<<CS10);      // start with clock off
						}
					}
			}// if eco_accel
			
			else {
				// Get analog throttle input
				ADCSRA |= (1<<ADSC);
				while(!bit_is_set(ADCSRA, ADIF)) { }
				ADCSRA |= (1<<ADIF);
				volatile uint16_t thr_in = ADC;
				
				switch(user_mode){ 
				//All button released
				case NO_INPUT:

					eco_accel = 0;

					if(thr_in >= 36){
						//Calculate and send current proportional to the ADC throttle input
						motor_current = thr_in*(MAX_CUR)/(IN_MAX-IN_MIN)-(MAX_CUR/(IN_MAX-IN_MIN))*IN_MIN;
						if(motor_current >= MAX_CUR)
							motor_current = MAX_CUR;
						bldc_interface_set_current(motor_current);
					} 
					else{
						motor_current = 0;
						bldc_interface_set_current(0);	
					}
					break;
				   
				//Accelerate button is pushed
				case ACCELERATE:

					if(!bit_is_set(TCCR1B,CS12)) {
						eco_accel = 1;
					}

					// motor_current = motor_current + 0.6;
					// if(motor_current > MAX_CUR)
					// 	motor_current = MAX_CUR;
					// bldc_interface_set_current(motor_current);		
					break;	
					
				}//End switch
					
				if(!(PINE & (1 << PE4))){
					bldc_interface_set_current(0);
					pirate_mode();
				}
				
				
				//sei();

			}//else eco_accel
			Tx_flag = 0;
		}//if Tx_flag
	}//while
	
	return 0;
}//main
