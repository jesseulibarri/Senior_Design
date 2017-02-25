
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"


char lcd_screen[16];
float number;

 void spi_init(void){
    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init 

void format_screen() {
    
    dtostrf(number, 10, 5, lcd_screen);
}

int main () {

DDRF |= 0x08;   //lcd strobe bit
spi_init();
lcd_init();
clear_display();
cursor_home();


    while(1) {

number = number + 0.5;

format_screen();
//sprintf(lcd_screen, "%f", number);
string2lcd(lcd_screen);
_delay_ms(500);
clear_display();
cursor_home();


    }//while
    return 0;
}//main
