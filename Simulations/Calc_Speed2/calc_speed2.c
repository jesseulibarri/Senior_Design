/********************************************************
 * Author: Jesse Ulibarri
 * Date: 12/16/16
 *
 * Description: This simulation will calculate the given
 *  speed based on an input pulse and real-time clock.
 *
 *******************************************************/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include "../Extern_Files/hd44780.h"
#define PI 3.14159
#define count_period    0.016

//Function Headers
void real_clk_init();
void spi_init();
void spi_init_master();
void timer1_init();
void format_lcd_array(double);
void calc_speed();
void spi_16bit_transmit(uint16_t);
void spi_double_transmit(double);

//Global Variables
volatile uint16_t i = 0;          //index
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
double tire_circ;
double distance_per_pulse;
double speed;

char lcd_string[32] = {"                                "};
char char_numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


ISR(TIMER1_CAPT_vect) {

    PORTC |= (1 << PC1);
    calc_speed();
    //spi_double_transmit(speed);
    
    if(i > 100) {
        format_lcd_array(speed);
        i = 0;
    }
    i++;
   
    PORTC &= ~(1 << PC1);

}

int main()
{

tire_circ = tire_diam * PI;
distance_per_pulse = tire_circ / sprocket_teeth;

DDRC |= (1 << PC0) | (1 << PC1);;     //for troubleshooting

//initializations
timer1_init();

/****** Turn on for datalogging *******/
//spi_init();

/****** Turn on to send to lcd *******/
spi_init_master();
lcd_init();
clear_display();

sei();                  //enable global interrupts

while(1) {
    
    /****** Turn on to send to lcd *******/
    refresh_lcd(lcd_string);
    _delay_us(50);
}

return 0;
}//main


/*****************************************************************************
 * Name: spi_init_master
 *  
 * Description: This function intializes the data direction and SPI registers
 *  for SPI transmission in master mode, with rising edge sample.
 * **************************************************************************/
void spi_init_master() {
    // set PORT direction. 
    // PB0--SS_N, PB1--SCK, PB2--MOSI, PB3--MISO 
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (0 << PB3);
	// set up SPI (master mode, clk low on idle, leading edge sample)
	SPCR = (1 << SPE) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA);
	SPSR = (1 << SPI2X);
}//SPI_init


/*****************************************************************************
 * Name: spi_init
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


/*****************************************************************************
 * Name: spi_init
 *  
 * Description: This function intializes the data direction and SPI registers
 *  for SPI transmission in slave mode, with rising edge sample.
 * **************************************************************************/
void spi_init(){
    
    //Set MOSI, SCK as output
    DDRB |= (1<<PB3);
    //Configure SPI (Slave mode, clk low on idle, rising edge sample)
    SPCR = (1<<SPE)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA); 
    SPSR = (1<<SPR1)|(1<<SPR0);

}//spi_init


/**************************************************************************************
 * Name: format_lcd_array
 *
 * Description: Takes a double and breaks it up into two parts (16-bit integer part and
 * 16-bit fraction part. The it converts the int values into ASCII values and builds
 * the LCD array to update.
 *************************************************************************************/
void format_lcd_array(double number) {
    uint16_t integer_part = (uint16_t)number;
    uint16_t fraction_part = 10000 * (number - integer_part);

    lcd_string[0] = char_numbers[(integer_part / 10) % 10];
    lcd_string[1] = char_numbers[(integer_part % 10)];
    lcd_string[2] = '.';
    lcd_string[3] = char_numbers[(fraction_part / 1000) % 10];
    lcd_string[4] = char_numbers[(fraction_part / 100) % 10];
    lcd_string[5] = char_numbers[(fraction_part / 10) % 10];
    lcd_string[6] = char_numbers[(fraction_part / 1) % 10];
                                              
}//format_lcd_array


/**************************************************************************************
 * Name: calc_speed
 *
 * Description: Calculates the speed based on the incoming speed sensor pulse.
 *************************************************************************************/
void calc_speed() {

    PORTC |= (1 << PC0);
    uint16_t timestamp = ICR1;
    static uint16_t timestamp_hist = 0;
    uint16_t timestamp_dif;

    if(timestamp < timestamp_hist) {
        timestamp_dif= 65535 - timestamp_hist + timestamp;
    } 
    else 
        timestamp_dif = timestamp - timestamp_hist;

    double msec = (double)timestamp_dif * count_period;
    double seconds = msec / 1000;
    speed = (distance_per_pulse/ seconds) * (1 / 17.6);
    timestamp_hist = timestamp;
    PORTC &= ~(1 << PC0);

}//calc_speed

/**************************************************************************************
 * Name: spi_16bit_transmit
 *
 * Description: This function is passed a 16 bit integer and breaks it into a high and 
 *  low byte to be sent over SPI.
 *************************************************************************************/
void spi_16bit_transmit(uint16_t result){
    char uint16_low = result & 0xFF;
    char uint16_high = result >> 8;

    SPDR = uint16_high;                    //Load high byte into SPDR buffer
    while(bit_is_clear(SPSR, SPIF)){}   //Wait till SPI data has been sent out
    SPDR = uint16_low;                     //Load low byte into SPDR buffer
    while(bit_is_clear(SPSR, SPIF)){}   //Wait till SPI data has been sent out

}//spi_16bit_transmit

/******************************************************************************
 * Name: spi_double_transmit
 *
 * Description: This function is passed a double and breaks it into 4 bytes to
 *  be sent one byte at a time over SPI.
 ******************************************************************************/
void spi_double_transmit(double number){
    uint16_t integer_part = (uint16_t)number;
    uint16_t fraction_part = 1000 * (number - integer_part);

    spi_16bit_transmit(integer_part);
    spi_16bit_transmit(fraction_part);
}//spi_double_transmit
