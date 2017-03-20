
//#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <stdlib.h>
#include "pirate.h"
#include "system_init.h"


/*********************************************************************
 * Name: pirate_mode
 *
 * Description: This function will be called when the pirate mode
 * switch is toggled to logic low. Then the speed 1 & 2 and 12v 
 * relay will be turned off. A while loop will execute until a
 * logic high is detected on the pirate switch.Then before returing
 * to main the three relays will be turned back on. 
 *
 * TODO: Configure Port C data direction for pirate mode function.
 *********************************************************************/
void pirate_mode() {
    //Configure interrupt 0 so a rising edge will wake up the controller out of sleep mode
    
    EICRA = (1<<ISC00) | (1<<ISC01);   //Generate aysnchronous interrupt request on rising edge
    EIMSK = (1<<INT0);                 //Enable external interrupt 0
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    //Enable power down mode, set sleep enable bit 
                                            //in the MCUCR register
    PORTD &= ~(1<<PC_ON_OFF);  //Turn 12V power converter
    PORTB &= ~(1<<PB7);
    cli();  //clear global interrupt, only needed if storing data before sleep
    sleep_enable();         //Set sleep enable bit in MCUCR register
    sei();                  //Set global interrupt bit
    sleep_cpu();            //CPU is sleeping
    sleep_disable();        //CPU wakes up on rising edge ISR is executed
    system_init();
    

}//pirate_mode


