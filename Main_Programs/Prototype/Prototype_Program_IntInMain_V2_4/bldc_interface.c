#include "bldc_interface.h"
#include "buffer.h"
#include <string.h>

// Private variables
static unsigned char send_buffer[512];

// Function pointers
static void(*send_func)(unsigned char *data, unsigned int len) = 0;

/**
 * Initialize bldc_interface.
 *
 * @param func
 * A function to be used when sending packets. Null (0) means that no packets will be sent.
 */
void bldc_interface_init(void(*func)(unsigned char *data, unsigned int len)) {
	send_func = func;
}

/**
 * Send a packet using the set send function.
 *
 * @param data
 * The packet data.
 *
 * @param len
 * The data length.
 */
void bldc_interface_send_packet(unsigned char *data, unsigned int len) {
	if (send_func) {
		send_func(data, len);
	}
}

// Setters
void bldc_interface_set_current(float current) {
	int32_t send_index = 0;
	send_buffer[send_index++] = COMM_SET_CURRENT;
	buffer_append_float32(send_buffer, current, 1000.0, &send_index);
	bldc_interface_send_packet(send_buffer, send_index);
}

void bldc_interface_set_rpm(int rpm) {
	int32_t send_index = 0;
	send_buffer[send_index++] = COMM_SET_RPM;
	buffer_append_int32(send_buffer, rpm, &send_index);
	bldc_interface_send_packet(send_buffer, send_index);	
}

void bldc_interface_set_current_brake(float current) {
	int32_t send_index = 0;
	send_buffer[send_index++] = COMM_SET_CURRENT_BRAKE;
	buffer_append_float32(send_buffer, current, 1000.0, &send_index);
	bldc_interface_send_packet(send_buffer, send_index);	
}

// Other functions
void bldc_interface_reboot(void) {
	int32_t send_index = 0;
	send_buffer[send_index++] = COMM_REBOOT;
}

void bldc_interface_send_alive(void) {
	int32_t send_index = 0;
	send_buffer[send_index++] = COMM_ALIVE;
}
