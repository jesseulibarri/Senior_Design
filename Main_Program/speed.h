/********************************************************
 * File Name: speed.h
 *
 *
 * *****************************************************/

#ifndef SPEED_H
#define SPEED_H

uint16_t calc_avg(uint16_t *array);
void calc_speed();

//TODO: Need to change calc speed so that it takes in an array
//  of speed timestamps, and outputs the calculated speed.
//  This way, we will be able to use the same calc function
//  for both speed sensors.

#endif
