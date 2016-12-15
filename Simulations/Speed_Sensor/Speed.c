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

uint8_t speed = 25;
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
uint16_t sixteen_bit_timer_val;
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

void timer1_init() {
    // Fast PWM mode, TOP in OCR1A, OC pin disconnected, prescale 64
    TCCR1A |= (1 << WGM10) | (1 << WGM11);
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10) | (1 << CS11);
    // OCR1A will define the period of the pulses
    //OCR1A = sixteen_bit_timer_val;
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

    PORTB |= (1 << PB0);
    _delay_us(10);
    PORTB &= ~(1 << PB0);

}

/******************** MAIN *************************/
int main()
{

double tire_circ = tire_diam * PI;
double distance_per_pulse = tire_circ / sprocket_teeth;
// 1 mph = 17.6 in/sec
double period = distance_per_pulse / (speed * 17.6);
sixteen_bit_timer_val = ((double)period * 16000000) / 64;

//itoa(tire_circ, lcd_string, 10);
format_lcd_array(distance_per_pulse);
//PORTB.0 set to output
DDRB = 0xFF;
timer1_init();
SPI_init();
lcd_init();
clear_display();
sei();


    while(1){
        refresh_lcd(lcd_string);
        _delay_us(50);
    }

return 0;
}//main
