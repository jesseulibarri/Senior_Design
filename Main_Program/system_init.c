
#include <avr/io.h>
#include <avr/interrupt.h>
#include "math.h"
#include "system_init.h"
#include "pirate.h"
#include "const.h"
#include "user_io.h"
//TODO: #include "speed.h"
//TODO: #include "datalogging.h"

#define USART_BAUDRATE 115200  
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

#define USART1_BAUDRATE 115200  
#define BAUDVALUE_1  ((F_CPU/(USART1_BAUDRATE * 16UL)) - 1 )


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

    /******** ICP1 *********/
    //TODO: We are going down to one speed sensor so this init is not needed.
/*    //Makes use of the input capture function on PORTD.4.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                 //Enable input capture interrupt
*/
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

    //Timer will run on the 32kHz oscillator to allow for a slower speed
    //Normal mode, 32,768Hz with 8 pre-scale = 16Hz = 62.5mS
    //TODO: We will not be using the 32kHz timer. It takes to long to start up,
    //  and we will get better accuracy with timer1.
/*    
    // Follow procedures in the datasheet to select the external clock.
    TIMSK &= ~((1 << OCIE0) | (1 << TOIE0)); //clear interrupts
    ASSR |= (1 << AS0);                      //enable external clock
    TCCR0 = (0 << WGM01) | (0 << WGM00) | \
            (0 << CS01) | (1 << CS00);      //Normal mode, 8 prescale
    while(!((ASSR & 0b0111) == 0)) {}       //spin till registers finish updating
    TIFR |= (1 << OCF0) | (1 << TOV0);      //clear interrupt flags
    TIMSK |= (1 << OCIE0);                  //enable compare match interrupt
*/

    /******** Enable Global Interrupts *********/
    sei();

    /******** IO *********/
    DDRA |= (1<<ACCELERATE) | (1<<CRUISE);  //Accelerate and cruise (input) buttons on PORTA.0-1
    DDRB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Output for relay circuits
    DDRD |= (1<<PIRATE_SWITCH);             //Pirate mode enable on PORTD.0 (INT0)
    PORTA |= (1<<ACCELERATE) | (1<<CRUISE); //Set pullup resistors
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
    //Initalize ADC and the ports
    DDRF &= ~(1<<PF1);  //Port F bit 1 is ADC input
    PORTF &= ~(1<<PF1); //Port F bit 1 pull up has to be off

    ADMUX = (0<<REFS1)|(1<<REFS0)|(1<<MUX0);    //Single ended input, Port F bit 0, 
                                                //right adjusted, 10 bit
    //ADC enabled, One shot mode, ADC complete interrupt enabled, clk prescalar 128 (125khz)
    ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

    /****** UART0 *******/
    //UCSR0B |= (1<<RXCIE0)|(1<<TXCIE0)|(1<<RXEN0)|(1<<TXEN0);  //Enable TX, RX, interrupts
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);                      //Enable TX, RX
    UCSR0C |= (0<<UMSEL0)|(0<<USBS0)|(1<<UCSZ00)|(1<<UCSZ01);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size

    /****** UART2 *******/
    //UCSR1B |= (1<<RXCIE1)|(1<<TXCIE1)|(1<<RXEN1)|(1<<TXEN1);  //Enable TX, RX, interrupts
    UCSR1B |= (1 << RXEN1) | (1 << TXEN1);                      //Enable TX, RX
    UCSR1C |= (0<<UMSEL1)|(0<<USBS1)|(1<<UCSZ10)|(1<<UCSZ11);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size
    
    //TODO: Add any timers/interrupts found to be necessary!!!!
    
       PORTC &= ~(1 << PC0);   //end timing test

}//system_init
