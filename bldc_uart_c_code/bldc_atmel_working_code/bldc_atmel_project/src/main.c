/************************************************************************************************
 * Author:
 * Date:
 *
 * Description: 
 *************************************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <avr/sleep.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "bldc_interface.h"
#include "bldc_interface_uart.h"
#include "buffer.h"
#include "packet.h"
#include "crc.h"
#include "hd44780.h"

#define nop_a5  0x00		
#define rd_pos  0x10
#define speed1_relay 4      	//Port B Pin 4
#define speed2_relay 5      	//Port B Pin 5
#define pc_relay 6          	//Port B pin 6
#define pirate_switch 1     	//Port D Pin 1
#define BAUD 76800           	//UART Baud Rate
#define FOSC 16000000			//Clk frequency
#define MYUBBR FOSC/16/BAUD-1	//UART UBBR calculation to get 9600 baud

//Global Variables
float setcurrent = 0.0;
float torque_right = 0.0;
unsigned char torque_r_bytes[4];
float torque_left = 0.0;
unsigned char torque_l_bytes[4];
uint16_t steering_angle = 0;
unsigned char steering_angle_bytes[4];
float steering_angle_float = 0.0;

/*************************************************************************************************
 * Name: timer1_init
 *
 * Description: This 16 bit timer is used at 10Hz. Every time the timer
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
//void spi_encoder_init(){
//
//    //Set data direction for SPI and set pull up for MISO
//    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
//    PORTB |= (1<<PB3); //MISO line
//    DDRD |= (1<<PD0);
//  
//    //Enable SPI, shift LSB first, mast mode, clk low on idle,
//    //data sampled on rising edge, clk/16 = 1MHz data rate
//    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
//}//spi_encoder_init

/************************************************************************************************
 * Name: spi_init
 *
 * Description: This function is used to initialize the SPI protocol
 *	to use the LCD screen on the OSU atmega128 controller. 
************************************************************************************************/
//void spi_init(void){
//
//    DDRB = DDRB | 0x07;         //Turn on SS, MOSI, SCLK pins
//    SPCR = (1<<SPE)|(1<<MSTR);  //Set up SPI mode
//    SPSR = (1<<SPI2X);          //Run at Double Speed
//}//spi_init

/************************************************************************************************
 * Name: float_to_bytes
 *
 * Description: This function is used to transfer a given float
 * by reference to a 4 byte, 8-bit array for transmission.  
/************************************************************************************************/
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
 * 	encoder uses SPI for communication so we can only read 8 bits at a 
 * 	time which is why we ask for two 8 bit values and concatonate them
 * 	together in a 16 bit integer and then this function returns that
 * 	16 bit int. 
 ************************************************************************************************/
/*uint16_t get_angle(){

    uint8_t high_byte;
    uint8_t low_byte;
    uint16_t angle;

    spi_encoder_init();	//Initialize the SPI protocol for the steering encoder
    //_delay_us(20);
    PORTD &= ~(1<<PD0); //Set Select Line Low
    SPDR = rd_pos;      //Send get position command
    while(bit_is_clear(SPSR, SPIF)){} //Wait for SPI transmission
    PORTD |= (1<<PD0);  //Set Select Line High
    _delay_us(20);	//Wait

    //Wait for Encoder Ready Response
    while(SPDR != rd_pos){    
        PORTD &= ~(1<<PD0);     //Set Select Line Low
        SPDR = nop_a5;          //Send no-op
        while(bit_is_clear(SPSR, SPIF)){}
        PORTD |= (1<<PD0);      //Set Select Line High
        _delay_us(20);          //Wait
    }//while

    //Encoder is ready, read the upper byte (top 4 bits of the 12 total)
    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;          //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to be Received
    PORTD |= (1<<PD0);      //Set Select Line High
    high_byte = SPDR;       //Store Position
    _delay_us(20);          //Wait
    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;           //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to Be received
    PORTD |= (1<<PD0);      //Set Select Line High
    low_byte = SPDR;

    //Concatenates the high and low byte of the steering 
    //angle to a 16 bit integer and return the angle
    angle = (high_byte<<8)|(low_byte);	
    return angle;
}//get_angle
*/
/************************************************************************************************
 * Name: motor_torque
 *
 * Description: This function is has 3 input arguments all which are passed by pointer
 *	reference because these arguments are modified in the function. This function
 *	is used to calculate a torque ration between the rear wheels of the car based
 *	on a steering angle. As well this function includes an acceleration mode which
 * 	is used to ramp up the speed of the care while still checking if the car is 
 *	turning left and right to calculate a difference in torque (electronic differential).
 *	This function also implements a safety feature that doesn't let the torque ramp up
 *	past a set max torque value which can be changed.
 *
 *	TODO: We need to work on the cruise control switch case and implement the speed sensor
 *		calculation. Need to ask Brian if we can cut torque to motors when not accelerating
 *		or if we have to ramp the torque down before going into sleep mode. 
 ************************************************************************************************/
