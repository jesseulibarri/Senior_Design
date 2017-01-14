/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "speed.h"
#include "datalogging.h"


/*********************************************************************
 * ISR: timer0
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 16Hz
 *********************************************************************/
ISR(TIMER0_OVF_vect) {

    speed1 = calc_speed(&times1);
    speed2 = calc_speed(&times2);

    //Start ADC conversion to get steering angle
    ADCSRA |= (1 << ADSC);                  //Poke ADSC and start conversion
    while(bit_is_clear(ADCSRA, ADIF)) { }   //loop while interrupt flag not set
    ADCSRA |= (1<<ADIF);                    //Clear flag by writing a one 

    //TODO: Calculate new values for the motor controllers
    //TODO: Build UART frame
    //TODO: UART0 send
    //TODO: UART1 send

}


/*********************************************************************
 * ISR: pirate_mode
 *
 * Description: 
 *********************************************************************/

ISR(INT0_vect){
    EIMSK &= ~(1<<INT0);
    
}//ISR


/*********************************************************************
 * ISR: speed_sensor_221
 *
 * Description: 
 *********************************************************************/
ISR(TIMER1_CAPT_vect) {

    uint8_t k;
    uint16_t timestamp = ICR1;
    static uint16_t timestamp_hist1 = 0;

         //shift difference history over to make room for new
         for(k = 9; k >= 0; k--) { times1[k+1] = times1[k]; }
     
         //wrap around at the end of the timer
         if(timestamp < timestamp_hist) { times1[0] = 65535 - timestamp_hist + timestamp; }
         else { times1[0] = timestamp - timestamp_hist; }
              
         timestamp_hist = timestamp;
    
    /*
    calc_speed();
    spi_double_tx(speed1);
    spi_8bit_tx(dropped_byte);
*/
}


/*********************************************************************
 * ISR: speed_sensor_2
 *
 * Description: 
 *********************************************************************/
ISR(TIMER3_CAPT_vect) {

    uint8_t k;
    uint16_t timestamp = ICR3;
    static uint16_t timestamp_hist2 = 0;

         //shift difference history over to make room for new
         for(k = 9; k >= 0; k--) { times2[k+1] = times2[k]; }
     
         //wrap around at the end of the timer
         if(timestamp < timestamp_hist) { times2[0] = 65535 - timestamp_hist + timestamp; }
         else { times2[0] = timestamp - timestamp_hist; }
              
         timestamp_hist = timestamp;


    /*
    calc_speed();
    spi_double_tx(speed2);
    spi_8bit_tx(dropped_byte);
*/
}

