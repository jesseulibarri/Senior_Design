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
#define ACCELERATE      0x7F
#define CRUISE          0x3F
#define PIRATE          0xFE
#define MAX_TORQUE_CUR  13
#define TRUE	1
#define FALSE   0

float torque_right = 0.0;
unsigned char torque_r_bytes[4];
float torque_left = 0.0;
unsigned char torque_l_bytes[4];
unsigned char speed_bytes[4];
float cruise_speed = 0.0;
unsigned char steering_angle_bytes[4];
uint16_t steering_angle_int;
float steering_angle = 0.0;
float base_torque = 0.0;
unsigned char base_torque_bytes[4];
uint16_t timestamp_dif = 20000;
float integral = 0.0;
char rx_buff[4];
float speed = 0.0;
char* speed_array = "     ";
unsigned char output_array[4];
uint8_t status;


/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER1_OVF_vect) {
	
	uint8_t user_mode = PIND | 0x3E; //Mask everything out except PORTD 0, 6, and 7
    steering_angle_int = get_angle();
	speed = calc_speed(timestamp_dif, speed);
	//uart1_uchar_transmit(output_array, speed);
	
	//uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);
	
    switch(user_mode){ 
    
    //All button were released
	case NO_INPUT:
		integral = 0;
		//speed = calc_speed(timestamp_dif, speed);
		if(torque_right != 0) {
        	base_torque = 0;
            torque_right = 0;
            torque_left = 0;
        }
        //uart1_uchar_transmit(torque_r_bytes, torque_right);
        uart1_uchar_transmit(torque_l_bytes, torque_left);
        break;
       
    //Accelerate button is pushed
	case ACCELERATE:
		integral = 0;
		//speed = calc_speed(timestamp_dif, speed);
		cruise_speed = speed;
		base_torque = base_torque + 0.5;
		if(base_torque > MAX_TORQUE_CUR)
			base_torque = MAX_TORQUE_CUR; 
            
		//Calculate new values for the motor controllers
        set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);     
        //Transmit torque value over uart
        uart1_uchar_transmit(torque_l_bytes, torque_left);
        break;
	
	//Cruise button is pushed
	case CRUISE:
        //Calculate new values for the motor controllers
       // speed = calc_speed(timestamp_dif, speed);
      // cruise(&torque_right, &torque_left, steering_angle, &base_torque, cruise_speed, speed, &integral);
      // uart1_uchar_transmit(torque_l_bytes, torque_left);
		 	
		if(speed > cruise_speed){
			base_torque = 0;
	   		set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
			uart1_uchar_transmit(torque_l_bytes, torque_left);
		}
		else{
			base_torque = 9;
	   		set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
			uart1_uchar_transmit(torque_l_bytes, torque_left);
		}
        break;

	case PIRATE:
		pirate_mode();
		break;
    }
}//timer1_ISR


/*********************************************************************
 * ISR: pirate_mode
 *
 *********************************************************************/
ISR(INT0_vect){
    //NOT SURE WHAT THIS IS FOUCSR0B &= ~(1<<RXCIE0);R
    EIMSK &= ~(1<<INT0);

}//ISR

/*********************************************************************
 * ISR: speed_sensor_2
 *
 * Description: Same as speed_sensor_1 description. 
 *********************************************************************/

ISR(TIMER3_CAPT_vect) {

    uint16_t timestamp = ICR3;
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
