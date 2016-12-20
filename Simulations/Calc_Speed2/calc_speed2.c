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
#define count_period 0.016

void real_clk_init();
void SPI_init();
void timer1_init();

volatile uint16_t i = 0;          //index
uint8_t tire_diam = 22;
uint8_t sprocket_teeth = 42;
double tire_circ;
double distance_per_pulse;
double seconds = 0;
uint16_t timestamp;
double speed;

char lcd_string[32] = {"                                "};
char char_numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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
                                              
}


void calc_speed() {

    PORTC |= (1 << PC0);
    static double timestamp_hist = 0;
    double difference;
    double timestamp_dif;

    if(timestamp < timestamp_hist) {
        difference = 65535 - timestamp_hist;
        timestamp_dif = difference + timestamp;
    } 
    else 
        timestamp_dif = timestamp - timestamp_hist;

    double msec = timestamp_dif * count_period;
    double seconds = msec / 1000;
    speed = (distance_per_pulse / seconds) * (1 / 17.6);
    timestamp_hist = timestamp;
    PORTC &= ~(1 << PC0);

}//calc_speed


ISR(TIMER1_CAPT_vect) {

    PORTC |= (1 << PC1);
    timestamp = (double)ICR1;
    calc_speed();
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

DDRB = 0xFF;

//real_clk_init();        //initialize clock
timer1_init();
SPI_init();
lcd_init();
clear_display();
sei();                  //enable global interrupts

while(1) {
    
    refresh_lcd(lcd_string);
    _delay_us(50);
}

return 0;
}//main


void real_clk_init() {
    
    // Follow procedures in the datasheet to select the external clock.
    TIMSK &= ~((1 << OCIE0) | (1 << TOIE0)); //clear interrupts
    ASSR |= (1 << AS0);                     //enable external clock
    TCCR0 = (1 << WGM01) | (0 << WGM00) | \
            (0 << CS01) | (1 << CS00);      //CTC mode, 8 prescale
    OCR0 = 32;                               //set TOP to measure mS
    while(!((ASSR & 0b0111) == 0)) {}       //spin till registers finish updating
    TIFR |= (1 << OCF0) | (1 << TOV0);      //clear interrupt flags
    TIMSK |= (1 << OCIE0);                  //enable compare match interrupt

}//real_clk_intit


void SPI_init() {
	// set up SPI (master mode, clk low on idle, leading edge sample)
	SPCR = (1 << SPE) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA);
	SPSR = (1 << SPI2X);
}//SPI_init


void timer1_init() {

    //Makes use of the input capture function on PORTD.4.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                 //Enable input capture interrupt

}//timer1_init

