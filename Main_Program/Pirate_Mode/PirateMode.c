/**********************************************
 * Author: Shane Licari
 * Date: 12/19/16
 *
 * Description: This program will contain a
 *  Pirate Mode function that executes when
 *  when the driver toggles the pirate mode
 *  switch.
 * *******************************************/
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <stdlib.h>

#define speed1_relay  0    //Port C Pin 0
#define speed2_relay  1    //Port C Pin 1
#define pc_relay  2       //Port C Pin 2
#define pirate_switch  0   //Port D Pin 0




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
    //Enable power down mode and enable the sleep bit in MCUCR register
    //MCUCR = (1<<SM1);
    EICRB = (1<<ISC00) | (1<<ISC01);   //Generate aysnchronous interrupt request on rising edge
    EIMSK |= (1<<INT0);                 //Enable external interrupt 0
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    PORTB &= ~((1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay));  //Turn off relay circuits
    cli();
    _delay_ms(1000);

    if (PIND == 0b11111111){    
        sleep_enable();          //set sleep enable bit in MCUCR register
        //sleep_bod_disable();    //Disable brown out detector
        sei();  //set global interrupt bit
        sleep_cpu();
        sleep_disable();
    }
    
    
    
    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay); //Turn on relay circuits
}//pirate_mode

ISR(INT0_vect){
    EIMSK &= ~(1<<INT0);
    EIFR &= ~(1<<INTF0);
    //PORTD = (1<<PD0);
}//ISR

/*int8_t debounce_switch() {
    static uint16_t state = 0; //holds present state
    state = (state << 1) | (!bit_is_clear(PIND, 0)) | 0xE000;
    if (state == 0xF000) reutrn 1;
    return 0;
}
*/

int main() {
    //int8_t check;
    DDRB = 0xFF;
    DDRD = 0x00;
    PORTD = 0xFF;

    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay); //Turn on relay circuits
    
    while(1){
        if(!(PIND & (1<<PD0))){ //If pin goes low enter pirate mode
             pirate_mode();
        }
        _delay_ms(500);
    }
return 0;
}//main
