/************************************************************************************************
 * Motor Torque Calculation and Data Logging
 *
 * Author: Shane Licari
 * Contributers: Eli Y. Jesse U.
 * Date: 2/28/2017
 *
 * Description: This program will calculate a motor torque
 *  based off of a steering angle while ramping the torque
 *  at a certain rate. It will then take the calculated 
 *  steering angle and the output motor torque, both 1 and 2, 
 *  type cast and/or convert them into a float, then send 
 *  them via UART at 76800 Baud to the data logger.
 *************************************************************************************************/

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
#define speed1_relay 4      	//Port B Pin 4
#define speed2_relay 5      	//Port B Pin 5
#define pc_relay 6          	//Port B pin 6
#define pirate_switch 1     	//Port D Pin 1
#define BAUD 76800           	//UART Baud Rate
#define FOSC 16000000			//Clk frequency
#define MYUBBR FOSC/16/BAUD-1	//UART UBBR calulation to get 9600 baud

//Global Variables
float torque_right = 0.0;
unsigned char torque_r_bytes[4];
float torque_left = 0.0;
unsigned char torque_l_bytes[4];
uint16_t steering_angle;
unsigned char steering_angle_bytes[4];
float steering_angle_float = 0.0;

/*************************************************************************************************
 * Name: timer1_init
 *
 * Description: This 16 bit timer is used at 10Hz. Everytime the timer
 * 	reaches the top value (OCR1A) the timer over flow flag is set
 *	and a interrupt is triggered 10 times a second. This will be 
 *	used to update motor torque values in the ISR. This function has
 * 	no arguments and does not return anything. 
 ************************************************************************************************/
void timer1_init(){
	
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    TCCR1A |= (1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM13)|(1<<WGM12);
    
    //Set Prescalar to 64 - 10Hz
    TCCR1B |= (1<<CS11)|(1<<CS10);
    //Set Output Comare Match A Value - 10Hz
    OCR1A = 24999; 
	
    //Set Prescalar to 256 - 1Hz
    //TCCR1B |= (1<<CS12);;
    //Set Output Comare Match A Value - 1Hz
    //OCR1A = 62500; 

    //Configure Timer/Counter 1 Output Compare Match A Interrupt
    TIMSK |= (1<<TOIE1);
}//timer1_init

/************************************************************************************************
 * Name: spi_encoder_init
 *
 * Description: This function configures the SPI protocol for
 * using the steering sensor.
 ************************************************************************************************/
void spi_encoder_init(){

    //Set data direction for SPI and set pullup for MISO
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
    PORTB |= (1<<PB3); 			//MISO line
    DDRD |= (1<<PD0);
    DDRA |= (1<<PA0);
  
    //Enable SPI, shift LSB first, mast mode, clk low on idle,
    //data sampled on rising edge, clk/16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
}//spi_encoder_init

/************************************************************************************************
 * Name: spi_init
 *
 * Description: This function is used to initialize the SPI protocol
 *	to use the LCD screen on the OSU atmega128 controller. 
************************************************************************************************/
void spi_init(void){
	
    DDRB = DDRB | 0x07;         //Turn on SS, MOSI, SCLK pins
    SPCR = (1<<SPE)|(1<<MSTR);  //Set up SPI mode
    SPSR = (1<<SPI2X);          //Run at Double Speed
}//spi_init

