/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

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

    calc_speed1();
    spi_double_transmit(speed1);
    spi_8bit_transmit(dropped_byte);
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

    calc_speed2();
    spi_double_transmit(speed2);
    spi_8bit_transmit(dropped_byte);
    //dropped_byte++;
    /*
    if(i > 70) {
        format_lcd_array(speed);
        i = 0;
    }
    i++;
   */

}

