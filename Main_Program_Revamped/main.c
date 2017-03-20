/********************************************************
 * File Name: main.c
 * Author:
 * Date:
 *
 * Description: This is the main loop for the SEM Urban
 *  Concept vehicle.
 *  ****************************************************/

#include "system_init.h"
#include "uart.h"
#include "steering.h"

extern uint16_t encoder_angle;
int main()
{

system_init();

while(1) {
	encoder_angle = get_angle(encoder_angle);
}

return 0;
}//main
