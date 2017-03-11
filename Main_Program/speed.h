/********************************************************
 * File Name: speed.h
 *
 *
 * *****************************************************/

#ifndef SPEED_H
#define SPEED_H

float ema(float avg, float sample);
float calc_speed(uint16_t time_dif, float current_avg);
void accelerate(float* torque_right, float* torque_left, uint16_t angle, float b_torque);
void cruise(float* torque_right, float* torque_left, uint16_t angle, float b_torque, float target_speed);

#endif
