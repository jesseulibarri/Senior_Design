
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "uart_functions.h"
#include "hd44780.h"

//NOTE: RXD0 is PORT E bit 0
//      TXD0 is PORT E bit 1

uint8_t i;
uint8_t rx_temp;
char lcd_string[16];

void spi_init(void){
  DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
  SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
  SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init    

ISR(USART0_RX_vect) {
    PORTB = 0x01;
    clear_display();
    cursor_home();
    rx_temp = UDR0;
    uint2lcd(rx_temp / 10 % 10);
    //lcd_string[0] = (char)(rx_temp / 10) % 10;
    //char2lcd(lcd_string[0]);
    uint2lcd(rx_temp % 10);
    _delay_ms(10);
    //lcd_string[1] = (char)rx_temp % 10;
    //char2lcd(lcd_string[1]);
    //string2lcd(lcd_string);
    PORTB = 0x00;
}

int main() {

DDRB = 0xFF;

DDRF |= 0x08;   //lcd strobe bit
uart_init();
spi_init();
lcd_init();
clear_display();
cursor_home();

sei();
/*
for(i = 0; i < 10; i++) {
    while(!(UCSR0A & (1<<RXC0))) {}
    char2lcd(UDR0);
    //lcd_string[i] = UDR0;
}
*/

while(1) {

    //refresh_lcd(lcd_string);

    /*
    uint2lcd(lcd_string[0]);
    uint2lcd(lcd_string[1]);
    _delay_ms(50);
    clear_display();
    cursor_home();
*/

}
}//main


