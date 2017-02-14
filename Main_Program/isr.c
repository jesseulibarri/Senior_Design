/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "speed.h"
#include "datalogging.h"
#include "system_init.h"
#include "user_io.h"
#include "pirate.h"


/*********************************************************************
 * ISR: timer0
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 16Hz
 *********************************************************************/
ISR(TIMER0_OVF_vect) {

    uint8_t torque1;
    uint8_t torque2;

    user_mode = PINA;

    switch(user_mode) 
    {
        //Accelerate button was let go
        case 0x00:
            pirate_mode();
            system_init();
            break;
        //Accelerate button is pushed
        case 0x01:

            speed1 = calc_speed(&times1);
            //speed two will not be needed if we only use one speed sensor
            speed2 = calc_speed(&times2);

            //TODO: This will go away if we use the SPI steering sensor
            //Start ADC conversion to get steering angle
            ADCSRA |= (1 << ADSC);                  //Poke ADSC and start conversion
            while(bit_is_clear(ADCSRA, ADIF)) { }   //loop while interrupt flag not set
            ADCSRA |= (1<<ADIF);                    //Clear flag by writing a one 

            //TODO: Calculate new values for the motor controllers
            torque1 = motor_torque();
            torque2 = motor_torque();
            //TODO: Build UART frame
            // frame(some_number_1);

            //***** Set data to LCD *******
            UDR0 = torque1;
            while(bit_is_clear(UCSR0A, TXC0)) {}
            UDR1 = torque2;
            while(bit_is_clear(UCSR1A, TXC1)) {}
            // frame(some_number_2);
            //TODO: UART0 send
            // tx_UART0(frame1);
            //TODO: UART1 send
            // tx_UART1(frame2);
            break;

        //Accelerate button is pushed
        case 0x02:

            speed1 = calc_speed(&times1);
            //speed two will not be needed if we only use one speed sensor
            speed2 = calc_speed(&times2);

            //TODO: This will go away if we use the SPI steering sensor
            //Start ADC conversion to get steering angle
            ADCSRA |= (1 << ADSC);                  //Poke ADSC and start conversion
            while(bit_is_clear(ADCSRA, ADIF)) { }   //loop while interrupt flag not set
            ADCSRA |= (1<<ADIF);                    //Clear flag by writing a one 

            //TODO: Calculate new values for the motor controllers
            torque1 = motor_torque();
            torque1 = motor_torque();
            //TODO: Build UART frame

            //***********
            UDR0 = torque1;
            while(bit_is_clear(UCSR0A, TXC0)) {}
            UDR1 = torque2;
            while(bit_is_clear(UCSR1A, TXC1)) {}

            // frame(some_number_1);
            // frame(some_number_2);
            //TODO: UART0 send
            // tx_UART0(frame1);
            //TODO: UART1 send
            // tx_UART1(frame2);
            break;
    }//switch

}//timer0_ISR


/*********************************************************************
 * ISR: pirate_mode
 *
 * Description: The pirate mode switch is connected to external
 *  interrupt 0. If triggered, the pirate mode function will be called.
 *********************************************************************/

ISR(INT0_vect){

    //NOT SURE WHAT THIS IS FOR
    EIMSK &= ~(1<<INT0);

    pirate_mode();
    system_init();

}//ISR


/*********************************************************************
 * ISR: speed_sensor_1
 *
 * Description: This interrupt will occur every time the speed sensor
 *  sends a pulse the uC. The interrupt will capture the timestamp
 *  that the pulse came in at, it will shift all the old timestamps
 *  in the time array to make room for the new one. It will then put
 *  the new stamp in position zero. As the car travels,
 *  the stamps will constantly be shifted through the array. 
 *********************************************************************/
ISR(TIMER1_CAPT_vect) {

    uint8_t k;
    uint16_t timestamp = ICR1;
    static uint16_t timestamp_hist1 = 0;

    //shift difference history over to make room for new
    for(k = 9; k >= 0; k--) { times1[k+1] = times1[k]; }
     
    //wrap around at the end of the timer
    if(timestamp < timestamp_hist1) { times1[0] = 65535 - timestamp_hist1 + timestamp; }
    else { times1[0] = timestamp - timestamp_hist1; }
              
    timestamp_hist1 = timestamp;
    
}


/*********************************************************************
 * ISR: speed_sensor_2
 *
 * Description: Same as speed_sensor_1 description. 
 *********************************************************************/
ISR(TIMER3_CAPT_vect) {

    uint8_t k;
    uint16_t timestamp = ICR3;
    static uint16_t timestamp_hist2 = 0;

    //shift difference history over to make room for new
    for(k = 9; k >= 0; k--) { times2[k+1] = times2[k]; }
    
    //wrap around at the end of the timer
    if(timestamp < timestamp_hist2) { times2[0] = 65535 - timestamp_hist2 + timestamp; }
    else { times2[0] = timestamp - timestamp_hist2; }
           
    timestamp_hist2 = timestamp;

}

