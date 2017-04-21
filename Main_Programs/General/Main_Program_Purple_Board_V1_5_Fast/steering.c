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

/***********************************************************************************
 * Name: spi_encoder_init
 *
 * Description: This function configures the SPI protocol for 
 * using the steering sensor.
 ***********************************************************************************/
void spi_encoder_init(){

    //Set data direction for SPI (SS, SCK, MOSI, MISO) and set pullup for MISO
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
	PORTB |= (1<<PB3);
    //DDRF |= (1<<PF0);

    //Enable SPI, shift LSB first, master mode, clk low on idle,
    //data sampled on rising edge, clk/16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
}//spi_encoder_init

/***********************************************************************************
 * Name: calibrate_spi_steering
 *
 * Description: This function calibrates the SPI steering sensor.
 ***********************************************************************************/
void calibrate_spi_steering() {

    PORTD &= ~(1<<PD4);     //set select line low
    SPDR = set_zero_point;  //send set zero command
    while(bit_is_clear(SPSR, SPIF)) {}
    PORTD |= (1<<PD4);      //set select line high

    //wait for the sensor to respond with 0x80
    while(SPDR != 0x80) {
        PORTD &= ~(1<<PD4);
        SPDR = nop_a5;
        while(bit_is_clear(SPSR, SPIF)) {}
        PORTD |= (1<<PD4);
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
uint16_t get_angle(uint16_t encoder_angle){
	uint8_t high_byte;
	uint8_t low_byte;
	uint16_t angle;
	
    PORTB &= ~(1<<PB0);     //set select line low
    SPDR = rd_pos;          //send get position command
    while(bit_is_clear(SPSR, SPIF)) {}
    PORTB |= (1<<PB0);      //set select line high
    _delay_us(20);

    uint8_t i = 0;
    //wait for encoder ready response
    while(SPDR != rd_pos) {
     
        PORTB &= ~(1<<PB0);     //ss goes low
        SPDR = nop_a5;          //send noop
        while(bit_is_clear(SPSR, SPIF)) {}
        PORTB |= (1<<PB0);      //ss goes high
        _delay_us(20);          //wait
        if(i == 20) {
            return encoder_angle;
        }//if
    i++;
    }//while

    //encoder is ready, read the upper byte (top 4 bits of the 12 total)
    PORTB &= ~(1<<PB0);     //set select line low
    SPDR = nop_a5;          //send nop command
    while(bit_is_clear(SPSR, SPIF)) {}  //wait for position to be received
    PORTB |= (1<<PB0);
    high_byte = SPDR;       //store posistion
    _delay_us(20);

    PORTB &= ~(1<<PB0);
    SPDR = nop_a5;
    while(bit_is_clear(SPSR, SPIF)) {}  //wait for position to be received
    PORTB |= (1<<PB0);
    low_byte = SPDR;

    //combine low and high bytes into a single variable
    angle = (high_byte << 8) | (low_byte);
    //this part is to run on our microcontroller for block checkoff
    float temp = (float)angle;
    return angle;
}//get_angle

