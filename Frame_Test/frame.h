#ifndef FRAME_H
#define FRAME_H
#include "datatypes.h"

void frame_decode(struct DataFrame_t *frame);
void frame_encode(struct DataFrame_t *frame);
unsigned int frame_verify_crc(struct DataFrame_t *frame);
unsigned int frame_update_crc(unsigned int crc, unsigned char data);
void frame_process(struct DataFrame_t *frame);
void frame_init(struct DataFrame_t *frame);

#endif
