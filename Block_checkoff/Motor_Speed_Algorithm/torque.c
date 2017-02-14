/************************************************************
 * Author: Shane Licari
 * Date: 2/14/17
 *
 * Description: This program will calculate a motor torque
 *  based off of a steering angle while ramping the torque
 *  at a certain rate.
 *  ********************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>


void timer1_init(){
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    TCCR1A = (1<<WGM11) | (1<<WGM10);
    TCCR1B = (1<<WGM13) | (1<<WGM12);
    
    //Set Prescalar to 64
    TCCR1B = (1<<CS11) | (1<<CS10);

    //Set Output Comare Match A Value
    OCR1A = 2499; 

    //Configure Timer/Counter 1 Output Compare Match A Interrupt
    TIMSK = (1<<OCIE1A);

}

ISR(){


}
