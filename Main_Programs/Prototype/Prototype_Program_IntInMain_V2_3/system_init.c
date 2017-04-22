/*******************************************************
 * File Name: system_init.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description: Rrogram takes care of all initializations.
 * Timers, interrupts, UART, datalogging, ADC, IO, etc.
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

/*** Turn ON to enable datalogging ***/
uint8_t datalogging = OFF;

/********************************************************
 * Name: system_init
 *
 * Description: Function takes care of all initializations.
 * Timers, interrupts, UART, datalogging, ADC, IO
 * ******************************************************/
void system_init() {

    /******** System Timer *********/
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    //16MHz, pre-scale=64, TOP=24,999, freq=10Hz, period=100mS
    TCCR3A |= (1<<WGM31)|(1<<WGM30);
    TCCR3B |= (1<<WGM33)|(1<<WGM32);
    //Set Prescalar to 64
    TCCR3B |= (1<<CS31)|(1<<CS30);
    //Set Output Comare Match A Value (TOP value, 10Hz, 100mS)
    OCR3A = 24999;
    //Interrupt on timer overflow (at TOP value)
    ETIMSK |= (1<<TOIE3);

    /******** IO *********/
    DDRF |= (0<<PF6) | (0<<PF5);  //| (0<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Accelerate, and pirate switch (input) buttons on PORTD 6, 7, 0. Set PC_ON_OFF (output) PORTD 5.
    PORTF |= (1<<PF6) | (1<<PF5); //| (1<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Set pullup resistors for input pins and turn on PC_ON_OFF pin
    DDRE |= (0<<PE4);             //input for led indicaiting 12 power converter on off pin is on
    PORTE |= (1<<PE4);            //turn on led  

    /****** Initialize ADC for Throttle input *******/
    // Select PF2 to be input, no pullup
    DDRF &= ~(1<<PF2);
    PORTF &= ~(1<<PF2);
    // Set external 5V to be ref. Select ADC2 for analog throttle
    ADMUX |= (1<<REFS0)|(1<<MUX1);
    // Enable ADC, clock division factor = 128
    ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);	
	
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
