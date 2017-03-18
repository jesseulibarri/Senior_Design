/***************************************************
 * Author: Jesse Ulibarri
 * Date: 12/14/16
 *
 * Description: This is a program that will simulate
 *  the speed sensors on each wheel.
 *
 **************************************************/
//#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hd44780.h"

#define USART_BAUDRATE 76800
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

#define PI 3.14159
#define PACKET_SIZE 4

float speed = 1.0;
unsigned char speed_bytes[4];
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
uint16_t sixteen_bit_timer_val;

double period;
double distance_per_pulse;
double tire_circ;

char lcd_string[32];



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


void uart_init(){
//rx and tx enable, receive interrupt enabled, 8 bit characters
UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
//UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

//async operation, no parity,  one stop bit, 8-bit characters
  UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
  UBRR0H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
  UBRR0L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 

}


void float_to_bytes(float* src, unsigned char* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = *src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes


void bytes_to_float(unsigned char* src, float* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    memcpy(u.bytes, src, 4);
    *dest = u.a;
}

 void send_packet(unsigned char packet[]) {
    //make sure that nothing else is sending
    while(!(UCSR0A & (1<<UDRE0))) { }
    int8_t i;
    for(i = 0; i < PACKET_SIZE; i++) {
        UDR0 = packet[i];
        while(!(UCSR0A & (1<<UDRE0))) { }
        _delay_us(100);
    }
    //send terminator
    UDR0 = '\n';
    while(!(UCSR0A & (1<<UDRE0))) { }
}//send_packet

ISR(USART0_RX_vect) {
    unsigned char data = UDR0;
    static uint8_t i = 0;
    if(data == 'G') {
        i = 0;
        //bytes_to_float(speed_bytes, &speed);
        //dtostrf(speed, 6, 3, lcd_string);
        clear_display();
        cursor_home();
        string2lcd(lcd_string);
        //_delay_ms(40);

        //period = distance_per_pulse / (speed * 17.6);
        //OCR1A = (period * 16000000) / 64;
    } else {
        lcd_string[i] = data;
        i++;
    }
}//ISR

ISR(INT0_vect) {
    if(speed == 40) {
    } else { 
        PORTB |= (1 << PB6);
        speed += 0.25;
        PORTB &= ~(1 << PB6);
    }
}//ISR

ISR(INT1_vect) {
    if(speed == 0.5) {
    } else { speed -= 0.25; }
}//ISR

ISR(TIMER1_OVF_vect) {

    PORTB |= (1 << PB7);
    _delay_us(10);
    PORTB &= ~(1 << PB7);

}//ISR

/******************** MAIN *************************/
int main()
{
tire_circ = tire_diam * PI;
distance_per_pulse = tire_circ / sprocket_teeth;
// 1 mph = 17.6 in/sec
period = distance_per_pulse / (speed * 17.6);
sixteen_bit_timer_val = ((double)period * 16000000) / 64;

//float theta = 0.01;

/*
//PORTD.0 will increase speed, PORTD.1 will deacrease speed
//Interrupts will trigger on falling edge.
DDRD |= (0 << PD0) | (0 << PD1);
PORTD |= (1 << PD0) | (1 << PD1);
EICRA |= (1 << ISC01) | (1 << ISC11);
EIMSK |= (1 << INT0) | (1 << INT1);
*/

//PORTB.0 set to output
DDRB =0xFF;
DDRC |= (1 << PC0);
timer1_init();
uart_init();
SPI_init();
lcd_init();
clear_display();
sei();

    while(1){
/*
        speed = 40*sin(theta);
        period = distance_per_pulse / (speed * 17.6);
        OCR1A = (period * 16000000) / 64;
        theta += 0.01;
        if(theta > PI) { theta = 0.01; }
*/

        //period = distance_per_pulse / (speed * 17.6);
        //OCR1A = (period * 16000000) / 64;

        //float_to_bytes(&speed, speed_bytes);
        //send_packet(speed_bytes);
       /* dtostrf(speed, 6, 3, lcd_string);
        clear_display();
        cursor_home();
        string2lcd(lcd_string);
        _delay_ms(40);
        */
    }//while

return 0;
}//main
