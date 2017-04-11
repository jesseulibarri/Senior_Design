#ifndef BLDC_INTERFACE_UART_H_
#define BLDC_INTERFACE_UART_H_

// Includes
#include "packet.h" // For the MAX_PACKET_LEN define

// Functions
void bldc_interface_uart_init(void(*func)(unsigned char *data, unsigned int len));

#endif /* BLDC_INTERFACE_UART_H_ */
