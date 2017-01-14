/********************************************************
 * File Name: steering.c
 *
 * *****************************************************/

#include "steering.h"

float calc_angle(uint16_t adc_result, const float SF, const float deg_offset) {

    float result;
    result = (adc_result*SF)-(deg_offset);
    return result;


}
