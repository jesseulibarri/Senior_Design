
#include <avr/io.h>
#include <avr/interrupt.h>
#include "math.h"
#include "system_init.h"
#include "uart.h"
#include "steering.h"
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
    PORTD |= (1<<ACCELERATE_B) | (1<<CRUISE_B) | (1<<PIRATE_SWITCH) | (1<<PC_ON_OFF); //Set pullup resistors for input pins and turn on PC_ON_OFF pin

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

       spi_encoder_init();
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
    /****** Initialize UART0 *******/
   uart0_init(BAUDVALUE);

    /****** Initialize UART1 *******/
   uart1_init(BAUDVALUE);


}//system_init
