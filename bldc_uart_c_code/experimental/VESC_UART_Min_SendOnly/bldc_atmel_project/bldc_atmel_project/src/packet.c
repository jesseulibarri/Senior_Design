#include <string.h>
#include "packet.h"
#include "crc.h"

typedef struct {
	volatile unsigned char rx_state;
	volatile unsigned char rx_timeout;
	void(*send_func)(unsigned char *data, unsigned int len);
	unsigned int payload_length;
	unsigned char rx_buffer[PACKET_MAX_PL_LEN];
	unsigned char tx_buffer[PACKET_MAX_PL_LEN + 6];
	unsigned int rx_data_ptr;
	unsigned char crc_low;
	unsigned char crc_high;
} PACKET_STATE_t;

static PACKET_STATE_t handler_states[PACKET_HANDLERS];

void packet_init(void (*s_func)(unsigned char *data, unsigned int len), int handler_num) {
	handler_states[handler_num].send_func = s_func;
}

void packet_send_packet(unsigned char *data, unsigned int len, int handler_num) {
	if (len > PACKET_MAX_PL_LEN) {
		return;
	}

	int b_ind = 0;

	if (len <= 256) {
		handler_states[handler_num].tx_buffer[b_ind++] = 2;
		handler_states[handler_num].tx_buffer[b_ind++] = len;
	} else {
		handler_states[handler_num].tx_buffer[b_ind++] = 3;
		handler_states[handler_num].tx_buffer[b_ind++] = len >> 8;
		handler_states[handler_num].tx_buffer[b_ind++] = len & 0xFF;
	}

	memcpy(handler_states[handler_num].tx_buffer + b_ind, data, len);
	b_ind += len;

	unsigned short crc = crc16(data, len);
	handler_states[handler_num].tx_buffer[b_ind++] = (uint8_t)(crc >> 8);
	handler_states[handler_num].tx_buffer[b_ind++] = (uint8_t)(crc & 0xFF);
	handler_states[handler_num].tx_buffer[b_ind++] = 3;

	if (handler_states[handler_num].send_func) {
		handler_states[handler_num].send_func(handler_states[handler_num].tx_buffer, b_ind);
	}
}

/**
 * Call this function every millisecond.
 */
void packet_timerfunc(void) {
	int i = 0;
	for (i = 0;i < PACKET_HANDLERS;i++) {
		if (handler_states[i].rx_timeout) {
			handler_states[i].rx_timeout--;
		} else {
			handler_states[i].rx_state = 0;
		}
	}
}