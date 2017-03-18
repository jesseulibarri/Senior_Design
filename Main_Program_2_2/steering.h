/********************************************************
 * File Name: steering.h
 *
 *
 * *****************************************************/

#ifndef STEERING_H
#define STEERING_H

void spi_encoder_init();
void calibrate_spi_steering();
uint16_t get_angle();
#endif
