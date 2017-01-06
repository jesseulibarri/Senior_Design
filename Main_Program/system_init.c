
#include <avr/io.h>
#include <avr/interrupt.h>
#include "math.h"
#include "system_init.h"
#include "pirate.h"
#include "const.h"
//TODO: #include "speed.h"
//TODO: #include "datalogging.h"

/*
//Global Variables
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
double tire_circ;
double distance_per_pulse;
double speed;
uint8_t dropped_byte = 0;
*/

/*** Turn ON to enable datalogging ***/
uint8_t datalogging = OFF;


/********************************************************
 * Name: system_init
 *
 * Description: Function takes care of all initializations.
 *  Timers, interrupts, UART, datalogging, ADC, IO
 * ******************************************************/
void system_init() {

    /****** System Timing *******/
    DDRC |= (1 << PC0);                  //for timing requirement 
    PORTC |= (1 << PC0);                 //begin timing

    /******** ICP1 *********/
    //Makes use of the input capture function on PORTD.4.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                 //Enable input capture interrupt

    /******** ICP3 *********/
    //Makes use of the input capture function on PORTE.7.
    TCCR3A = 0x00;                          //Normal mode, no compare
    TCCR3B |= (1 << ICES3) | (1 << CS32);   //Input capture on rising edge,
                                            //256 clk prescale
    ETIMSK |= (1 << TICIE3);                 //Enable input capture interrupt

    /******** Enable Global Interrupts *********/
    sei();

    /******** IO *********/
    DDRB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Output for relay circuits
    DDRD |= (1<<PIRATE_SWITCH);     //Pirate mode enable on PORTD.0 (INT0)
    PORTB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Turn on relay circuits
    PORTD |= (1<<PIRATE_SWITCH);     //Set high

    ///*** Calculate the system needed constants ***/
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    /****** Datalogging *******/
    if(datalogging) { 

        //Set MOSI, SCK as output
        DDRB |= (1<<PB3);
        //Configure SPI (Slave mode, clk low on idle, rising edge sample)
        SPCR = (1<<SPE)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR1)|(0<<SPR0);
        SPSR = (1<<SPI2X);

    }//if datalogging
    
    /******** ADC *********/
    //Initalize ADC and the ports
    DDRF &= ~(1<<PF1);  //Port F bit 1 is ADC input
    PORTF &= ~(1<<PF1); //Port F bit 1 pull up has to be off

    ADMUX = (0<<REFS1)|(1<<REFS0)|(1<<MUX0);    //Single ended input, Port F bit 0, 
                                                //right adjusted, 10 bit
    //ADC enabled, One shot mode, ADC complete interrupt enabled, clk prescalar 128 (125khz)
    ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

    /****** UART0 *******/
    //TODO: UART interrupts
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      //Enable TX, RX
    UCSR0C |= (0<<UMSEL0)|(0<<USBS0)|(1<<UCSZ00)|(1<<UCSZ01);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size

    /****** UART2 *******/
    //TODO: UART interrupts
    UCSR1B |= (1 << RXEN1) | (1 << TXEN1);      //Enable TX, RX
    UCSR1C |= (0<<UMSEL1)|(0<<USBS1)|(1<<UCSZ10)|(1<<UCSZ11);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size
    
    //TODO: Add any timers/interrupts found to be necessary!!!!

    PORTC &= ~(1 << PC0);   //end timing test

}//system_init
