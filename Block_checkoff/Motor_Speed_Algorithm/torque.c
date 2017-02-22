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
#define speed1_relay 4      	//Port B Pin 4
#define speed2_relay 5      	//Port B Pin 5
#define pc_relay 6          	//Port B pin 6
#define pirate_switch 1     	//Port D Pin 1
#define BAUD 38400           	//UART Baud Rate
#define FOSC 16000000		//Clk frequency
#define MYUBBR FOSC/16/BAUD-1	//UART UBBR calulation to get 9600 baud

//Structure that holds a 16 bit integer and 16 bit fraction
//once the floats are converted to ints
struct int_frac{
    uint16_t integer;
    uint16_t fraction;
};

//Global Variables
float torque_right = 0.0;
float torque_left = 0.0;
uint16_t steering_angle;

struct int_frac TR;
struct int_frac TL;
uint8_t data_array[10];	//data array used to send a 10 byte frame over UART

/***************************************************************************
 * Name: timer1_init
 *
 * Description: This 16 bit timer is used at 10Hz. Everytime the timer
 * 	reaches the top value (OCR1A) the timer over flow flag is set
 *	and a interrupt is triggered 10 times a second. This will be 
 *	used to update motor torque values in the ISR. This function has
 * 	no arguments and does not return anything. 
 ***************************************************************************/
void timer1_init(){
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    TCCR1A |= (1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM13)|(1<<WGM12);
    
    //Set Prescalar to 64
    TCCR1B |= (1<<CS11)|(1<<CS10);

    //Set Output Comare Match A Value
    OCR1A = 24999; 

    //Configure Timer/Counter 1 Output Compare Match A Interrupt
    TIMSK |= (1<<TOIE1);
}//timer1_init

/****************************************************************
 * Name: spi_encoder_init
 *
 * Description: This function configures the SPI protocol for
 * using the steering sensor.
 ****************************************************************/
void spi_encoder_init(){

    //Set data direction for SPI and set pullup for MISO
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
    PORTB |= (1<<PB3); //MISO line
    DDRD |= (1<<PD0);
  
    //Enable SPI, shift LSB first, mast mode, clk low on idle,
    //data sampled on rising edge, clk/16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
}//spi_encoder_init

/****************************************************************
 * Name: spi_init
 *
 * Description: This function is used to initialize the SPI protocol
 *	to use the LCD screen on the OSU atmega128 controller. 
 ****************************************************************/
void spi_init(void){
    DDRB = DDRB | 0x07;         //Turn on SS, MOSI, SCLK pins
    SPCR = (1<<SPE)|(1<<MSTR);  //Set up SPI mode
    SPSR = (1<<SPI2X);          //Run at Double Speed
}//spi_init

/****************************************************************************
 * Name: spi_float_to_int
 *
 * Description: This function takes two input arguments one is a
 * 	32 bit float number and the other is a structure that is passed by
 *	reference. This function will tke a 32 bit float and break it up 
 * 	into a 16 bit integer part and 16 bit fraction part. Here we use 
 *	The instance of the global structure to convert this float and 
 *	store each part into the appropriate member variable.
 *****************************************************************************/
void spi_float_to_int(struct int_frac *value, float number){
    value->integer = (uint16_t)number;
    value->fraction = 10000 * (number - value->integer);
}//spi_float_to_int

/****************************************************************
 * Name: get_angle
 *
 * Description: This function is used to get a 12 bit value from the steering
 *	encoder from 0-4096 which corresponds to 0-360 degrees. The steering
 * 	encoder uses SPI for comminication so we can only read 8 bits at a 
 * 	time which is why we ask for two 8 bit values and cacatonate them
 * 	together in a 16 bit integer and then this function returns that
 * 	16 bit int. 
 ****************************************************************/
uint16_t get_angle(){

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

    //spi_init(); //re-enable lcd screen spi config

    //Cancatonate the high and low byte of the steering 
    //angle to a 16 bit integer and return the angle
    angle = (high_byte<<8)|(low_byte);	
    return angle;
}//get_angle

/**************************************************************************************************
 * Name: motor_torque
 *
 * Description: This funcion is has 3 input arguments all which are passed by pointer
 *	reference beccause these arguments are modified in the function. This function
 *	is used to calculate a torque ration between the rear wheels of the car based
 *	on a steering angle. As well this function inlcudes an acceleration mode which
 * 	is used to ramp up the speed of the care while still checking if the car is 
 *	turning left and right to calculate a difference in torque (electronic differential).
 *	This function also implements a safety feature that doesnt let the torque ramp up
 *	past a set max torque value which can be changed.
 *
 *	TODO: We need to work on the cruise control switch case and implement the speed sensor
 *		calculation. Need to ask Brian if we can cut torque to motors when not accelerating
 *		or if we have to ramp the torque down before going into sleep mode. 
 ***************************************************************************************************/
