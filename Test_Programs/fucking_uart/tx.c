#include <avr/io.h>
#include <util/delay.h>
#include "uart_functions.h"
#include "hd44780.h"

char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void spi_encoder_init(){

    //Set data direction for SPI (SS, SCK, MOSI, MISO) and set pullup for MISO
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
    PORTB |= (1<<PB3);
    //DDRF |= (1<<PF0);

    //Enable SPI, shift LSB first, master mode, clk low on idle,
    //data sampled on rising edge, clk/16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
}//spi_encoder_init

void spi_init(void){
    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init 

void send0_data(uint8_t data) {
    PORTB ^= (1 << PB7);
    while(!(UCSR0A & (1<<UDRE0))) { }
    UDR0 = data;
    //clear_display();
    //cursor_home();
    //char2lcd(data);
}


void send1_data(uint8_t data) {
    PORTB ^= (1 << PB7);
    while(!(UCSR1A & (1<<UDRE1))) { }
    UDR1 = data;
    //clear_display();
    //cursor_home();
    //char2lcd(data);
}


int main() {

uint8_t i = 0;
DDRB = 0xFF;
DDRF |= 0x08;   //lcd strobe bit
//spi_init();
//lcd_init();
//clear_display();
//cursor_home();

spi_encoder_init();
uart_init();
uart1_init();


    while(1) {
        send1_data(i);
        send0_data(i);
        _delay_ms(500);
        i++;
    }//while
}//main
