/********************************************************
 * File Name: steering.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "steering.h"

#define nop_a5          0x00
#define rd_pos          0x10
#define set_zero_point  0x70


//NOTES:
// To read position this sequence should be followed:
// 1. Master sends rd_pos command. Encoder responds with idle character.
// 2. Continue sending nop_a5 command while encoder response is 0xA5
// 3. If response was 0x10 (rd_pos), send nop_a5 and receive MSB position (lower 4 bits of this byte are the upper 4 of the 12-bit
//      position)
// 4. Send second nop_a5 command and receive LSB position (lower 8 bits of 12-bit positon)


//To set the zero point this sequence should be followed:
//1. Send set_zero_point command
//2. Send nop_a5 command while response is not 0x80
//3. A response of 0x80 means that the zero set was successful and the new position offset is stored in EEPROM.
//4. The encoder must be power cycled. If the encoder is not power cycled, the position values will not be calculated off the latest
//zero position. When the encoder is powered on next the new offset will be used for the position calculation.

void calibrate_spi_steering() {

    PORTD &= ~(1<<PD0);     //set select line low
    SPDR = set_zero_point;  //send set zero command
    while(bit_is_clear(SPSR, SPIF)) {}
    PORTD |= (1<<PD0);      //set select line high

    //wait for the sensor to respond with 0x80
    while(SPDR != 0x80) {
        PORTD &= ~(1<<PD0);
        SPDR = nop_a5;
        while(bit_is_clear(SPSR, SPIF)) {}
        PORTD |= (1<<PD0);
        _delay_us(20);
    }//while
}//calibrate_spi_steering



/****************************************************************
 * Name: get_angle
 *
 * Description: This function is used to get a 12 bit value from the steering
 *	encoder from 0-4096 which corresponds to 0-360 degrees. The steering
 * 	encoder uses SPI for comminication so we can only read 8 bits at a 
 * 	time which is why we ask for two 8 bit values and cacatonate them
 * 	together in a 16 bit integer and then this function returns that
 * 	16 bit int. 
 ****************************************************************/
uint16_t get_angle(){

    uint8_t high_byte;
    uint8_t low_byte;
    uint16_t angle;

    //spi_encoder_init();	//Initialize the SPI protocol for the steering encoder
    //_delay_us(20);
    PORTD &= ~(1<<PD0); //Set Select Line Low
    SPDR = rd_pos;      //Send get position command
    while(bit_is_clear(SPSR, SPIF)){} //Wait for SPI transmission
    PORTD |= (1<<PD0);  //Set Select Line High
    _delay_us(20);	//Wait

    //Wait for Encoder Ready Response
    while(SPDR != rd_pos){    
        PORTD &= ~(1<<PD0);     //Set Select Line Low
        SPDR = nop_a5;          //Send no-op
        while(bit_is_clear(SPSR, SPIF)){}
        PORTD |= (1<<PD0);      //Set Select Line High
        _delay_us(20);          //Wait
    }//while

    //Encoder is ready, read the upper byte (top 4 bits of the 12 total)
    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;          //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to be Received
    PORTD |= (1<<PD0);      //Set Select Line High
    high_byte = SPDR;       //Store Position
    _delay_us(20);          //Wait
    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;           //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to Be received
    PORTD |= (1<<PD0);      //Set Select Line High
    low_byte = SPDR;

    //spi_init(); //re-enable lcd screen spi config

    //Cancatonate the high and low byte of the steering 
    //angle to a 16 bit integer and return the angle
    angle = (high_byte<<8)|(low_byte);	
    return angle;
}//get_angle


float calc_angle(uint16_t adc_result, const float SF, const float deg_offset) {

    float result;
    result = (adc_result*SF)-(deg_offset);
    return result;


}
