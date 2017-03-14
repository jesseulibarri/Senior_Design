/********************************************************
 * File Name: steering.h
 *
 *
 * *****************************************************/

#ifndef STEERING_H
#define STEERING_H

void calibrate_spi_steering();
uint16_t get_angle();
float calc_angle(uint16_t adc_result, const float SF, const float deg_offset);

#endif
