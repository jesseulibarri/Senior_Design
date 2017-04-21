/*******************************************************
 * File Name: system_init.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description:
********************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "math.h"
#include "system_init.h"
#include "uart.h"
#include "datalogging.h"
#include "pirate.h"

//VESC Specific header files (some may not be needed)
#include "bldc_interface.h"
#include "bldc_interface_uart.h"
#include "buffer.h"
#include "packet.h"
#include "crc.h"

float tire_circ;
float distance_per_pulse;

/*** Turn ON to enable datalogging ***/
uint8_t datalogging = OFF;
uint8_t spi_steering = ON;


/********************************************************
 * Name: system_init
 *
 * Description: Function takes care of all initializations.
 *  Timers, interrupts, UART, datalogging, ADC, IO
 * ******************************************************/
void system_init() {

    /******** ICP1 *********/
    //Makes use of the input capture function on PORTD.4.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                 //Enable input capture interrupt

    /******** System Timer *********/
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    //  16MHz, pre-scale=64, TOP=24,999, freq=10Hz, period=100mS
    //  16MHz, pre-scale=64, TOP=6,249, freq=40Hz, period=25mS (for system checkoff requirement)
    TCCR3A |= (1<<WGM31)|(1<<WGM30);
    TCCR3B |= (1<<WGM33)|(1<<WGM32);
    //Set Prescalar to 64
    TCCR3B |= (1<<CS31)|(1<<CS30);
    //Set Output Comare Match A Value (TOP value, 10Hz, 100mS)
    OCR3A = 24999;
    //Set Output Comare Match A Value (TOP value, 40Hz, 25mS)
    //OCR3A = 10000; 
    //Interrupt on timer overflow (at TOP value)
    ETIMSK |= (1<<TOIE3);

    /******** Enable Global Interrupts *********/
    //sei();

    /******** IO *********/
    DDRF |= (0<<PF6) | (0<<PF5); //| (0<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Accelerate, and pirate switch (input) buttons on PORTD 6, 7, 0. Set PC_ON_OFF (output) PORTD 5.
    PORTF |= (1<<PF6) | (1<<PF5); //| (1<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Set pullup resistors for input pins and turn on PC_ON_OFF pin
    DDRE |= (0<<PE4); //input for led indicaiting 12 power converter on off pin is on
    PORTE |= (1<<PE4); // turn on led

    DDRA |= (1<<PA1);       //Set timing bit for system checkoff 
    PORTA &= ~(1<<PA1);   

    ///*** Calculate the system needed constants ***/
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    /****** Initialize RPI for Datalogging *******/
    if(datalogging) { 
        spi_rpi_init(); 
    }//if datalogging

    /****** Initialize spi_steering sensor *******/
    if(spi_steering) {
       spi_encoder_init();
     }//if spi_steering

    /****** Initialize RPI for Datalogging *******/
    if(datalogging) { 
        spi_rpi_init(); 
    }//if datalogging

    /****** Initialize UART0 *******/
    uart0_init(BAUDVALUE_1);

    /****** Initialize UART1 *******/
    uart1_init(BAUDVALUE_1);
   
	/****** VESC Interface UART Initialization ******/
	bldc_interface_uart_init(send_packet);   

    /**** Enable Global Interrupts ********/
    sei();

}//system_init
