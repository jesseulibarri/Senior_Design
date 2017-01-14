
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include "math.h"

#define F_CPU 16000000
#define ON  1
#define OFF 0
#define TIRE_DIAM       22
#define SPROCKET_TEETH  42
#define SPEED1_RELAY    4
#define SPEED2_RELAY    5
#define PC_RELAY        6
#define PIRATE_SWITCH   7

//Global Variables
//uint8_t tire_diam = 22;
//uint8_t sprocket_teeth = 42;
double tire_circ;
double distance_per_pulse;
//double speed;

/*** Turn ON to enable datalogging ***/
uint8_t datalogging = ON;

/********************************************************
 * Name: send_speed
 *
 * Description: This is not the completed "send speed"
 *  function. This is needed to verify the block 
 *  according to the testing proceedures in the block 
 *  description report.
 * ******************************************************/
void send_speed() {

    // For block checkoff testing proceedures
    PORTC &= ~(1 << PC0);   //end timing test

    // For block checkoff, send theoretical speed
    //UDR0 = 10;      //send a speed of 10mph
    //while(bit_is_clear(UCSR0A, TXC)) {} //wait for tx to complete

}//send_speed

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

    /******** System Timer *********/
    //Timer will run on the 32kHz oscillator to allow for a slower speed
    //Normal mode, 32,768Hz with 8 pre-scale = 16Hz = 62.5mS

    // Follow procedures in the datasheet to select the external clock.
    TIMSK &= ~((1 << OCIE0) | (1 << TOIE0)); //clear interrupts
    ASSR |= (1 << AS0);                      //enable external clock
    TCCR0 = (0 << WGM01) | (0 << WGM00) | \
            (0 << CS01) | (1 << CS00);      //Normal mode, 8 prescale
    while(!((ASSR & 0b0111) == 0)) {}       //spin till registers finish updating
    TIFR |= (1 << OCF0) | (1 << TOV0);      //clear interrupt flags
    TIMSK |= (1 << OCIE0);                  //enable compare match interrupt


    /******** Enable Global Interrupts *********/
    //sei();

    /******** IO *********/
    DDRB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Output for relay circuits
    DDRB |= (1<<PIRATE_SWITCH);     //Pirate mode enable on PORTD.0 (INT0)
    PORTB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Turn on relay circuits
    PORTB |= (1<<PIRATE_SWITCH);     //Set high

    ///*** Calculate the system needed constants ***/
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    /****** Datalogging *******/
    if(datalogging) { 

        //Set MOSI, SCK as output
        DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
        //Configure SPI (Slave mode, clk low on idle, rising edge sample)
        SPCR = (1<<SPE)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR1)|(0<<SPR0);
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
    UBRR0H = (51 >> 8);     //set baudrate to 38.4k
    UBRR0L = 51;

    /****** UART2 *******/
    //TODO: UART interrupts
    UCSR1B |= (1 << RXEN1) | (1 << TXEN1);      //Enable TX, RX
    UCSR1C |= (0<<UMSEL1)|(0<<USBS1)|(1<<UCSZ10)|(1<<UCSZ11);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size
    UBRR1H = (51 >> 8);      //set baudrate to 38.4k
    UBRR1L = 51;
  
    //TODO: Add any timers/interrupts found to be necessary!!!!
    
    /****** For Block Checkoff *******/
    //Send a value via UART
    //UDR0 = 5;
    //while(bit_is_clear(UCSR0A, TXC)) {} // wait for tx to complete

    //Send a value to the bar graph via SPI
    DDRE = (1 << PE6) | (1 << PE5);  //set data direction for bar graph poke
    //*********** Send SPI Data **********
    SPDR = 6;
    while(bit_is_clear(SPSR, SPIF)) {} // wait until data is sent
    
    //********** Bar Graph Portion *******************
    PORTE |= (1 << PE6);      // move graph data from shift to storage reg.
    PORTE &= ~(1 << PE6);     // change 3-state back to high Z

    //PORTC &= ~(1 << PC0);   //end timing test
    send_speed();

    /******************** End Testing **************************/


}//system_init

int main() {

DDRB |= (1 << PB7);
system_init();

while(1) {
PORTB ^= (1 << PB7);
_delay_ms(1000);
}

return 0;
}//main
