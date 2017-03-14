
#include <avr/io.h>
#include <avr/interrupt.h>
#include "math.h"
#include "system_init.h"
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

    /****** System Timing *******/
    DDRC |= (1 << PC0);                     //for timing requirement 
    PORTC |= (1 << PC0);                    //begin timing

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
    DDRD |= (1<<ACCELERATE_B) | (1<<CRUISE_B);  //Accelerate and cruise (input) buttons on PORTA.0-1
    DDRB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Output for relay circuits
    DDRD |= (1<<PIRATE_SWITCH);             //Pirate mode enable on PORTD.0 (INT0)
    PORTA |= (1<<ACCELERATE_B) | (1<<CRUISE_B); //Set pullup resistors
    PORTB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Turn on relay circuits
    PORTD |= (1<<PIRATE_SWITCH);            //Set high

    ///*** Calculate the system needed constants ***/
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    /****** Datalogging *******/
    if(datalogging) { 
        //Raspberry Pi will be master.
        //Set SS, MOSI, SCK as input, MISO as output
        DDRB |= (0 << PB0) | (0 << PB1) | (0 << PB2) | (1 << PB3);
        //Configure SPI (Slave mode, clk low on idle, rising edge sample)
        SPCR = (1<<SPE)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR1)|(0<<SPR0);
        SPSR = (1<<SPI2X);

    }//if datalogging

    /****** spi_steering sensor *******/
   if(spi_steering) { 

        //Set data direction for SPI and set pullup for MISO
        DDRB = (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
        PORTB |= (1<<PB3);
        DDRD = (1<<PD0);   //ss for encoder

        //SPCR |= 1 << SPIE;    //Enable interrupts
        //SPCR |= 0 << SPIE;    //Disable interrupts
    
        //Enable SPI, shift LSB first, master mode, clk low on idle, 
        //  data sampled on rising edge, clk / 16 = 1MHz datarate
        SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);

    }//if spi_steering

    /******** ADC *********/
/*    //Initalize ADC and the ports
    DDRF &= ~(1<<PF1);  //Port F bit 1 is ADC input
    PORTF &= ~(1<<PF1); //Port F bit 1 pull up has to be off

    ADMUX = (0<<REFS1)|(1<<REFS0)|(1<<MUX0);    //Single ended input, Port F bit 0, 
                                                //right adjusted, 10 bit
    //ADC enabled, One shot mode, ADC complete interrupt enabled, clk prescalar 128 (125khz)
    ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
*/
    /****** UART0 *******/
    //TODO: One of these configurations will need Rx interrupt enabled
    //  so that we can receive information from Matlab
    //
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
//  UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
    UBRR0H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR0L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 

    /****** UART1 *******/
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    //UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1); //INTERRUPTS ENABLED
    UCSR1B |= (1<<RXEN1) | (1<<TXEN1);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10);
    UBRR1H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR1L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 


    //TODO: Add any timers/interrupts found to be necessary!!!!
    
       PORTC &= ~(1 << PC0);   //end timing test

}//system_init
