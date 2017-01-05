#include <stdio.h>
#include <string.h>
#include "frame.h"
#include "datatypes.h"
//#include "commands.h"
#include "cobs.h"
uint16_t crc_1021(uint16_t old_crc, unsigned char data);

/* DATAFRAME_SIZE defined in datatypes.h */

void frame_encode(struct DataFrame_t *frame){

    static unsigned char tmp[DATAFRAME_SIZE];

    /* add CRC */
    unsigned int calc_crc = 0x0000;
    for(unsigned int i=0; i < frame->length; i++)
        calc_crc = crc_1021(calc_crc, frame->data[i]);

    frame->data[frame->length] = (calc_crc >> 8) & 0x00FF;
    frame->data[frame->length + 1] = (calc_crc) & 0x00FF;
    frame->length += 2;
    frame->crc = calc_crc;

    cobs_encode_result status;
    status = cobs_encode(tmp, DATAFRAME_SIZE, &(frame->data[0]), frame->length);
    memcpy(frame->data, tmp, status.out_len);
    frame->length = status.out_len;
    frame->operation = FRAME_OP_NONE;
    frame->status = FRAME_STATUS_ENCODED;
}

void frame_decode(struct DataFrame_t *frame){

    static unsigned char tmp[DATAFRAME_SIZE];
    cobs_decode_result status;
    status = cobs_decode(tmp, DATAFRAME_SIZE, &(frame->data[0]), frame->length);
    memcpy(frame->data, tmp, status.out_len);
    frame->length = status.out_len;
    frame->operation = FRAME_OP_NONE;
    frame->status = FRAME_STATUS_DECODED;
}

uint16_t crc_1021(uint16_t old_crc, unsigned char data)
{
	uint16_t crc;
	uint16_t x;
	x = ((old_crc >> 8) ^ data) & 0xFF;  //x = ((old_crc>>8) ^ data) & 0xff; 
 	x ^= x>>4;
 	crc = (old_crc << 8) ^ (x << 12) ^ (x <<5) ^ x;
 	crc &= 0xffff;
 	return crc;
}

unsigned int frame_update_crc(unsigned int crc, unsigned char data){

    crc = crc ^ (((unsigned int)data & 0x0000FFFF) << 8);
    crc &= 0x0000FFFF;

    unsigned int i;
    for(i = 0; i < 8; i++){
        if(crc & 0x8000)
            crc = (crc << 1) ^ 0x1021;
        else
            crc <<= 1;
    }

    return (crc & 0x0000FFFF);
}


unsigned int frame_verify_crc(struct DataFrame_t *frame){

    unsigned char *data = frame->data;
    unsigned int len = frame->length;
    unsigned int given_crc = 0x0000;
    unsigned int calc_crc  = 0x0000;

    /* extract crc from data frame */
    given_crc |= (data[len-2]) << 8;
    given_crc |= (data[len-1]) & 0x00FF;
    frame->crc = given_crc;
    frame->length -= 2;

    /* calculate crc of received data */
    for(unsigned int i=0; i < len-2; i++)
        calc_crc = crc_1021(calc_crc, data[i]);
    calc_crc &= 0x0000FFFF;

    /* compare the two */
    /* mark volatile for debug */
    uint8_t flag = (given_crc == calc_crc);
    return flag;
}

void frame_init(struct DataFrame_t *frame){
    frame->length = 0;
    frame->crc = 0x0000;
    frame->status = FRAME_STATUS_OK;
    frame->operation = FRAME_OP_NONE;
}

void frame_process(struct DataFrame_t *frame){

    if(frame->operation == FRAME_OP_DECODE){
        frame_decode(frame);
        /* drop if bad crc. log or debug here */
        /* XXX: log/notify for bad crc or something */
        if(!frame_verify_crc(frame)){
            frame->status = FRAME_STATUS_ERR;
        }
    }
    else if (frame->operation == FRAME_OP_ENCODE){
        frame_encode(frame);
    }
}
