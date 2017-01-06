/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "speed.h"
#include "datalogging.h"

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

    calc_speed();
    spi_double_tx(speed1);
    spi_8bit_tx(dropped_byte);
    //dropped_byte++;
    /*
    if(i > 70) {
        format_lcd_array(speed);
        i = 0;
    }
    i++;
   */

}


/*********************************************************************
 * ISR: speed_sensor_2
 *
 * Description: 
 *********************************************************************/
ISR(TIMER3_CAPT_vect) {

    calc_speed();
    spi_double_tx(speed2);
    spi_8bit_tx(dropped_byte);
    //dropped_byte++;
    /*
    if(i > 70) {
        format_lcd_array(speed);
        i = 0;
    }
    i++;
   */

}

