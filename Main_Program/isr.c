/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "speed.h"
#include "steering.h"
#include "system_init.h"
#include "pirate.h"
#include "conversions.h"
#include "uart.h"

#define NO_INPUT        0xFF
#define ACCELERATE      0x7F
#define CRUISE          0x3F
#define PIRATE          0xDF
#define MAX_TORQUE_CUR  25


float torque_right = 0.0;
unsigned char torque_r_bytes[4];
float torque_left = 0.0;
unsigned char torque_l_bytes[4];
float speed;
unsigned char speed_bytes[4];
float cruise_speed;
uint16_t steering_angle;
float base_torque;
uint16_t timestamp_history;
float integral = 0;
/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER1_OVF_vect) {

    uint8_t user_mode = PIND | 0x3F; //Mask everything out except PORTD.6 and 7
    steering_angle = 0;// get_angle();

    //Start ADC conversion to get steering angle
    ADCSRA |= (1 << ADSC);                  //Poke ADSC and start conversion
    while(bit_is_clear(ADCSRA, ADIF)) { }   //loop while interrupt flag not set
    ADCSRA |= (1<<ADIF);                    //Clear flag by writing a one 

    
    switch(user_mode) 
    {
        //Accelerate button was let go
        case NO_INPUT:
            integral = 0;
            speed = calc_speed(timestamp_history, speed);
            cruise_speed = speed;
            if(torque_right != 0) {
                base_torque = 0;
                torque_right = 0;
                torque_left = 0;
            }
            break;
        //Accelerate button is pushed
        case ACCELERATE:
            integral = 0;
            base_torque = base_torque + 0.5;
            if(base_torque > MAX_TORQUE_CUR) { base_torque = MAX_TORQUE_CUR; }

            //Calculate new values for the motor controllers
            speed = calc_speed(timestamp_history, speed);
            cruise_speed = speed;
            accelerate(&torque_right, &torque_left, steering_angle, base_torque);
                
            //Convert floats to bytes and send on uart
            float_to_bytes(&torque_right, torque_r_bytes);
            float_to_bytes(&torque_left, torque_l_bytes);
            float_to_bytes(&speed, speed_bytes);
            uart0_uchar(torque_r_bytes);
            //uart0_uchar(torque_l_bytes);
            //uart0_uchar(speed_bytes);

            break;

        //Cruise button is pushed
        case CRUISE:
            base_torque = base_torque + 0.5;
            if(base_torque > MAX_TORQUE_CUR) { base_torque = MAX_TORQUE_CUR; }

            //Calculate new values for the motor controllers
            speed = calc_speed(timestamp_history, speed);
            cruise(&torque_right, &torque_left, steering_angle, base_torque, cruise_speed, speed, &integral);

            //Convert floats to bytes and send on uart
            float_to_bytes(&torque_right, torque_r_bytes);
            float_to_bytes(&torque_left, torque_l_bytes);
            float_to_bytes(&speed, speed_bytes);
            uart0_uchar(torque_r_bytes);
            //uart0_uchar(torque_l_bytes);
            //uart0_uchar(speed_bytes);

            break;

        case PIRATE:

            pirate_mode();

            break;

    }//switch
}//timer1_ISR


/*********************************************************************
 * ISR: pirate_mode
 *
 * Description: The pirate mode switch is connected to external
 *  interrupt 0. If triggered, the pirate mode function will be called.
 *********************************************************************/

ISR(INT0_vect){

    //NOT SURE WHAT THIS IS FOR
    EIMSK &= ~(1<<INT0);

    pirate_mode();
    system_init();

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
    if(timestamp < timestamp_hist) { timestamp_history = 65535 - timestamp_hist + timestamp; }
    else { timestamp_history = timestamp - timestamp_hist; }
           
    timestamp_hist = timestamp;

}

