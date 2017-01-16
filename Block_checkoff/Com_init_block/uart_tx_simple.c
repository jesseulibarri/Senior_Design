
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "uart_functions.h"
#include "hd44780.h"


uint8_t i;
char rx_char;
char lcd_string[16];

void spi_init(void){
  DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
  SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
  SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init    


int main() {

DDRF |= 0x08;   //lcd strobe bit
uart_init();
spi_init();
lcd_init();
clear_display();
cursor_home();

for(i = 0; i < 10; i++) {
    while(!(UCSR0A & (1<<RXC0))) {}
    char2lcd(UDR0);
    //lcd_string[i] = UDR0;
}

//string2lcd(lcd_string);

while(1) { }
}//main


