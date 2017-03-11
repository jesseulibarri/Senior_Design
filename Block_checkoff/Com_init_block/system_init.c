
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "math.h"
//#include "uart_functions.h"

//#define F_CPU 16000000
#define ON  1
#define OFF 0
#define TIRE_DIAM       22
#define SPROCKET_TEETH  42
#define SPEED1_RELAY    4
#define SPEED2_RELAY    5
#define PC_RELAY        6
#define PIRATE_SWITCH   7

#define USART_BAUDRATE 115200
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

//Global Variables
double tire_circ;
double distance_per_pulse;

uint16_t timestamps[16];

/*** Turn ON to enable datalogging ***/
uint8_t datalogging = ON;


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
    DDRB |= (1<<PIRATE_SWITCH);     //Pirate mode enable on PORTD.0 (INT0)
    PORTB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Turn on relay circuits
    PORTB |= (1<<PIRATE_SWITCH);     //Set high

    /******** System Timer *********/
    //Timer will run on the 32kHz oscillator to allow for a slower speed
    //Normal mode, 32,768Hz with 8 pre-scale = 16Hz = 62.5mS

    // Follow procedures in the datasheet to select the external clock.
    TIMSK &= ~((1 << OCIE0) | (1 << TOIE0)); //clear interrupts
    ASSR |= (1 << AS0);                      //enable external clock
    TCCR0 = (0 << WGM01) | (0 << WGM00) | \
            (0 << CS01) | (1 << CS00);      //Normal mode, 8 prescale
    while(!((ASSR & 0b0111) == 0)) {}       //spin till registers finish updating

    ///*** Calculate the system needed constants ***/
    uint8_t j;
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    for(j = 0; j < 9; j++) {
        timestamps[j] = 0;
    }

    /****** Datalogging *******/
    if(datalogging) { 
       
        //Set SS, MOSI, SCK as output
        DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) |(0 << PB3);
        //Configure SPI (Slave mode, clk low on idle, rising edge sample)
        SPCR = (1<<SPE)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA);//|(1<<SPR1)|(0<<SPR0);
        SPSR = (1<<SPI2X);

    }//if datalogging
    
    /****** UART0 *******/
    //my_uart_init();
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
//  UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
    UBRR0H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR0L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 

    /****** UART2 *******/
    //my_uart1_init();
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    //UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1); //INTERRUPTS ENABLED
    UCSR1B |= (1<<RXEN1) | (1<<TXEN1);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10);
    UBRR1H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR1L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 

    /****** For Block Checkoff *******/
    
/*    //Send a value via UART
    uint8_t i;
    char characters[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(i = 0; i < 10; i++) {
        //uart_putc(characters[i]);
        while (!(UCSR0A&(1<<UDRE0)));    // Wait for previous transmissions
        UDR0 = characters[i];;    // Send data byte
        while (!(UCSR0A&(1<<UDRE0)));    // Wait for previous transmissions

        _delay_ms(1000);
    }
*/
    //*********** Send SPI Data **********
/*    //Send a value to the bar graph via SPI
    DDRF = (1 << PF6) | (1 << PF5);  //set data direction for bar graph poke

    _delay_ms(500);
    for(i = 1; i < 11; i++) {
        SPDR = i;
        while(bit_is_clear(SPSR, SPIF)) {} // wait until data is sent
        ********** Bar Graph Portion *******************
        PORTF |= (1 << PF6);      // move graph data from shift to storage reg.
        PORTF &= ~(1 << PF6);     // change 3-state back to high Z
        _delay_ms(1000);
    }
*/
    /******************** End Testing **************************/


}//system_init


int main() {

DDRB |= (1 << PB7);

/****** System Timing *******/
DDRA |= (1 << PA0);                  //for timing requirement 
PORTA |= (1 << PA0);                 //begin timing

system_init();

PORTA &= ~(1 << PA0);   //end timing test

while(1) {
PORTB ^= (1 << PB7);
_delay_ms(1000);
}

return 0;
}//main
