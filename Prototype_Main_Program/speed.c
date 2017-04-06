
#include <avr/io.h>
#include <math.h>
#include "system_init.h"
#include "speed.h"

#define COUNT_PERIOD    0.016F
#define N 10

/*****************************************************************************
 * Name: Exponential Moving Average
 *  
 * Description: This function 
 * **************************************************************************/
//Exponential Moving Average
float ema(float avg, float sample)
{
    float alpha = 2.0/(N+1);
    avg = alpha * sample + (1.0-alpha) * avg;
    return avg;
}


/**************************************************************************************
 * Name: calc_speed
 *
 * Description: Calculates the speed based on the incoming speed sensor pulse.
 *************************************************************************************/
float calc_speed(uint16_t time_dif, float current_avg) {

//    static uint16_t timestamp_avg_dif;

//    timestamp_avg_dif = calc_avg(timestamps);
    float msec = (float)time_dif * COUNT_PERIOD;
    float seconds = msec / 1000;
    float new_speed = (distance_per_pulse/ seconds) * (1 / 17.6);
    float new_avg = ema(current_avg, new_speed); 

return new_avg;
}//calc_speed




