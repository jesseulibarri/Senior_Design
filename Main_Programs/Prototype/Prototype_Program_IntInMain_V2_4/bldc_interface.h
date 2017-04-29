#ifndef BLDC_INTERFACE_H_
#define BLDC_INTERFACE_H_

#include "datatypes.h"

// interface functions
void bldc_interface_init(void(*func)(unsigned char *data, unsigned int len));
void bldc_interface_send_packet(unsigned char *data, unsigned int len);

// Setters
void bldc_interface_set_current(float current);
void bldc_interface_set_current_brake(float current);
void bldc_interface_set_rpm(int rpm);

// Other functions
void bldc_interface_reboot(void);
void bldc_interface_send_alive(void);

#endif /* BLDC_INTERFACE_H_ */
