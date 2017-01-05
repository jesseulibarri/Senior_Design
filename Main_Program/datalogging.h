/********************************************************
 * File Name: datalogging.h
 *
 *
 * *****************************************************/

#ifndef DATALOGGING_H
#define DATALOGGING_H

uint8_t timeout();
uint8_t spi_8bit_tx(uint8_t);
uint8_t spi_16bit_tx(uint16_t);
uint8_t spi_double_tx(double);

#endif
