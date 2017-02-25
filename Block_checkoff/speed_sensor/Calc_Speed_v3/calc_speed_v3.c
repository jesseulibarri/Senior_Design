/********************************************************
 * Author: Jesse Ulibarri
 * Date: 12/16/16
 *
 * Description: This simulation will calculate the given
 *  speed based on an input pulse and real-time clock.
 *
 *******************************************************/

//#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include "hd44780.h"

#define USART_BAUDRATE 115200 
#define BAUDVALUE  ((F_CPU/(USART_BAUDRATE * 16UL)) - 1 )

#define USART1_BAUDRATE 115200
#define BAUDVALUE_1  ((F_CPU/(USART1_BAUDRATE * 16UL)) - 1 )


#define PI              3.14159F
#define count_period    0.016F
#define PACKET_SIZE     8

//Function Headers
void spi_init_lcd();
void uart_init();
void uart1_init();
void timer1_init();
float calc_speed(uint16_t* timestamps);
uint16_t calc_avg(uint16_t *array);
void bytes_to_float(unsigned char* src, float* dest);
void float_to_bytes(float* src, unsigned char* dest);
void send_packet(unsigned char* packet);

//Global Variables
uint16_t i = 0;          //index
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
float tire_circ;
float distance_per_pulse;
float speed;
float avg_speed;
unsigned char avg_speed_bytes[4];
unsigned char rx_buf[4];
unsigned char tx_buf[8];

char lcd_string[16];

ISR(USART1_RX_vect) {
    static uint8_t i = 0;
    char data = UDR1;
    if(data == '\n') {
        i = 0;
    } else {
        rx_buf[i] = data;
        i++;
    }
}//ISR


ISR(TIMER1_CAPT_vect) {

    PORTC |= (1 << PC0);
    uint8_t k;
    uint16_t timestamp = ICR1;
    static uint16_t timestamp_hist = 0;
    static uint16_t times1[10] = {1};

    //shift difference history over to make room for new
    for(k = 9; k >= 1; k--) { times1[k] = times1[k - 1]; }

    //wrap around at the end of the timer
    if(timestamp < timestamp_hist) {
        //timestamp_dif = 65535 - timestamp_hist + timestamp;
        times1[0] = 65535 - timestamp_hist + timestamp;
    } 
    else 
        //timestamp_dif = timestamp - timestamp_hist;
        times1[0] = timestamp - timestamp_hist;

    timestamp_hist = timestamp;

    avg_speed = calc_speed(times1);
    float_to_bytes(&avg_speed, avg_speed_bytes);
    for(k = 0; k <= 3; k++) { tx_buf[k] = rx_buf[k]; }
    for(k = 0; k <= 3; k++) { tx_buf[k+4] = avg_speed_bytes[k]; }
    send_packet(tx_buf);
    dtostrf(avg_speed, 6, 3, lcd_string);
    
    PORTC &= ~(1 << PC0);

}//ISR

int main()
{

tire_circ = tire_diam * PI;
distance_per_pulse = tire_circ / sprocket_teeth;

DDRC |= (1 << PC0) | (1 << PC1);;     //for troubleshooting

//initializations
timer1_init();
uart_init();
uart1_init();

/****** Turn on to send to lcd *******/
DDRF |= 0x08;
spi_init_lcd();
lcd_init();
clear_display();

sei();                  //enable global interrupts

while(1) {

    clear_display();
    cursor_home();
    string2lcd(lcd_string);
    _delay_ms(50);

   }//while

return 0;
}//main
    
/*****************************************************************************/
/*****************************************************************************
 * Name: timer1_init
 *  
 * Description: This function intializes the data direction and SPI registers
 *  for SPI transmission in slave mode, with rising edge sample.
 * **************************************************************************/
void timer1_init() {

    //Makes use of the input capture function on PORTD.4.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                 //Enable input capture interrupt

}//timer1_init


//******************************************************************
//                            uart_init
//
//RXD0 is PORT E bit 0
//TXD0 is PORT E bit 1
//Jumpers J14 and J16 (mega128.1) or Jumpers J7 and J9 (mega128.2)
//must be in place for the MAX232 chip to get data.

void uart_init(){
//rx and tx enable, receive interrupt enabled, 8 bit characters
//UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); //INTERRUPTS ENABLED
UCSR0B |= (1<<RXEN0) | (1<<TXEN0);               //INTERRUPS DISABLED

//async operation, no parity,  one stop bit, 8-bit characters
  UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
  UBRR0H = (BAUDVALUE >>8 ); //load upper byte of the baud rate into UBRR 
  UBRR0L =  BAUDVALUE;       //load lower byte of the baud rate into UBRR 

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
//******************************************************************



/*****************************************************************************
 * Name: spi_init_lcd
 *  
 * Description: This function intializes the data direction and SPI registers
 *  for SPI transmission in master mode, with rising edge sample.
 * **************************************************************************/
void spi_init_lcd() {

    DDRB   = DDRB | 0x07;           //Turn on SS, MOSI, SCLK pins
    SPCR  |= (1<<SPE) | (1<<MSTR);  //set up SPI mode
    SPSR  |= (1<<SPI2X);            //run at double speed 
    
}//SPI_init


/**************************************************************************************
 * Name: calc_avg
 *
 * Description: Calculates the average of elements in an array.
 *************************************************************************************/
uint16_t calc_avg(uint16_t *array) {
    uint8_t j;
    uint16_t sum = 0;
    for(j = 0; j < 10; j++) { sum = sum + array[j]; }
    uint16_t avg = sum / 10;
    return avg;
}//calc_avg

/*****************************************************************************/
/*****************************************************************************
 * Name: Exponential Moving Average
 *  
 * Description: This function 
 * **************************************************************************/
//Exponential Moving Average
#define N 16
float ema(float avg, float sample)
{
    float alpha = 2.0/(N+1);
    avg = alpha * sample + (1.0-alpha) * avg;
    return avg;
}

/**************************************************************************************
 * Name: calc_speed
 *
 * Description: Calculates the speed based on the incoming speed sensor pulse.
 *************************************************************************************/
float calc_speed(uint16_t *timestamps) {

    PORTC |= (1 << PC0);

    static uint16_t timestamp_avg_dif;

    timestamp_avg_dif = calc_avg(timestamps);
    float msec = (float)timestamp_avg_dif * count_period;
    float seconds = msec / 1000;
    speed = (distance_per_pulse/ seconds) * (1 / 17.6);
    avg_speed = ema(avg_speed, speed); 

    PORTC &= ~(1 << PC0);

return avg_speed;
}//calc_speed


/**************************************************************************************
 * Name: bytes_to_float
 *
 * Description: 
 *************************************************************************************/
void bytes_to_float(unsigned char* src, float* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    memcpy(u.bytes, src, 4);
    *dest = u.a;
}


/**************************************************************************************
 * Name: float_to_bytes
 *
 * Description: 
 *************************************************************************************/
void float_to_bytes(float* src, unsigned char* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = *src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes


/**************************************************************************************
 * Name: send_packet
 *
 * Description: 
 *************************************************************************************/
 void send_packet(unsigned char packet[]) {
    //make sure that nothing else is sending
    while(!(UCSR0A & (1<<UDRE0))) { }
    int8_t i;
    for(i = 0; i < PACKET_SIZE; i++) {
        UDR0 = packet[i];
        while(!(UCSR0A & (1<<UDRE0))) { }
        _delay_us(100);
    }
}//send_packet
