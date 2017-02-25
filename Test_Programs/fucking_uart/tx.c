#include <avr/io.h>
#include <util/delay.h>
#include "uart_functions.h"
#include "hd44780.h"

char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


void spi_init(void){
    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init 

void send_data(uint8_t data) {
    PORTB ^= (1 << PB7);
    while(!(UCSR0A & (1<<UDRE0))) { }
    UDR0 = data;
    clear_display();
    cursor_home();
    char2lcd(data);
}


int main() {

uint8_t i = 0;
DDRB = 0xFF;
DDRF |= 0x08;   //lcd strobe bit
spi_init();
lcd_init();
clear_display();
cursor_home();

uart_init();

    while(1) {
        send_data(i);
        _delay_ms(500);
        i++;
    }//while
}//main
