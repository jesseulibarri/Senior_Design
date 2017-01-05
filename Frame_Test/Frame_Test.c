#include <stdio.h>
#include <string.h>
#include "frame.h"
#include "datatypes.h"
//#include "commands.h"
#include "cobs.h"

int main(){
    
	struct DataFrame_t message;
	char data[];
	
	data[] = [0x07, 0x02, 0x00, 0x14];
	for(unsigned int i=0; i < sizeof(data); i++)
        strcpy(message->data[i], data[i]);
    message.length = sizeof(message->data);
	
	//printf(message->data);
	//printf(message->length);
	
	//char msg[] = {0x01, 'O', 'K'};

    //unsigned int crc = 0;
    //for(int i=0; i < sizeof(msg); i++)
    //    crc = frame_update_crc(crc, msg[i]);

    //char frame[5];
    //memcpy(frame, msg, 3);
    //frame[3] = (crc >> 8) & 0x000000FF;
    //frame[4] = (crc & 0x000000FF);

    //char output[30];
    //frame_encode(output, frame, 5);

    /*for(int i=0; i < sizeof(msg); i++){*/
        /*printf("%02x ", msg[i]);*/
    /*}*/
    /*printf("\n");*/

    /*char output[30];*/
    /*frame_encode(output, msg, sizeof(msg));*/

    //printf("Encoded: ");
    //for(int i=0; i < 7; i++){
    //    printf("\\x%02x", output[i]);
    //}
    //printf("\n");

    /*char decoded[40];*/
    /*frame_decode(decoded, output);*/

    /*for(int i=0; i < sizeof(msg); i++){*/
        /*printf("%02x ", decoded[i]);*/
    /*}*/
    /*printf("\n");*/

    /*unsigned int crc = 0;*/
    /*for(int i=0; i < sizeof(msg); i++)*/
        /*crc = frame_update_crc(crc, msg[i]);*/

    /*printf("%04x\n", crc);*/

    /*unsigned char tmp[100];*/
    /*memcpy(tmp, msg, sizeof(msg));*/
    /*tmp[sizeof(msg)] = (crc >> 8) & 0xFF;*/
    /*tmp[sizeof(msg)+1] = (crc >> 0) & 0xFF;*/

    /*for(int i=0; i < sizeof(msg) + 2; i++){*/
        /*printf("%02x ", tmp[i]);*/
    /*}*/

    /*printf("\n");*/

    /*printf("%d\n", frame_verify_crc(tmp, sizeof(msg) + 2));*/



    return 0;
}