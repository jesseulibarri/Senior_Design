/***********************************************
 * Author: Jesse Ulibarri
 * Date: 2/21/17
 *
 * Description: This program is used for block checkoff
 *  for the "uC_to_outside" interface. Program will configure
 *  UART to send at 115.2k Baud, generate a dummy torque
 *  value, package the torque, and then send it to the 
 *  OSU board to be displayed on the LCD screen.
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"
#include "uart_functions.h"

#define PACKAGE_SIZE    4

float torque = 0;
float converted_torque;
unsigned char torque_bytes[4];

char lcd_string[16];


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

void float_to_bytes(float* src, unsigned char* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = *src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes


void send_package(unsigned char package[]) {
    //make sure that nothing else is sending
    while(!(UCSR0A & (1<<UDRE0))) { }
    int8_t i;
        for(i = 0; i < PACKAGE_SIZE; i++) {
        UDR0 = package[i];
        while(!(UCSR0A & (1<<UDRE0))) { }
        _delay_us(100);
    }
    //send terminator
    UDR0 = '\n';
    while(!(UCSR0A & (1<<UDRE0))) { }

}//send_package


void format_lcd_torque(float src_float, char* dest_array){
    dtostrf(src_float, 6, 3, dest_array);
}//format_lcd_torque

int main() {

DDRB = 0xFF;
DDRF |= 0x08;   //lcd strobe bit
spi_init();
lcd_init();
clear_display();
cursor_home();


uart_init();

    while(1) {
        torque = torque + 0.5;
        float_to_bytes(&torque, torque_bytes);
        send_package(torque_bytes);
        bytes_to_float(torque_bytes, &converted_torque);
        format_lcd_torque(converted_torque, lcd_string);
        clear_display();
        cursor_home();
        string2lcd(lcd_string);
        _delay_ms(500);
        

    }//while
}//main
