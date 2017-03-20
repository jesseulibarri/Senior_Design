/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "hd44780.h"

#define TIRE_DIAM 		22
#define SPROCKET_TEETH 	42
#define PI 				3.14159

#define TRUE			1
#define FALSE   		0
#define PACKET_SIZE		4

#define USART_BAUDRATE 	76800  
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

#define USART1_BAUDRATE 76800 
#define BAUDVALUE_1  ((F_CPU/(USART1_BAUDRATE * 16UL)) - 1 )

float period;
float distance_per_pulse;
float tire_circ;
uint16_t sixteen_bit_timer_val;

char lcd_string[16];

char rx_buff[4];
int i = 0;
float speed = 0.1;
float old_speed = 0.1;
uint8_t status;
char* speed_array = "     ";
//unsigned char output_array[4];


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

void timer3_init() {
	/******** System Timer *********/
    //Initialize 16 bit Timer/Counter 3 for Fast PWM, TOP=24,999
    //  16MHz, pre-scale=64, TOP=24,999, freq=10Hz, period=100mS
    TCCR3A |= (1<<WGM31)|(1<<WGM30);
    TCCR3B |= (1<<WGM33)|(1<<WGM32);
    //Set Prescalar to 64
    TCCR3B |= (1<<CS31)|(1<<CS30);
    //Set Output Comare Match A Value (TOP value)
    OCR3A = 24999; 
    //Interrupt on timer overflow (at TOP value)
    ETIMSK |= (1<<TOIE3);
}//timer3_init

void SPI_init() {
	// set up SPI (master mode, clk low on idle, leading edge sample)
	SPCR = (1 << SPE) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA);
	SPSR = (1 << SPI2X);
}//SPI_init

/**************************************************************************************
 * Name: uart0_init
 *
 * Description: RXD0 is PORT E bit 0
 *              TXD0 is PORT E bit 1
 *************************************************************************************/
void uart0_init(){
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    //UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00) | (1<<USBS0);
    UBRR0H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR0L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 
}//uart0_init

/**************************************************************************************
 * Name: uart1_init
 *
 * Description: RXD1 is PORT D bit 2
 *              TXD1 is PORT D bit 3
 *************************************************************************************/
void uart1_init(){
    //rx and tx enable, receive interrupt enabled, 8 bit characters
    UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1); //INTERRUPTS ENABLED
    //UCSR1B |= (1<<RXEN1) | (1<<TXEN1);               //INTERRUPS DISABLED

    //async operation, no parity,  one stop bit, 8-bit characters
    UCSR1C |= (1<<UCSZ11) | (1<<UCSZ10) | (1<<USBS1);
    UBRR1H = (BAUDVALUE_1 >>8 ); //load upper byte of the baud rate into UBRR 
    UBRR1L =  BAUDVALUE_1;       //load lower byte of the baud rate into UBRR 
}//uart1_init
//******************************************************************

/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER3_OVF_vect) {

	if(status){
		speed = atof(speed_array);
		if(speed >= 1.0 && speed < 35) {
		PORTE |= (1<<PE6);
		//update the timer pulse frequency
		period = distance_per_pulse / (speed * 17.6);
        OCR1A = (period * 16000000) / 64;
        PORTE &= ~(1<<PE6);
    	}//if

		UCSR1B |= (1<<RXCIE1);
		status = FALSE;
		old_speed = speed;
	} else { speed = old_speed; }
	
}//Timer_ISR

ISR(USART1_RX_vect){
	//PORTE |= (1<<PE5);
	static uint8_t i = 0;

    char data = UDR1;
    if(data == 'G') {
        i = 0;
		status = TRUE;
		speed_array = rx_buff;
		UCSR1B &= ~(1<<RXCIE1);
	}
	else {
        rx_buff[i] = data;
        i++;
    }
    //PORTE &= ~(1<<PE5);
}//UART_ISR

// ISR(INT0_vect) {
//     if(speed == 40) {
//     } else { 
//         speed += 0.25;
//     }
// }//INT0_ISR


// ISR(INT1_vect) {
//     if(speed == 0.5) {
//     } else { speed -= 0.25; }
// }//INT1_ISR


ISR(TIMER1_OVF_vect) {
	PORTB |= (1 << PB7);
    PORTE |= (1 << PE7);
    _delay_us(10);
    PORTE &= ~(1 << PE7);
    PORTB &= ~(1 << PB7);

}//TIMER1_ISR

int main()  {

	tire_circ = TIRE_DIAM * PI;
	distance_per_pulse = tire_circ / SPROCKET_TEETH;
	// 1 mph = 17.6 in/sec
	period = distance_per_pulse / (speed * 17.6);
	sixteen_bit_timer_val = (period * 16000000) / 64;

	DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB5) | (1<<PB6) | (1<<PB7);
	DDRE |= (1<<PE5) | (1<<PE6) | (1<<PE7);
	DDRF |= 0x08;   //lcd strobe bit
	timer1_init();
	timer3_init();
	SPI_init();
	lcd_init();
	clear_display();
	cursor_home();
	//uart0_init();
	uart1_init();
	sei();

	// //button 0 will increase speed, button 1 will decrease speed
	// DDRD |= (0 << PD0) | (0 << PD1);
 //    PORTD |= (1 << PD0) | (1 << PD1);
 //    EICRA |= (1 << ISC01) | (1 << ISC11);
 //    EIMSK |= (1 << INT0) | (1 << INT1);

	while(1) {
		dtostrf(speed, 4, 1, lcd_string);
		clear_display();
		cursor_home();
		string2lcd(lcd_string);
		_delay_ms(5);
	}//while
	return 0;
}//main


