#include "frame.h"
#include "commands.h"
#include "datatypes.h"
#include "string.h"
//#include "uart.h"
//#include "motor.h"
//#include "arm_math.h"
//#include "sampling.h"
//#include "adc.h"
//#include "constants.h"
//#include "hall.h"



void float2Bytes(unsigned char* bytes_temp, float float_variable){
	union {
		float a;
		unsigned char bytes[4];
	} thing;
	thing.a = float_variable;
	memcpy(bytes_temp, thing.bytes, 4);
}
