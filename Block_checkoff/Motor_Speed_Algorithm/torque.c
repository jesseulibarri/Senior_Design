/************************************************************
 * Author: Shane Licari
 * Date: 2/14/17
 *
 * Description: This program will calculate a motor torque
 *  based off of a steering angle while ramping the torque
 *  at a certain rate.
 *  ********************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <avr/sleep.h>
#include <math.h>
#include "hd44780.h"

#define nop_a5  0x00
#define rd_pos  0x10
#define speed1_relay 4      //Port C Pin 0
#define speed2_relay 5      //Port C Pin 1
#define pc_relay 6          //Port C pin 2
#define pirate_switch 0     //Port D Pin 0

//Global Torque Variables
float torque_right = 0;
float torque_left = 0;

/****************************************************************
 * Name: timer1_init
 *
 * Description:
 ****************************************************************/
void timer1_init(){
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    TCCR1A = (1<<WGM11)|(1<<WGM10);
    TCCR1B = (1<<WGM13)|(1<<WGM12);
    
    //Set Prescalar to 64
    TCCR1B = (1<<CS11)|(1<<CS10);

    //Set Output Comare Match A Value
    OCR1A = 2499; 

    //Configure Timer/Counter 1 Output Compare Match A Interrupt
    TIMSK = (1<<OCIE1A);

}//timer1_init

ISR(TIMER1_COMPA_vect){
motor_torque(&torque_right, &torque_left);
spi_init();

}//timer1_isr

/****************************************************************
 * Name: spi_encoder_init
 *
 * Description: This function configures the SPI protocol for
 * using the steering sensor.
 ****************************************************************/
void spi_encoder_init(){

    //Set data direction for SPI and set pullup for MISO
    DDRB = (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
    PORTB |= (1<<PB3); //MISO line
    

    //Enable SPI, shift LSB first, mast mode, clk low on idle,
    //data sampled on rising edge, clk/16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
}//spi_encoder_init

/****************************************************************
 * Name: spi_init
 *
 * Description: 
 ****************************************************************/
void spi_init(void){
    DDRB = DDRB | 0x07;         //Turn on SS, MOSI, SCLK pins
    SPCR = (1<<SPE)|(1<<MSTR);  //Set up SPI mode
    SPSR = (1<<SPI2X);          //Run at Double Speed
}//spi_init

/****************************************************************
 * Name: spi_float_to_int
 *
 * Description: 
 ****************************************************************/
uint16_t spi_float_to_int(float number){
    uint16_t result;
    uint16_t integer_part = (uint16_t)number;
    uint16_t fraction_part = 1000 * (number - integer_part);
    
    result = (integer_part<<8)|(fraction_part);
    return result;
}

/****************************************************************
 * Name: get_angle
 *
 * Description: 
 ****************************************************************/
uint16_t get_angle(){

    uint8_t high_byte;
    uint8_t low_byte;
    uint16_t angle;

    spi_encoder_init();

    PORTD &= ~(1<<PD0); //Set Select Line Low
    SPDR = rd_pos;      //Send get position command
    while(bit_is_clear(SPSR, SPIF)){} //Wait for SPI transmission
    PORTD |= (1<<PD0);  //Set Select Line High
    _delay_us(20);

    //Wait for Encoder Ready Response
    while(SPDR != rd_pos){
    
        PORTD &= ~(1<<PD0);     //Set Select Line Low
        SPDR = nop_a5;          //Send no-op
        while(bit_is_clear(SPSR, SPIF)){}
        PORTD |= (1<<PD0);      //Set Select Line High
        _delay_us(20);          //Wait
    }

    //Encoder is ready, read the upper byte (top 4 bits of the 12 total)
    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;          //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to be Received
    PORTD |= (1<<PD0);      //Set Select Line High
    high_byte = SPDR;       //Store Position
    _delay_us(20);          //Wait

    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5           //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to Be received
    PORTD |= (1<<PD0);      //Set Select Line High
    low_byte = SPDR;

    angle = (high_byte<<8)|(low_byte);
    return angle;
}



/****************************************************************
 * Name: motor_torque
 *
 * Description: 
 ****************************************************************/
void motor_torque(float *Torque_right, float *Torque_left){
    
    uint16_t angle;
    float torque_ratio;
    static float general_torque += 0.5;
    static uint8_t max_torque = 25;
    
    angle = get_angle();

    switch(user_mode){

        //No Acceleration, Ramp 
        case 0x00:

        //Accelerating Mode, Ramp Up
        case 0x01:
            //Prevent torque from exceeding max torque
            if(general_torque > max_torque){
                general_torque = max_torque;
            }
            //We are turning right
            if(angle >= 0 && angle <= 2048){
                torque_ratio = ((-0.00031)*angle)+(0.99972);
                torque_right = general_torque*torque_ratio;
                torque_left = general_torque;
            }
            //We are turning left
            else{
                torque_ratio = ((1.033)*log((double)angle))-(7.59);
                torque_left = general_torque*torque_ratio;
                torque_right = general_torque;
            }

        //Cruise Mode
        case 0x03:

}

void pirate_mode(){

    //Configure interrupt 0 so a rising edge will wake up the controller from sleep mode
    EICRA = (1<<ISC01); //Generate aysnchronous interrupt request on rising edge
    EIMSK = (1<<INT0);  //Enable external interrupt 0

    set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Enable power down mode, set sleep enable bit
                                         //in the MCUCR register
    PORTB &= ~((1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay)); //Turn off relay circuits
    cli();  //Clear global interrupt
    sleep_enable(); //Set sleep enable bit in MCUCR register
    sei();          //Set global interrupt bit
    sleep_cpu();    //CPU is sleeping
    sleep_disable   //CPU wakes up on rising edge ISR is executed

    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay); //Turn on relay circuits
}//pirate_mode

ISR(INT0_vect){
    EIMSK &= ~(1<<INT0);
}//ISR


int main(){

    uint16_t TR;
    uint16_t TL;
    char lcd_data1[16] = {"             "};
    char lcd_data2[16] = {"             "};
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    DDRD &= ~(1<<PD0); //Configure Port D Pin 0 for input
    spi_init();
    lcd_init();
    _delay_ms(200);

    while(1){
        TR = spi_float_to_int(torque_right);
        TL = spi_float_to_int(torque_left);
    
        clear_display();
        cursor_home();

        lcd_data1[0] = numbers[TR/1000 % 10];
        lcd_data1[1] = numbers[TR/100 % 10];
        lcd_data1[2] = numbers[TR/10 % 10];
        lcd_data1[3] = numbers[TR % 10];

        lcd_data2[2] = numbers[TL/1000 % 10];
        lcd_data2[3] = numbers[TL/100 % 10];
        lcd_data2[4] = numbers[TL/10 % 10];
        lcd_data2[5] = numbers[TL % 10];
        
        sting2lcd(lcd_data1);
        sting2lcd(lcd_data2);

        _delay_ms(100);
        clear_display();

        if(PIND & (1<<PD0)){
            pirate_mode();
            _delay_ms(10);
        }
    }
    return 0;
}

