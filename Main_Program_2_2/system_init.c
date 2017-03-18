
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
uint8_t spi_steering = OFF;


/********************************************************
 * Name: system_init
 *
 * Description: Function takes care of all initializations.
 *  Timers, interrupts, UART, datalogging, ADC, IO
 * ******************************************************/
void system_init() {

    /******** ICP3 *********/
    //Makes use of the input capture function on PORTE.7.
    TCCR3A = 0x00;                          //Normal mode, no compare
    TCCR3B |= (1 << ICES3) | (1 << CS32);   //Input capture on rising edge,
                                            //256 clk prescale
    ETIMSK |= (1 << TICIE3);                //Enable input capture interrupt

    /******** System Timer *********/
    //Initialize 16 bit Timer/Counter 1 for Fast PWM, TOP=24,999
    //  16MHz, pre-scale=64, TOP=24,999, freq=10Hz, period=100mS
    TCCR1A |= (1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM13)|(1<<WGM12);
    //Set Prescalar to 64
    TCCR1B |= (1<<CS11)|(1<<CS10);
    //Set Output Comare Match A Value (TOP value)
    OCR1A = 24999; 
    //Interrupt on timer overflow (at TOP value)
    TIMSK |= (1<<TOIE1);

    /******** Enable Global Interrupts *********/
    sei();

    /******** IO *********/
    DDRD |= (0<<ACCELERATE_B) | (0<<CRUISE_B) | (0<<PIRATE_SWITCH) | (1<<PC_ON_OFF);  //Accelerate, and pirate switch (input) buttons on PORTD 6, 7, 0. Set PC_ON_OFF (output) PORTD 5.
    DDRB |= (1<<PB7); //input for led indicating 12 power converter on off pin is on
    PORTB |= (1<<PB7); // turn on led
    PORTD |= (1<<ACCELERATE_B) | (1<<CRUISE_B) | (1<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Set pullup resistors for input pins and turn on PC_ON_OFF pin

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
