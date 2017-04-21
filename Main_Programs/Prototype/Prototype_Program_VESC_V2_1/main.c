/********************************************************
 * File Name: main.c
 * Author:
 * Date:
 *
 * Description: This is the main loop for the SEM Urban
 * Concept vehicle.
 * ****************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "system_init.h"
#include "uart.h"
#include "steering.h"

uint16_t encoder_angle = 0;
int main()
{

///*** Calculate the system needed constants ***/
tire_circ = TIRE_DIAM * M_PI;
distance_per_pulse = tire_circ / SPROCKET_TEETH;

system_init();
_delay_ms(1000);

while(1) {
	//encoder_angle = get_angle(encoder_angle);
	encoder_angle = 0; 

}

return 0;
}//main
