#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart_functions.h"
#include "hd44780.h"

char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char lcd_string[3];

void spi_init(void){
    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init 

ISR(USART0_RX_vect) {
    uint8_t value = UDR0;
    clear_display();
    cursor_home();
    lcd_string[0] = numbers[(value / 100) % 10];
    lcd_string[1] = numbers[(value / 10) % 10];
    lcd_string[2] = numbers[(value) % 10];
    string2lcd(lcd_string);
}//ISR


int main() {

DDRF |= 0x08;   //lcd strobe bit
spi_init();
lcd_init();
clear_display();
cursor_home();

uart_init();
UCSR0B |= (1<<RXCIE0);  //enable receive interrupts
sei();

    while(1) { }//while
return 0;
}//main
