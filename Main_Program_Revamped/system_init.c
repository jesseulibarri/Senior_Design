
#include <avr/io.h>
#include <avr/interrupt.h>
#include "math.h"
#include "system_init.h"
#include "uart.h"
#include "steering.h"
#include "datalogging.h"
#include "pirate.h"


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
    //Makes use of the input capture function on PORTD.7.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                //Enable input capture interrupt

    /******** System Timer *********/
    //Initialize 16 bit Timer/Counter 1 for Fast PWM, TOP=24,999
    //  16MHz, pre-scale=64, TOP=24,999, freq=10Hz, period=100mS
    TCCR3A |= (1<<WGM31)|(1<<WGM30);
    TCCR3B |= (1<<WGM33)|(1<<WGM32);
    //Set Prescalar to 64
    TCCR3B |= (1<<CS31)|(1<<CS30);
    //Set Output Comare Match A Value (TOP value)
    OCR3A = 24999; 
    //Interrupt on timer overflow (at TOP value)
    ETIMSK |= (1<<TOIE3);

    /******** Enable Global Interrupts *********/
    sei();

    /******** IO *********/
    DDRA |= (0<<ACCELERATE_B) | (0<<CRUISE_B) | (0<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Accelerate, and pirate switch (input) buttons on PORTD 6, 7, 0. Set PC_ON_OFF (output) PORTD 5.
    DDRB |= (1<<PB7); //input for led indicaiting 12 power converter on off pin is on
    PORTB |= (1<<PB7); // turn on led
    PORTA |= (1<<ACCELERATE_B) | (1<<CRUISE_B) | (1<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Set pullup resistors for input pins and turn on PC_ON_OFF pin

    ///*** Calculate the system needed constants ***/
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    /****** Initialize RPI for Datalogging *******/
    if(datalogging) { 
        
        spi_rpi_init(); 
    }//if datalogging

    /****** spi_steering sensor *******/
   if(spi_steering) { 

       spi_encoder_init();
     }//if spi_steering

    /****** Initialize UART0 *******/
   uart0_init(BAUDVALUE);

    /****** Initialize UART1 *******/
   uart1_init(BAUDVALUE);


}//system_init
