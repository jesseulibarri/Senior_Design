#include "frame.h"
#include "commands.h"
#include "datatypes.h"
#include "uart.h"
#include "motor.h"
#include "arm_math.h"
#include "sampling.h"
#include "adc.h"
#include "constants.h"
#include "hall.h"

static struct DataFrame_t resp;

void float2Bytes(unsigned char* bytes_temp, float32_t float_variable){
	union {
		float32_t a;
		unsigned char bytes[4];
	} thing;
	thing.a = float_variable;
	memcpy(bytes_temp, thing.bytes, 4);
}

void bytes2Float(unsigned char* bytes_temp, float32_t *float_variable){
	union {
		float32_t a;
		unsigned char bytes[4];
	} thing;
	memcpy(thing.bytes, bytes_temp, 4);
    *float_variable = thing.a;
}

void bytes2uint8(unsigned char* bytes_temp, uint8_t *int_var){
	union {
		uint8_t a;
		unsigned char bytes[4];
	} thing;
	memcpy(thing.bytes, bytes_temp, 4);
    *int_var = thing.a;
}

void uint32ToBytes(unsigned char* bytes_temp, uint32_t int_var){
	union {
		uint32_t a;
		unsigned char bytes[4];
	} thing;
    thing.a = int_var; 
	memcpy(bytes_temp, thing.bytes, 4);
}

void command_process(struct DataFrame_t *frame){

    unsigned char cmd = frame->data[0];
    unsigned char *data = &(frame->data[1]);

    frame_init(&resp);

    float32_t ftmp;
    uint32_t tmp32;
    /*uint8_t itmp;*/

    switch(cmd){
        case 0x01:
            resp.data[0] = 0x01;
            resp.data[1] = 'O';
            resp.data[2] = 'K';
            resp.length = 3;
            break;
        /* init sampling phase*/
        case 0x06:
            resp.data[0] = 0x06;
            resp.data[1] = 'O';
            resp.data[2] = 'K';
            resp.length = 3;
            sampling_start(2000, 1);
            break;
        /* get current speed (rpm) */
        case 0x0B:
            ftmp = motor_state.we * WE_TO_RPM;
            resp.data[0] = 0x0B;
            resp.length = 1;
            float2Bytes(resp.data + resp.length, ftmp);
            resp.length += 4;
            break;
        /* set vq (volts)*/
        case 0x0E:
            resp.data[0] = 0x0E;
            resp.data[1] = 'O';
            resp.data[2] = 'K';
            resp.length = 3;
            bytes2Float(data, &ftmp);
            motor_set_vq(ftmp);
            break;
        /* set vd (volts)*/
        case 0x0F:
            resp.data[0] = 0x0F;
            resp.data[1] = 'O';
            resp.data[2] = 'K';
            resp.length = 3;
            bytes2Float(data, &ftmp);
            motor_set_vd(ftmp);
            break;
        /* set iq (amps)*/
        case 0x10:
            resp.data[0] = 0x10;
            resp.data[1] = 'O';
            resp.data[2] = 'K';
            resp.length = 3;
            bytes2Float(data, &ftmp);
            motor_set_iq(ftmp);
            break;
        /* set vd vq */
        case 0x11:
            resp.data[0] = 0x10;
            resp.data[1] = 'O';
            resp.data[2] = 'K';
            resp.length = 3;
            bytes2Float(data, &ftmp);
            motor_set_vd(ftmp);
            bytes2Float(data+4, &ftmp);
            motor_set_vq(ftmp);
            break;
        /* get current electrical position) */
        case 0x12:
            ftmp = motor_state.we;
            resp.data[0] = 0x12;
            resp.length = 1;
            float2Bytes(resp.data + resp.length, ftmp);
            resp.length += 4;
            /*tmp32 = HALL_TIM->CCR1;*/
            /*resp.data[0] = 0x12;*/
            /*resp.length = 1;*/
            /*uint32ToBytes(resp.data + resp.length, tmp32);*/
            /*resp.length += 4;*/
            break;
        default:
            resp.data[0] = 0xFF;
            resp.data[1] = 'E';
            resp.data[2] = 'R';
            resp.data[3] = 'R';
            resp.length = 4;
            break;

    }

    resp.operation = FRAME_OP_ENCODE;
    frame_process(&resp);
    if(resp.status == FRAME_STATUS_ENCODED){
        uart1_send_frame(&resp);
    }
}
