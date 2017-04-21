/*******************************************************
 * File Name: main.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description: This is the main loop for the SEM Urban
 * Concept vehicle.
 *****************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "system_init.h"
#include "uart.h"

int main(){
	//Initialize the system
	system_init();
	//delay for 1 sec to ensure motor controller is functional
	_delay_ms(1000);
	
	while(1){}
	
	return 0;
}//main