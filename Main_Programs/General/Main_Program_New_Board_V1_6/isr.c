/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "speed.h"
#include "steering.h"
#include "system_init.h"
#include "pirate.h"
#include "conversions.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>

#define NO_INPUT        0xFF
#define ACCELERATE      0xBF
#define CRUISE          0x9F

#define PIRATE          0xFE
#define MAX_TORQUE_CUR  20
#define TRUE	1
#define FALSE   0

volatile extern uint8_t index = 0;
volatile extern uint8_t wake_up_timing = 0;
extern uint16_t encoder_angle;
float torque_right = 0.0;
unsigned char torque_r_bytes[4];
float torque_left = 0.0;
unsigned char torque_l_bytes[4];
unsigned char speed_bytes[4];
float cruise_speed = 0.0;
unsigned char steering_angle_bytes[4];
uint16_t steering_angle_int;
float steering_angle = 0.0;
float base_torque;
unsigned char base_torque_bytes[4];
uint16_t timestamp_dif = 20000;
float integral = 0.0;
char rx_buff[4];
volatile extern float speed = 0.0;
char* speed_array = "     ";
unsigned char output_array[4];
uint8_t status;


/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER3_OVF_vect) {

	//steering_angle_int = get_angle(steering_angle_int);
    steering_angle = (float)encoder_angle;
	speed = calc_speed(timestamp_dif, speed);

	//TODO: This is entirely for system checkoff. Remove afterward
	if(wake_up_timing == 1 && index == 20) {
		wake_up_timing = 0;		//We only want to do this once when waking from sleep mode
		uart1_uchar_transmit(speed_bytes, speed, 'V');
	}//if
	index++;


	uint8_t user_mode = PINF | 0x9F;
    switch(user_mode){ 
    
    //All button were released
	case NO_INPUT:
	//	integral = 0;
		//speed = calc_speed(timestamp_dif, speed);
        	base_torque = 0.001;
            torque_right = 0;
            torque_left = 0;
        
		uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);
        break;
       
    //Accelerate button is pushed
	case ACCELERATE:
		//integral = 0;
		cruise_speed = speed;
		base_torque = base_torque + 0.6;
		if(base_torque > MAX_TORQUE_CUR)
			base_torque = MAX_TORQUE_CUR; 
            
		//Calculate new values for the motor controllers
        set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
		uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);
        break;
	
	//Cruise button is pushed
	case CRUISE:
        //Calculate new values for the motor controllers
      // cruise(&torque_right, &torque_left, steering_angle, &base_torque, cruise_speed, speed, &integral);
      // uart1_uchar_transmit(torque_l_bytes, torque_left);
		 	
		if(speed > cruise_speed){
			base_torque = 0;
	   		set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
			uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);
		}
		else{
			base_torque = 9;
	   		set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
			uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);

		}
        break;

	default:
		base_torque = 0.001;
        torque_right = 0;
        torque_left = 0;

		uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);
        break;
    }//switch case
}//timer1_ISR


/*********************************************************************
 * ISR: pirate_mode
 *
 *********************************************************************/
ISR(INT0_vect){ 
	wake_up_timing = 1;		//We only want to do this once when waking from sleep mode
    EIMSK &= ~(1<<INT0);
	wake_up_timing = 1;		//We only want to do this once when waking from sleep mode

}//ISR

/*********************************************************************
 * ISR: speed_sensor_2
 *
 * Description: Same as speed_sensor_1 description. 
 *********************************************************************/

ISR(TIMER1_CAPT_vect) {

    uint16_t timestamp = ICR1;
    static uint16_t timestamp_hist = 0;

    //wrap around at the end of the timer
    if(timestamp < timestamp_hist) { timestamp_dif = 65535 - timestamp_hist + timestamp; }
    else { timestamp_dif = timestamp - timestamp_hist; }
  
    timestamp_hist = timestamp;

}//ISR

/*********************************************************************
 * ISR: USART Receieve Interrupt ISR
 *
 * Description: 
 *********************************************************************/
/*
ISR(USART0_RX_vect){
	static uint8_t i = 0;
	
	DDRB |= (1<<PB6);
	PORTB ^= (1<<PB6);
	
    char data = UDR0;
    if(data == 'G') {
        i = 0;
		status = TRUE;
		speed_array = rx_buff;
		//UCSR0B &= ~(1<<RXCIE0);
	}
	else {
        rx_buff[i] = data;
        i++;
    }
}//ISR*/
