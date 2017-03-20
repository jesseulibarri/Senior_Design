
/****************************************************
 * File: Steering.c
 * Author: Jesse Ulibarri
 * Description: This program is built for testing the
 *  SPI rotary position sensor we bought for block
 *  checkoff.
****************************************************/


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "hd44780.h"

#define BAUD 115200           	//UART Baud Rate
#define FOSC 16000000		//Clk frequency
#define MYUBBR FOSC/16/BAUD-1	//UART UBBR calulation to get 9600 baud

#define nop_a5          0x00
#define rd_pos          0x10
#define set_zero_point  0x70

void spi_encoder_init() {

    //Set data direction for SPI and set pullup for MISO
    DDRB = (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
    PORTB |= (1<<PB3);
    DDRD = (1<<PD0);   //ss for encoder

    //SPCR |= 1 << SPIE;    //Enable interrupts
    //SPCR |= 0 << SPIE;    //Disable interrupts
    
    //Enable SPI, shift LSB first, master mode, clk low on idle, 
    //  data sampled on rising edge, clk / 16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);

}//spi_encoder_init


void spi_init(void){
    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  = (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  = (1<<SPI2X);            //run at double spee
}//spi_init  

void uart0_init(unsigned char ubrr){
    
    //Set Baud Rate at 9600
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;

    //Enable Transmitter and Reciever
    UCSR0B = (1<<RXEN)|(1<<TXEN);
    
    //Set Frame Format, 8 bit data, 2 stop bit, Asynchronous
    UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00)|(1<<USBS0);
}//uart1_init


/****************************************************************
 * Name: float_to_bytes
 *
 * Description: This function will convert a float to an array
 *  of bytes so that it can be sent over UART.
 ****************************************************************/
void float_to_bytes(float* src, unsigned char* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = *src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes

void uart0_transmit(uint8_t data_array[]){
    int i = 0;
    //Wait for empty transmit buffer
    while(!(UCSR0A & (1<<UDRE0))) { }

    for(i = 0; i < 4;i++) {
        UDR0 = data_array[i];
    while(!(UCSR0A & (1<<UDRE0))) { }
    _delay_us(100);
    }
    //TODO: send terminator if needed
    UDR0 = '\n';
    while(!(UCSR0A & (1<<UDRE0))) { }

}//uart1_transmit



int main() {

//variables
uint8_t high_byte;
uint8_t low_byte;
uint16_t angle;
unsigned char angle_bytes[4];
//char lcd_data[32] = {"                                "};
char lcd_data[16] = {"                "};
char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

DDRA = (1<<PA0)|(1<<PA1);
uart0_init(MYUBBR);

spi_init();
lcd_init();
clear_display();
cursor_home();

//make sure that the sensor is initialized
_delay_ms(200);

spi_encoder_init();

//To set the zero point this sequence should be followed:
//1. Send set_zero_point command
//2. Send nop_a5 command while response is not 0x80
//3. A response of 0x80 means that the zero set was successful and the new position offset is stored in EEPROM.
//4. The encoder must be power cycled. If the encoder is not power cycled, the position values will not be calculated off the latest
//zero position. When the encoder is powered on next the new offset will be used for the position calculation.

/*
PORTD &= ~(1<<PB0);     //set select line low
SPDR = set_zero_point;  //send set zero command
while(bit_is_clear(SPSR, SPIF)) {}
PORTD |= (1<<PB0);      //set select line high

//wait for the sensor to respond with 0x80
while(SPDR != 0x80) {
    PORTA |= (1 << PA0);
    PORTD &= ~(1<<PB0);
    SPDR = nop_a5;
    while(bit_is_clear(SPSR, SPIF)) {}
    PORTD |= (1<<PB0);
    _delay_us(20);
    PORTA &= ~(1 << PA0);
}
*/
//_delay_ms(5000);


while(1) {
    
//NOTES:
// To read position this sequence should be followed:
// 1. Master sends rd_pos command. Encoder responds with idle character.
// 2. Continue sending nop_a5 command while encoder response is 0xA5
// 3. If response was 0x10 (rd_pos), send nop_a5 and receive MSB position (lower 4 bits of this byte are the upper 4 of the 12-bit
//      position)
// 4. Send second nop_a5 command and receive LSB position (lower 8 bits of 12-bit positon)
 
spi_encoder_init();    

-


spi_init();

lcd_data[0] = numbers[angle/1000 % 10];
lcd_data[1] = numbers[angle/100 % 10];
lcd_data[2] = numbers[angle/10 % 10];
lcd_data[3] = numbers[angle % 10];

string2lcd(lcd_data);

_delay_ms(100);

clear_display();

}//while

    return 0;
}//main



