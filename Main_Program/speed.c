
#include <avr/io.h>
#include "speed.h"
#include "const.h"
#include "datalogging.h"

double speed1;
double speed2;

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
void calc_speed() {

    int8_t k;
    uint16_t timestamp = ICR1;
    static uint16_t timestamp_hist = 0;
    static uint16_t timestamp_dif[10] = {1};
    //static uint16_t timestamp_dif;
    static uint16_t timestamp_avg_dif;

    //shift difference history over to make room for new
    for(k = 9; k >= 0; k--) { timestamp_dif[k+1] = timestamp_dif[k]; }

    if(timestamp < timestamp_hist) {
        //timestamp_dif = 65535 - timestamp_hist + timestamp;
        timestamp_dif[0] = 65535 - timestamp_hist + timestamp;
    } 
    else 
        //timestamp_dif = timestamp - timestamp_hist;
        timestamp_dif[0] = timestamp - timestamp_hist;

    timestamp_avg_dif = calc_avg(timestamp_dif);
    double msec = (double)timestamp_avg_dif * COUNT_PERIOD;
    double seconds = msec / 1000;
    speed1 = (distance_per_pulse / seconds) * (1 / MPH_TO_SEC_PER_IN);
    timestamp_hist = timestamp;

    //TODO: Change the function so that it returns the calculated speed.
    //  This will allow us to use the same function for both speed sensors.

}//calc_speed



