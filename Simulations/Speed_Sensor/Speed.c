/***************************************************
 * Author: Jesse Ulibarri
 * Date: 12/14/16
 *
 * Description: This is a program that will simulate
 *  the speed sensors on each wheel.
 *
 **************************************************/
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include "../Extern_Files/hd44780.h"

#define PI 3.14159

uint8_t speed = 1.0;
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
uint16_t sixteen_bit_timer_val;
unsigned char rx_buf[4];
//char lcd_string_h[16];
//char lcd_string_l[16];
//div_t double_components;

char lcd_string[32];
char char_numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void format_lcd_array(double number) {
    uint16_t integer_part = (uint16_t)number;
    uint16_t fraction_part = 100000 * (number - integer_part);

    lcd_string[0] = char_numbers[(integer_part / 10) % 10];
    lcd_string[1] = char_numbers[(integer_part % 10)];
    lcd_string[2] = '.';
    lcd_string[3] = char_numbers[(fraction_part / 10000) % 10];
    lcd_string[4] = char_numbers[(fraction_part / 1000) % 10];
    lcd_string[5] = char_numbers[(fraction_part / 100) % 10];
    lcd_string[6] = char_numbers[(fraction_part / 10) % 10];
    lcd_string[7] = char_numbers[(fraction_part / 1) % 10];
                                              
}

/*
void format_lcd_array(double number) {

    double large_num = number * 1000;
    uint16_t convert_to_sixteen = large_num;
    double_components = div(convert_to_sixteen, 1000);
    itoa(double_components.quot, lcd_string_h, 10);
    itoa(double_components.rem, lcd_string_l, 10);

}
*/

void USART1_RX(uint8_t *rx_buf[], uint8_t n) {
    int i = 0;
	for(i,i<n,n++){
		uint8_t data = UDR1;
        rx_buf[i] = data;
		_delay_us(10);
        i++;
	}
}//Usart variable size RX funxtion int8 with delay

uint8_t USART_ReceiveByte(){
  while((UCSRA &(1<<RXC)) == 0);
  return UDR;
}//From the book

ISR(USART1_RX_vect) {
    static uint8_t i = 0;
    char data = UDR1;
    if(data == '\n') {
        i = 0;
    } else {
        rx_buf[i] = data;
        i++;
    }
}//ISR (Char Return)

void timer1_init() {
    // Fast PWM mode, TOP in OCR1A, OC pin disconnected, prescale 64
    TCCR1A |= (1 << WGM10) | (1 << WGM11);
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10) | (1 << CS11);
    // OCR1A will define the period of the pulses
    //OCR1A = 23348;
    OCR1A = sixteen_bit_timer_val;
    // Set interrupt everytime the timer overflows
    TIMSK |= (1 << TOIE1);
}//timer1_init


void SPI_init() {
	// set up SPI (master mode, clk low on idle, leading edge sample)
	SPCR = (1 << SPE) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA);
	SPSR = (1 << SPI2X);
}//SPI_init


ISR(TIMER1_OVF_vect) {

    PORTB |= (1 << PB7);
    _delay_us(10);
    PORTB &= ~(1 << PB7);

}

//******************************************************************
//                            uart1_init
//
//RXD1 is PORT D bit 2
//TXD1 is PORT D bit 3

void uart1_init(){
//rx and tx enable, receive interrupt enabled, 8 bit characters
UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1); //INTERRUPTS ENABLED
//  UCSR1B |= (1<<RXEN1) | (1<<TXEN1);               //INTERRUPS DISABLED

//async operation, no parity,  one stop bit, 8-bit characters
  UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10);
  UBRR1H = (BAUDVALUE_1 >>8 ); //load upper byte of the baud rate into UBRR 
  UBRR1L =  BAUDVALUE_1;       //load lower byte of the baud rate into UBRR 

}

/******************** MAIN *************************/
int main()
{
speed = rx_buf;
double tire_circ = tire_diam * PI;
double distance_per_pulse = tire_circ / sprocket_teeth;
// 1 mph = 17.6 in/sec
double period = distance_per_pulse / (speed * 17.6);
sixteen_bit_timer_val = ((double)period * 16000000) / 64;
float theta = 0.01;

//PORTB.0 set to output
DDRB =0xFF;
DDRC |= (1 << PC0);
timer1_init();
SPI_init();
uart1_init();
lcd_init();
clear_display();
sei();

    while(1){
        format_lcd_array(speed);
        
		period = distance_per_pulse / (speed * 17.6);
        OCR1A = (period * 16000000) / 64;

        float_to_bytes(&speed, speed_bytes);
        send_packet(speed_bytes);
        /*
        //send value to lcd screen
        string2lcd(lcd_string_h);
        char2lcd('.');
        string2lcd(lcd_string_l);

        //wait a moment
        _delay_ms(500);
        clear_display();
        cursor_home();
*/
        refresh_lcd(lcd_string);
        _delay_us(50);
        
    }//while

return 0;
}//main
