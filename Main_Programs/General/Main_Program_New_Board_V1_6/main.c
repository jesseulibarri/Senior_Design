/********************************************************
 * File Name: main.c
 * Author:
 * Date:
 *
 * Description: This is the main loop for the SEM Urban
 *  Concept vehicle.
 *  ****************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "system_init.h"
#include "uart.h"
#include "steering.h"
#include "pirate.h"


volatile uint8_t wake_up_timing;
//uint16_t encoder_angle = 20;

int main(){
///*** Calculate the system needed constants ***/
tire_circ = TIRE_DIAM * M_PI;
distance_per_pulse = tire_circ / SPROCKET_TEETH;

system_init();

wake_up_timing = 1;

while(1) {

	PORTA &= ~(1<<PA1);
	encoder_angle = get_angle(encoder_angle);
	if(!(PINE & (1<<PE4))){
        wake_up_timing = 1;
		PORTA |= (1<<PA1);
		pirate_mode();
        wake_up_timing = 1;
		
	}
	
}	


return 0;
}//main
