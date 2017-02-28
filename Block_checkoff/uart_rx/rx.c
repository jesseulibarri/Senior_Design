#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "uart_functions.h"
#include "hd44780.h"

uint8_t i = 0;
char lcd_string[16];
unsigned char rx_buf[4];
float number;

void spi_init(void){
    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init 

void bytes_to_float(unsigned char* src, float* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    memcpy(u.bytes, src, 4);
    *dest = u.a;
}

ISR(USART0_RX_vect) {
    static uint8_t i;
    unsigned char data  = UDR0;
    if(data == '\n') {
        i = 0;
        bytes_to_float(rx_buf, &number);
        dtostrf(number, 6, 3, lcd_string);

        clear_display();
        cursor_home();
        string2lcd(lcd_string);

    } else {
        rx_buf[i] = data;
        i++;
    }

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
