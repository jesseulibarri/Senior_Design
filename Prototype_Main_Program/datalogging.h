/*******************************************************
 * File Name: datalogging.h
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description:
********************************************************/

#ifndef DATALOGGING_H
#define DATALOGGING_H

extern uint16_t dropped_byte;

void spi_rpi_init();
uint8_t timeout();
uint8_t spi_8bit_tx(uint8_t);
uint8_t spi_16bit_tx(uint16_t);
uint8_t spi_double_tx(double);

#endif