/************************************************************************************************
 * Name: float_to_bytes
 *
 * Description: This function is used to transfer a given float
 * by reference to a 4 byte, 8-bit array for transmission.  
************************************************************************************************/
void float_to_bytes(float* src, unsigned char* dest) {
	
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = *src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes

/************************************************************************************************
 * Name: get_angle
 *
 * Description: This function is used to get a 12 bit value from the steering
 *	encoder from 0-4096 which corresponds to 0-360 degrees. The steering
 * 	encoder uses SPI for comminication so we can only read 8 bits at a 
 * 	time which is why we ask for two 8 bit values and cacatonate them
 * 	together in a 16 bit integer and then this function returns that
 * 	16 bit int. 
 ************************************************************************************************/
uint16_t get_angle(){

    uint8_t high_byte;
    uint8_t low_byte;
    uint16_t angle;

    spi_encoder_init();					//Initialize the SPI protocol for the steering encoder
    PORTA &= ~(1<<PD0); 				//Set Select Line Low
    SPDR = rd_pos;      				//Send get position command
    while(bit_is_clear(SPSR, SPIF)){} 	//Wait for SPI transmission
    PORTA |= (1<<PD0);  				//Set Select Line High
    _delay_us(20);						//Wait

    //Wait for Encoder Ready Response
    while(SPDR != rd_pos){    
        PORTA &= ~(1<<PD0);     		//Set Select Line Low
        SPDR = nop_a5;          		//Send no-op
        while(bit_is_clear(SPSR, SPIF)){}
        PORTA |= (1<<PD0);      		//Set Select Line High
        _delay_us(20);          		//Wait
    }//while

    //Encoder is ready, read the upper byte (top 4 bits of the 12 total)
    PORTA &= ~(1<<PD0);     			//Set Select Line Low
    SPDR = nop_a5;          			//Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to be Received
    PORTA |= (1<<PD0);      			//Set Select Line High
    high_byte = SPDR;       			//Store Position
    _delay_us(20);          			//Wait
    PORTA &= ~(1<<PD0);     			//Set Select Line Low
    SPDR = nop_a5;           			//Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to Be received
    PORTA |= (1<<PD0);      			//Set Select Line High
    low_byte = SPDR;

    //Cancatonate the high and low byte of the steering 
    //angle to a 16-bit integer and return the angle
    angle = (high_byte<<8)|(low_byte);	
    return angle;
}//get_angle

/************************************************************************************************
 * Name: motor_torque
 *
 *  Description: This funcion is has 3 input arguments all which are passed by pointer
 *	reference because these arguments are modified in the function. This function
 *	is used to calculate a torque ration between the rear wheels of the car based
 *	on a steering angle. This function inlcudes an acceleration mode,
 * 	used to ramp up the output torque, while still checking if the car is 
 *	turning left and right to calculate a difference in torque (electronic differential).
 *	This function also implements a safety feature that doesnt let the torque ramp up
 *	past a set max torque value which can be changed.
 ************************************************************************************************/
void motor_torque(float* torque_right, float* torque_left, uint16_t* steer_angle){
    
    uint16_t angle;
    float torque_ratio;
    static float general_torque = 0;
    static uint8_t max_torque = 25;
    uint8_t user_mode = PIND | 0xFE;

    general_torque += 0.5;				//This variable is used for the ramping feature
    angle = 0;
    //angle = get_angle();				//get steering angle reading from encoder
    *steer_angle = angle;				//modify the global steering angle variable
    
    switch(user_mode){

        //No Acceleration, Ramp 
        case 0x00:
            break;
        //Accelerating Mode, Ramp Up
        case 0xFE:
            //Prevent torque from exceeding max torque
            if(general_torque > max_torque){
                general_torque = max_torque;
            }
            //We are turning right
            if(angle >= 0 && angle <= 2048){
                torque_ratio = ((-0.00031)*angle)+(0.99972);		//Calculate torque ratio
                *torque_right = general_torque*torque_ratio;		//Update right motor torque
                *torque_left = general_torque;						//Update left motor torque
            }
            //We are turning left
            else{
                torque_ratio = ((1.033)*log((double)angle))-(7.59);	//Log function takes a double so had to typecast
                *torque_left = general_torque*torque_ratio;			//Update left motor torque
                *torque_right = general_torque;						//Update right motor torque
            }
            break;
        //Cruise Mode
        case 0x03:
            break;
	//If we are not accelerating or cruising set torque to 0
        default:
            if(general_torque != 0) {
                general_torque = 0;
                *torque_left = 0;
                *torque_right = 0;
            }
            else {}
            break;
    }//switch
}//motor_torque

/************************************************************************************************
 * Name: uart_init
 *
 * Description: This function is used to initialize UART1 on the atmega128 so
 *	we can send torque values and steering angle to the simulation on matlab.
 ************************************************************************************************/
void uart_init(unsigned char ubrr){
    
    //Set Baud Rate at 76800
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;

    //Enable Transmitter and Reciever
    UCSR0B = (1<<RXEN)|(1<<TXEN);
    
    //Set Frame Format, 8 bit data, 2 stop bit, Asynchronous
    UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00)|(1<<USBS0);
}//uart_init

/************************************************************************************************
 * Name: uart_transmit
 *
 * Description: This function has a 8 bit data array as an input argument. This array
 * 	will be formatted as a 10 byte frame that contains two torque values and a
 *	steering angle that will be sent over uart 10 times a second. Each torque
 *	value will be 4 bytes, sent as a float in 4 8-bit pieces. The steering angle 
 *  will be converted to a 4 byte float, which leaves a total of 12 bytes to be
 *	transmitted. Uart can only transmit 8 bits at a time thats why we use an array
 * 	to frame the data into 8 bit segments and sent back-to-back as floats. 
 ************************************************************************************************/
void uart_transmit(uint8_t data_array[], int n){
	
    int i = 0;
    //Wait for empty transmit buffer
    while(!(UCSR0A & (1<<UDRE0))) { }

    for(i = 0; i < n;i++) {
        UDR0 = data_array[i];
    while(!(UCSR0A & (1<<UDRE0))) { }
    _delay_us(100);
    }
}//uart_transmit


/************************************************************************************************
 * Name: ISR for 16-bit timer, sends 4 floats of data to be logged
 ************************************************************************************************/
ISR(TIMER1_OVF_vect){
	
	//ISR for the 16 bit timer
    PORTB ^= (1<<PB7);
    PORTF |= (1<<PF0);
    motor_torque(&torque_right, &torque_left, &steering_angle);	//Update motor torques
    steering_angle_float = (float)steering_angle;

    float_to_bytes(&torque_right, torque_r_bytes);
    float_to_bytes(&torque_left, torque_l_bytes);
    float_to_bytes(&steering_angle_float, steering_angle_bytes);

    uart_transmit(torque_r_bytes,4);			//transmit right torque value - float, 4 bytes
   // uart_transmit(torque_l_bytes,4);    		//transmit left torque value - float, 4 bytes
   // uart_transmit(steering_angle_bytes,4);		//transmit steering encoder value - uint16, 2 bytes

    //spi_init();									//Used to initalize SPI for LCD screen if being used
    PORTF &= ~(1<<PF0);
}//timer1_isr

/************************************************************************************************
 * Name: Main program, initalize all required ports, timers and UART. Loop infinitely.
 ************************************************************************************************/
int main(){
	
    DDRB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4);
    DDRF = 0xFF;
    DDRD &= ~((1<<PD7)|(1<<PD6)|(1<<PD0));  			//Configure Port D Pin 7, 6 for input
    DDRD |= (0<<PD0);
    PORTD |= (1<<PD7)|(1<<PD0);  					//enable pullup
    timer1_init();      					//initialize 16 bit timer
    uart_init(MYUBBR);						//initialize uart
    spi_encoder_init();
    sei();

    while(1){
    }//while
	
return 0;
}//main
