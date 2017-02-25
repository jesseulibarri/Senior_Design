
#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart_functions.h"
#include "hd44780.h"


float torque;
uint8_t i = 0;
char lcd_string[16];
uint8_t package_flag = 0;
unsigned char buffer[4];

void bytes_to_float(unsigned char* src, float* dest) {
    union {
        float a;
        char bytes[4];
    } u;
    memcpy(u.bytes, src, 4);
    *dest = u.a;
}//bytes_to_float


void spi_init(void){
  DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
  SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
  SPSR  |= (1<<SPI2X);            //run at double speed 
}//spi_init    


ISR(USART0_RX_vect) {
PORTB |= (1<<PB7);
unsigned char data = UDR0;

//if(data == 255) { package_flag = 1; }
//if(package_flag) {
    buffer[i] = data;
    i++;
    if(data == '\n') {
    //if(i == 4) { 
        PORTB |= (1<<PB6);
        //package_flag = 0; 
        i = 0;

        bytes_to_float(buffer, &torque);
        dtostrf(torque, 6, 3, lcd_string);

        clear_display();
        cursor_home();
        string2lcd(lcd_string);
        PORTB &= ~(1<<PB6);
    }//if
//}//if
PORTB &= ~(1<<PB7);
}//ISR_UART_RX

int main() {
DDRB |= 0b11000000;
DDRF |= 0x08;   //lcd strobe bit
uart_init();
UCSR0B |= (1<<RXCIE0);  //enable receive interrupts
spi_init();
lcd_init();
clear_display();
cursor_home();
sei();

    while(1) { }

return 0;
}//main


