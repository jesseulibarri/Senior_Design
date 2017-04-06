/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "speed.h"
#include "system_init.h"
#include "pirate.h"
#include "conversions.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>

#define NO_INPUT        0xFF
#define ACCELERATE      0x7F
#define PIRATE          0xFE
#define MAX_TORQUE_CUR  20

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

	speed = calc_speed(timestamp_dif, speed);
	uart1_uchar_transmit(speed_bytes, speed, 'V');
	
	//uart1_package_transmit(base_torque_bytes, torque_l_bytes, torque_r_bytes, steering_angle_bytes, torque_right, torque_left, steering_angle, base_torque);
	uint8_t user_mode = PINA | 0x3F; //Mask everything out except PORTD 0, 6, and 7
    switch(user_mode){ 
    
    //All button were released
	case NO_INPUT:

		//speed = calc_speed(timestamp_dif, speed);
        	base_torque = 0.001;
            motor_torque = 0;
            uart1_uchar_transmit(motor_torque_bytes, motor_torque, 'V');
        break;
       
    //Accelerate button is pushed
	case ACCELERATE:
		//speed = calc_speed(timestamp_dif, speed);
		base_torque = base_torque + 0.6;
		if(base_torque > MAX_TORQUE_CUR)
			base_torque = MAX_TORQUE_CUR; 
                 
        //Transmit torque value over uart
        //uart1_uchar_transmit(motor_torque_bytes, motor_torque);
        break;	

	default:
		base_torque = 0.001;
        motor_torque = 0; 
        uart1_uchar_transmit(motor_torque_bytes, motor_torque, 'V');
        break;

        }//switch

        if(!(PIND & (1 << PD0))) {
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
 * ISR: speed_sensor_1
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
	
}//ISR*/