void motor_torque(float* torque_right, float* torque_left, uint16_t* steer_angle){
    
    uint16_t angle;
    float torque_ratio;
    static float general_torque = 0;
    static uint8_t max_torque = 25;
    uint8_t user_mode = PIND | 0x7F;

    general_torque += 0.5;	//This variable is used for the ramping feature
    angle = get_angle();	//get steering angle reading from encoder
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

/***********************************************************************************
 * Name: uart_init
 *
 * Description: This function is used to initialize UART1 on the atmega128 so
 *	we can send torque values and steering angle to the simulation on matlab.
 *
 * 	TODO:Eventually we will need to initialize UART2 when we communicate to
 *		the two differn't motor controller boards but for the simulation
 *		and block checkoff one uart line is sufficient.  
 ***********************************************************************************/
void uart_init(unsigned char ubrr){
    
    //Set Baud Rate at 9600
    UBRR1H = (unsigned char)(ubrr>>8);
    UBRR1L = (unsigned char)ubrr;

    //Enable Transmitter and Reciever
    UCSR1B = (1<<RXEN)|(1<<TXEN);
    
    //Set Frame Format, 8 bit data, 2 stop bit, Asynchronous
    UCSR1C |= (1<<UCSZ11)|(1<<UCSZ10)|(1<<USBS1);
}//uart_init

/**********************************************************************************************
 * Name: uart_transmit
 *
 * Description: This function has a 8 bit data array as an input argument. This array
 * 	will be formatted as a 10 byte frame that contains two torque values and a
 *	steering angle that will be sent over uart 10 times a second. Each torque
 *	value will be 4 bytes, 2 bytes for the integer part and 2 bytes for the fraction
 *	part. The steering angle will be 2 bytes which leaves a total of 10 bytes to be
 *	transmitted. Uart can only transmit 8 bits at a time thats why we use an array
 * 	to frame the data into 8 bit segments. 
 *
 *	TODO: We need to add flag bits after every byte is sent so we can keep data together.
 *		We also might need to add a hand shake feature or error checking so the data
 *		being sent is reliable and not garbage.
 ************************************************************************************************/
void uart_transmit(uint8_t data_array[]){
    int i = 0;
    //Wait for empty transmit buffer
    while(!(UCSR1A & (1<<UDRE1))) { }

    for(i=0;i<2; i++){
        //Put data into buffer, send data
        UDR1 = data_array[i];
        while(!(UCSR1A & (1<<UDRE1))) { }
    }//for
	    //Send flag bit/byte
        UDR1 = '\n';
        while(!(UCSR1A & (1<<UDRE1))) { }

    for(i=2;i<4; i++){
        //Put data into buffer, send data
        UDR1 = data_array[i];
        while(!(UCSR1A & (1<<UDRE1))) { }
    }//for
	    //Send flag bit/byte
        UDR1 = '\n';
        while(!(UCSR1A & (1<<UDRE1))) { }

}//uart_transmit

/****************************************************************************************
 * Name: program_init
 *
 * Description: This function is used to initialize the timer and uart and is called
 *	when the controller wakes up out of sleep mode.  
 ***************************************************************************************/
void program_init(){

    DDRB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4);
    DDRF = 0xFF;
    DDRD |= (1<<PD0);   //SPI SS pin
    DDRD &= ~(1<<PD7)|(1<<PD6);  //Configure Port D Pin 7, 6 for input
    PORTD |= (1<<PD7);  //enable pullup
    timer1_init();      //initialize 16 bit timer
    uart_init(MYUBBR);	//initialize uart
    sei();
}//program_init

/************************************************************************************************
 * Name: pirate_mode
 *
 * Description: This function is used to put the atmega128 into sleep mode when the car is 
 *	not accelerating so we can save power. This function shuts down all sensors and the
 *	12v power converter. The only thing that is not shutdown is the 5v converter so we
 *	can wake the microcontroller up with a rising edge interrupt using a toggle switch.
 *
 * 	TODO: We need to look into the feasability of using the acceleration button to go 
 *		into sleep mode whenever its not being pressed and waking up when acceleration
 *		mode is engadged. Aslo need to look into debounce circuitry or software 
 *		debounding so this feature is fail safe.  
 ************************************************************************************************/