void motor_torque(float* torque_right, float* torque_left, uint16_t* steer_angle){
    
    uint16_t angle = 0;
    float torque_ratio;
    static float general_torque = 0;
    static uint8_t max_torque = 25;
    uint8_t user_mode = PIND | 0x7F;

    general_torque += 0.5;	//This variable is used for the ramping feature
    //angle = get_angle();	//get steering angle reading from encoder
    //angle = 10;
    *steer_angle = angle;	//modify the global steering angle variable
    
    switch(user_mode){

        //No Acceleration, Ramp 
        case 0x00:
            break;
        //Accelerating Mode, Ramp Up
        case 0x7F:
            //Prevent torque from exceeding max torque
            if(general_torque > max_torque){
                general_torque = max_torque;
            }
            //We are turning right
            if(angle >= 0 && angle <= 2048){
                torque_ratio = ((-0.00031)*angle)+(0.99972);	//Calculate torque ratio
                *torque_right = general_torque*torque_ratio;	//Update right motor torque
                *torque_left = general_torque;			//Update left motor torque
            }
            //We are turning left
            else{
                torque_ratio = ((1.033)*log((double)angle))-(7.59);	//Log function takes a double so had to typecast
                *torque_left = general_torque*torque_ratio;		//Update left motor torque
                *torque_right = general_torque;				//Update right motor torque
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
 *
 * 	TODO:Eventually we will need to initialize UART2 when we communicate to
 *		the two different motor controller boards but for the simulation
 *		and block checkoff one uart line is sufficient.  
 ************************************************************************************************/
void uart_init(unsigned char ubrr){
    
    //Set Baud Rate at 9600
    UBRR1H = (unsigned char)(ubrr>>8);
    UBRR1L = (unsigned char)ubrr;

    //Enable Transmitter and Receiver
    UCSR1B = (1<<RXEN)|(1<<TXEN);
    
    //Set Frame Format, 8 bit data, 2 stop bit, Asynchronous
    UCSR1C |= (1<<UCSZ11)|(1<<UCSZ10)|(1<<USBS1);
}//uart_init

/************************************************************************************************
 * Name: send_packet
 *	This function sends 8-bits of data, one element at a time through a given array of length 'len'
 ************************************************************************************************/
static void send_packet(unsigned char *data, unsigned int len){
	
    int i = 0;
	
    //Wait for empty transmit buffer
    while(!(UCSR1A & (1<<UDRE1))) { }

    for(i = 0; i < len;i++) {
        UDR1 = data[i];
    while(!(UCSR1A & (1<<UDRE1))) { }
    _delay_us(100);
    }
}//uart_transmit
//***********************************************************************************************/
// Get values back from the VESC: will change the printf to another way to log/store values.
//***********************************************************************************************/
void bldc_val_received(mc_values *val) {
	printf("Input voltage: %.2f V\r\n", val->v_in);
	printf("Temp:          %.2f degC\r\n", val->temp_pcb);
	printf("Current motor: %.2f A\r\n", val->current_motor);
	printf("Current in:    %.2f A\r\n", val->current_in);
	printf("RPM:           %.1f RPM\r\n", val->rpm);
	printf("Duty cycle:    %.1f %%\r\n", val->duty_now * 100.0);
	printf("Ah Drawn:      %.4f Ah\r\n", val->amp_hours);
	printf("Ah Regen:      %.4f Ah\r\n", val->amp_hours_charged);
	printf("Wh Drawn:      %.4f Wh\r\n", val->watt_hours);
	printf("Wh Regen:      %.4f Wh\r\n", val->watt_hours_charged);
	printf("Tacho:         %i counts\r\n", val->tachometer);
	printf("Tacho ABS:     %i counts\r\n", val->tachometer_abs);
	printf("Fault Code:    %s\r\n", bldc_interface_fault_to_string(val->fault_code));
}
/************************************************************************************************
 * Name: program_init
 *
 * Description: This function is used to initialize the timer and uart and is called
 *	when the controller wakes up out of sleep mode.  
 ***********************************************************************************************/
void program_init(){

    DDRB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4);
    DDRF = 0xFF;
    DDRD |= (1<<PD0);   			//SPI SS pin
    DDRD &= ~(1<<PD7)|(1<<PD6);  	//Configure Port D Pin 7, 6 for input
    PORTD |= (1<<PD7);  			//enable pullup
    timer1_init();      			//initialize 16 bit timer
    uart_init(MYUBBR);				//initialize uart
    sei();
}//program_init

/************************************************************************************************
 * Name: ISR for 16-bit timer
 ************************************************************************************************/
ISR(TIMER1_OVF_vect){
	//Call this function and pass it your UART send_packet function
	bldc_interface_uart_init(send_packet);///////////////////////////////////////////////////////////////////////////////////////THIS
		
	//ISR for the 16 bit timer
    PORTB ^= (1<<PB7);
    PORTF |= (1<<PF0);
    motor_torque(&torque_right, &torque_left, &steering_angle);	//Update motor torques
    steering_angle_float = (float)steering_angle;

    //float_to_bytes(&torque_right, torque_r_bytes);
    //float_to_bytes(&torque_left, torque_l_bytes);
    //float_to_bytes(&steering_angle_float, steering_angle_bytes);

	setcurrent = torque_right;
    bldc_interface_set_current(setcurrent); /////////////////////////////////////////////////////////////////////////////////////THIS

	//bldc_interface_set_current(25);

	//spi_init();					//Used to initalize SPI for LCD screen if being used
    PORTF &= ~(1<<PF0);
}//timer1_isr

/************************************************************************************************
 * Name: Main program, initialize all required ports, timers and UART. Loop infinitely.
 ************************************************************************************************/
int main(){
	
    DDRB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4);
    DDRF = 0xFF;
    //DDRD |= (1<<PD0);   //SPI SS pin
    DDRD &= ~(1<<PD7)|(1<<PD6);  //Configure Port D Pin 7, 6 for input
    PORTD |= (1<<PD7);  //enable pull up
    timer1_init();      //initialize 16 bit timer
    uart_init(MYUBBR);	//initialize uart
    sei();

    while(1){
    }//while
	
return 0;
}//main

