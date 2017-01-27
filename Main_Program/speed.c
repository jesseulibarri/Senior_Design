
#include <avr/io.h>
#include "speed.h"
#include "const.h"
#include "datalogging.h"
#include "user_io.h"

float speed1;
float speed2;
float target_speed;
uint16_t times1[10] = {1};
uint16_t times2[10] = {1};

/**************************************************************************************
 * Name: calc_avg
 *
 * Description: Calculates the average of elements in an array.
 *************************************************************************************/
uint16_t calc_avg(uint16_t *array) {
    uint8_t j;
    uint16_t sum = 0;
    for(j = 0; j < 10; j++) { sum = sum + array[j]; }
    uint16_t avg = sum / 10;
    return avg;
}//calc_avg


/**************************************************************************************
 * Name: calc_speed
 *
 * Description: Calculates the speed based on the incoming speed sensor pulse.
 *************************************************************************************/
float calc_speed(uint16_t *times) {

    uint16_t timestamp_avg_dif = calc_avg(times);
    float msec = (float)timestamp_avg_dif * COUNT_PERIOD;
    float seconds = msec / 1000;
    float speed = (distance_per_pulse / seconds) * (1 / MPH_TO_SEC_PER_IN);
return speed;
   
}//calc_speed


uint8_t motor_torque() {

    static uint8_t dummy_torque = 0;
    static uint8_t dummy_torque2;

    //TODO: For now, this is just a dummy function as a tester
    switch(user_mode)
    {
        //We are accelerating
        case 0x01:
            target_speed = speed1;
            if(dummy_torque > 25) { dummy_torque = 0; }
            return dummy_torque++;

        //We are cruising
        case 0x02:
            if(target_speed < speed1) { dummy_torque2 = 0; }
            else { dummy_torque2 = 5; }
            return dummy_torque2;
    }//switch
}//motor_torque
