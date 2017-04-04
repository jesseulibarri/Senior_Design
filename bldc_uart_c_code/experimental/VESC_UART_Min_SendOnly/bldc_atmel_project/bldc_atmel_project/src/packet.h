#ifndef PACKET_H_
#define PACKET_H_

#include <stdint.h>

// Settings
#define PACKET_RX_TIMEOUT		2
#define PACKET_HANDLERS			1
#define PACKET_MAX_PL_LEN		512

// Functions
void packet_init(void (*s_func)(unsigned char *data, unsigned int len), int handler_num);
void packet_timerfunc(void);
void packet_send_packet(unsigned char *data, unsigned int len, int handler_num);

#endif /* PACKET_H_ */
