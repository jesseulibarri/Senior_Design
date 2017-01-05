#include <stdio.h>
#include <string.h>
#include "frame.h"
#include "datatypes.h"
//#include "commands.h"
#include "cobs.h"

int main(){
    
    struct DataFrame_t message;
	char data[] = {'1','2','3','4','5'};

	for(unsigned int i=0; i < sizeof(data); i++)
        message.data[i] = data[i];
    message.length = sizeof(data);
    message.crc = 0x0000;
    message.status = FRAME_STATUS_OK;
    message.operation = FRAME_OP_ENCODE;

    printf("Message contents: ");
    for(int i=0; i < message.length; i++){
        printf("%02x ", message.data[i]);
    }
    
    printf("\n");
    printf("Message length: %i ", message.length);
    printf("\n");
    printf("Message CRC: %i ", message.crc);
    printf("\n");
    //printf("%s ", message.operation);
    printf("\n");
    //printf("%s ", message.status);


    frame_encode(&message);
   
    printf("Encoded message contents: ");
    for(int i=0; i < message.length; i++){
        printf("%02x ", message.data[i]);
    }
 
    printf("\n");
    printf("Encoded message length: %i ", message.length);
    printf("\n");
    printf("Encoded message CRC: %i ", message.crc);
    printf("\n");
    //printf("%s ", message.operation);
    printf("\n");
    //printf("%s ", message.status);


    uint8_t Flag = frame_verify_crc(&message);
    printf("CRC Error Check Status: %i ", Flag);
    printf("\n\n");


    frame_decode(&message);

    printf("Decoded message contents: ");
    for(int i=0; i < message.length; i++){
        printf("%02x ", message.data[i]);
    }
 
    printf("\n");
    printf("Decoded message length: %i ", message.length);
    printf("\n");
    printf("Decoded message CRC: %i ", message.crc);
    printf("\n");
    //printf("%s ", message.operation);
    printf("\n");
    //printf("%s ", message.status);
 


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
