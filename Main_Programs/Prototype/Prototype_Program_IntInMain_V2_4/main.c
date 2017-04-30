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
#define MAX_CUR  		15.0
#define MAX_RPM			10000
#define TRUE			1
#define FALSE   		0

#define OUT_MIN  		0
#define IN_MAX   		184
#define IN_MIN   		36

float target_cur;
volatile float motor_current;
volatile float motor_rpm;
volatile uint8_t Tx_flag;
int main(){
	//Initialize the system
	system_init();
	//delay for 1 sec to ensure motor controller is functional
	_delay_ms(1000);
	
	while(1){
		
		if(Tx_flag){

			// Get button input	
			uint8_t user_mode = PINF | 0x9F; //Mask everything out except PORTF

			// Get analog throttle input
			ADCSRA |= (1<<ADSC);
			while(!bit_is_set(ADCSRA, ADIF)) { }
			ADCSRA |= (1<<ADIF);
			volatile float thr_prev = thr_in;			
			volatile float thr_in = (float)ADC*1.0f;
			thr_in = thr_in*0.75 + thr_prev*0.25;

			switch(user_mode){ 
			//All button released
			case NO_INPUT:
			if(thr_in >= 36){
				//Calculate and send current proportional to the ADC throttle input		
				target_cur = thr_in*(MAX_CUR)/(IN_MAX-IN_MIN)-(MAX_CUR/(IN_MAX-IN_MIN))*IN_MIN;
                if(motor_current < target_cur) {
					motor_current += 0.5;
					} 
                else if(motor_current >= MAX_CUR) { 
					motor_current = MAX_CUR;			
					}
				bldc_interface_set_current(motor_current);
			} 
			else{
				motor_current = 0;
				motor_rpm = 0;	
				bldc_interface_set_current(0);	
			}
			break;
				   
			//Accelerate button is pushed
			case ACCELERATE:
				if(motor_rpm < MAX_RPM) { motor_rpm += 500; } 
                else if(motor_rpm >= MAX_RPM) { motor_rpm = MAX_RPM; }
				bldc_interface_set_rpm(motor_rpm);
			break;	
					
			}//End switch
					
		Tx_flag = 0;
		}//if Tx_flag
	}//while
	
	return 0;
}//main
