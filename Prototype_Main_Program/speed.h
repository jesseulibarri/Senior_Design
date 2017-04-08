/********************************************************
 * File Name: speed.h
 *
 *
 * *****************************************************/

#ifndef SPEED_H
#define SPEED_H

float ema(float avg, float sample);
float calc_speed(uint16_t time_dif, float current_avg);

#endif
