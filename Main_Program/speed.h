/********************************************************
 * File Name: speed.h
 *
 *
 * *****************************************************/

#ifndef SPEED_H
#define SPEED_H

extern double speed1;
extern double speed2;

//timestamps from the input capture pin
extern uint16_t times1[10];
extern uint16_t times2[10];

uint16_t calc_avg(uint16_t *array);
void calc_speed();

//TODO: Need to change calc speed so that it takes in an array
//  of speed timestamps, and outputs the calculated speed.
//  This way, we will be able to use the same calc function
//  for both speed sensors.

#endif
