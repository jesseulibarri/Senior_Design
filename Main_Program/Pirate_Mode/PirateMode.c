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
#include <util/delay.h>
#include <stdlib.h>

#define speed1_relay  0    //Port C Pin 0
#define speed2_relay  1    //Port C Pin 1
#define pc_relay  2       //Port C Pin 2
#define pirate_switch  0   //Port C Pin 3




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

    PORTB &= ~((1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay));

    while(!(PIND & (1<<PD1))){ }

    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay);
}//pirate_mode

int main() {

    DDRB = 0xFF;
    DDRD = 0x00;
    PORTD = 0xFF;

    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay);
    
    while(1){
        
        if(!(PIND & (1<<PD1))){
             pirate_mode();
        }
        _delay_ms(500);
    }
return 0;
}//main