void pirate_mode(){

    //Configure interrupt 0 so a rising edge will wake up the controller from sleep mode
    EICRA |= (1<<ISC11)|(1<<ISC10); //Generate aysnchronous interrupt request on rising edge
    EIMSK |= (1<<INT1);  //Enable external interrupt 0

    set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Enable power down mode, set sleep enable bit
                                         //in the MCUCR register
    PORTB &= ~((1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay)); //Turn off relay circuits
    cli();  //Clear global interrupt
    sleep_enable(); //Set sleep enable bit in MCUCR register
    sei();          //Set global interrupt bit
    sleep_cpu();    //CPU is sleeping
    sleep_disable();   //CPU wakes up on rising edge ISR is executed
    program_init();
    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay); //Turn on relay circuits
}//pirate_mode

//ISR for the pirate mode function
ISR(INT1_vect){
    EIMSK &= ~(1<<INT1);
}//ISR

//ISR for the 16 bit timer
ISR(TIMER1_OVF_vect){
    PORTB ^= (1<<PB7);
    PORTF |= (1<<PF0);
    motor_torque(&torque_right, &torque_left, &steering_angle);	//Update motor torques
    spi_float_to_int(&TR, torque_right);	//convert right motor torque value from float to int
    spi_float_to_int(&TL, torque_left);		//convert left motortorque value from float to int
    
    //Below we format the two torque values and steering angle into a
    //10 byte frame to be sent over uart
    data_array[0] = TR.integer >> 8;		//high byte
    data_array[1] = TR.integer & 0x00FF;	//low byte
    data_array[2] = TR.fraction >> 8;
    data_array[3] = TR.fraction & 0x00FF;
/*    data_array[4] = TL.integer >> 8;
    data_array[5] = TL.integer & 0x00FF;
    data_array[6] = TL.fraction >> 8;
    data_array[7] = TL.fraction & 0x00FF;
    data_array[8] = steering_angle >> 8;
    data_array[9] = steering_angle & 0x00FF; */
    uart_transmit(data_array);		//Call uart transmit to transmit 10 bytes
    spi_init();	//Used to initalize SPI for LCD screen if being used
    PORTF &= ~(1<<PF0);
}//timer1_isr

int main(){
   char lcd_data1[16] = {"         "};
   char lcd_data2[16] = {"             "};
   char lcd_data3[16] = {"        "};
   char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    DDRB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4);
    DDRF = 0xFF;
    //DDRD |= (1<<PD0);   //SPI SS pin
    DDRD &= ~(1<<PD7)|(1<<PD6);  //Configure Port D Pin 7, 6 for input
    PORTD |= (1<<PD7);  //enable pullup
/*    spi_init();
    lcd_init();
    clear_display();
    cursor_home();
*/    spi_encoder_init();
    timer1_init();      //initialize 16 bit timer
    uart_init(MYUBBR);	//initialize uart
    sei();

    //spi_float_to_int(&TR, torque_right);	//convert right motor torque value from float to int
    //spi_float_to_int(&TL, torque_left);		//convert left motortorque value from float to int
    while(1){
/*    
	if(!(PIND & (1<<PD1))){
		pirate_mode();	//If toggle goes low, go to sleep
		_delay_ms(10);
	} */
/*    
        clear_display();
        cursor_home();
 
        lcd_data1[0] = numbers[TR.integer/100 % 10];
        lcd_data1[1] = numbers[TR.integer/10 % 10];
        lcd_data1[2] = numbers[TR.integer % 10];
        lcd_data1[3] = '.';
        lcd_data1[4] = numbers[TR.fraction/100 % 10];
        lcd_data1[5] = numbers[TR.fraction/10 % 10];
        lcd_data1[6] = numbers[TR.fraction % 10];

        lcd_data2[0] = numbers[TL.integer/100 % 10];
        lcd_data2[1] = numbers[TL.integer/10 % 10];
        lcd_data2[2] = numbers[TL.integer % 10];
        lcd_data2[3] = '.';
        lcd_data2[4] = numbers[TL.fraction/100 % 10];
        lcd_data2[5] = numbers[TL.fraction/10 % 10];
        lcd_data2[6] = numbers[TL.fraction % 10];
*/        
        /*
        lcd_data3[0] = numbers[steering_angle/1000 % 10];
        lcd_data3[1] = numbers[steering_angle/100 % 10];
        lcd_data3[2] = numbers[steering_angle/10 % 10];
        lcd_data3[3] = numbers[steering_angle/1 % 10];
        */
/*
        string2lcd(lcd_data1);
        string2lcd(lcd_data2);
        //string2lcd(lcd_data3);	    
        
        _delay_ms(20);
*/        
    }//while
return 0;
}//main
