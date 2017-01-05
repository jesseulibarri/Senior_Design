/********************************************************
 * File Name: datalogging.c
 *
 * *****************************************************/

#include "datalogging.h"

/******** ON to enable **********/
#define DATALOGGING OFF 

/**************************************************************************************
 * Name: timeout
 *
 * Description: This function is passed a 16 bit integer and breaks it into a high and 
 *  low byte to be sent over SPI.
 *************************************************************************************/
uint8_t timeout() {
    //Normal mode, 64 prescale, 16MHz/(256*64) = 977Hz = 1.024mS
    TCCR0 |= (1 << CS00) | (1 << CS02);
    while(1) {
        if(bit_is_set(SPSR, SPIF)) { 
            TCCR0 &= ~((1 << CS00) | (1 << CS02));
            TCNT0 = 0x00;
            return 0; 
        }
        if(TCNT0 == 255) {
            TCCR0 &= ~((1 << CS00) | (1 << CS02));
            TCNT0 = 0x00;
            dropped_byte++;
            return 1;
        }
    }//while
}//timeout


/**************************************************************************************
 * Name: spi_8bit_tx
 *
 * Description: This function is passed a 16 bit integer and breaks it into a high and 
 *  low byte to be sent over SPI.
 *************************************************************************************/
uint8_t spi_8bit_tx(uint8_t result){

    SPDR = result;                     //Load low byte into SPDR buffer
    if(timeout()) { return 1; }             //Wait till SPI data has been sent out
    //while(bit_is_clear(SPSR, SPIF)) { }
return 0;
}//spi_8bit_tx


/**************************************************************************************
 * Name: spi_16bit_tx
 *
 * Description: This function is passed a 16 bit integer and breaks it into a high and 
 *  low byte to be sent over SPI.
 *************************************************************************************/
uint8_t spi_16bit_tx(uint16_t result){
    char uint16_low = result & 0xFF;
    char uint16_high = result >> 8;

    SPDR = uint16_high;                    //Load high byte into SPDR buffer
    if(timeout()) { return 1; }             //Wait till SPI data has been sent out
    //while(bit_is_clear(SPSR, SPIF)) { }
    SPDR = uint16_low;                     //Load low byte into SPDR buffer
    if(timeout()) { return 1; }             //Wait till SPI data has been sent out
    //while(bit_is_clear(SPSR, SPIF)) { }
return 0;
}//spi_16bit_tx


/******************************************************************************
 * Name: spi_double_tx
 *
 * Description: This function is passed a double and breaks it into 4 bytes to
 *  be sent one byte at a time over SPI.
 ******************************************************************************/
uint8_t spi_double_tx(double number){
    uint16_t integer_part = (uint16_t)number;
    uint16_t fraction_part = 1000 * (number - integer_part);

    SPDR = 0xEE;                        //Send start command
    if(timeout()) { return 1; }           //Wait till SPI data has been sent out
    //while(bit_is_clear(SPSR, SPIF)) { }
    spi_16bit_tx(integer_part);
    spi_16bit_tx(fraction_part);
return 0;
}//spi_double_tx

