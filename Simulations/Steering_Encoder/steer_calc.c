/*********************************************************************
 * Author: Shane Licari
 * Date: 12/20/2016
 *
 * Description: This program will use the ADC converter on the
 *  Atmega128 in 10 bit mode using interrupts when the conversion
 *  is done. The 4-20mA signal from the steering encoder corresponds
 *  to 1-5V and 0-360 degrees. 
 *
 *********************************************************************/
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
//#include "../Extern_Files/hd44780.h"

//Function headers
void spi_init();
void spi_16bit_transmit(uint16_t);
void spi_double_transmit(double);
void adc_init();
uint16_t adc_conversion();
double calc_angle(uint16_t, const double, const double);

//Global variables
uint8_t i;
uint16_t    adc_result;
double  angle;
const double SF = 0.04396;
const double deg_offset = 90.118;

//Main Program
int main(){

//Initalize SPI ports
spi_init();
//Initalize ADC ports
adc_init();

while(1){
    adc_result = adc_conversion();
    spi_16bit_transmit(adc_result);
    _delay_ms(100);

    angle = calc_angle(adc_result, SF, deg_offset);
    spi_double_transmit(angle);
    _delay_ms(100);    

    }//While
}//Main


/************************************
 *
 *
 *
 * **********************************/
void spi_init(){
    
    //Set MOSI, SCK as output
    DDRB |= (1<<PB3);
    //Configure SPI (Slave mode, clk low on idle, rising edge sample)
    SPCR = (1<<SPE)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA); 
    SPSR = (1<<SPR1)|(1<<SPR0);
}

/***************************************
 *
 *
 *
 *
 **************************************/
void spi_16bit_transmit(uint16_t result){
    char adc_low = result & 0xFF;
    char adc_high = result >> 8;

    SPDR = adc_high;                    //Load high byte into SPDR buffer
    while(bit_is_clear(SPSR, SPIF)){}   //Wait till SPI data has been sent out
    SPDR = adc_low;                     //Load low byte into SPDR buffer
    while(bit_is_clear(SPSR, SPIF)){}   //Wait till SPI data has been sent out

}

/******************************************
 *
 *
 *
 *
 *****************************************/
void spi_double_transmit(double number){
    unsigned char *chptr;
    chptr = (unsigned char *) &number;
    
    SPDR = (*chptr++);
    while(bit_is_clear(SPSR, SPIF)){}
    SPDR = (*chptr++);
    while(bit_is_clear(SPSR, SPIF)){}
    SPDR = (*chptr++);
    while(bit_is_clear(SPSR, SPIF)){}
    SPDR = (*chptr);
}
/*****************************************
 *
 *
 *
 ****************************************/
void adc_init(){

    //Initalize ADC and the ports
    DDRF &= ~(1<<PF0);  //Port F bit 0 is ADC input
    PORTF &= ~(1<<PF0); //Port F bit 0 pull up has to be off

    ADMUX = (0<<REFS1)|(1<<REFS0)|(1<<MUX0);    //Single ended input, Port F bit 0, right adjusted, 10 bit
    //ADC enabled, One shot mode, ADC complete interrupt enabled, clk prescalar 128 (125khz)
    ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

/***************************************
 *
 *
 *
 **************************************/
uint16_t adc_conversion(){
    ADCSRA |= (1<<ADSC); //Set ADSC and start conversion
    while(bit_is_clear(ADCSRA,ADIF)){}   //loop while interrupt flag not set
    ADCSRA |= (1<<ADIF); //Clear flag by writing a one 
    return ADC;   //Read the ADC output as 16 bits and return
}

/*************************************
 *
 *
 *
 *
 ************************************/
double calc_angle(uint16_t adc_result, const double SF, const double deg_offset){
    double result;
    result = (adc_result*SF)-(deg_offset);
    return result;
}

