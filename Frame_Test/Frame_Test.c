#include <stdio.h>
#include <string.h>
#include "frame.h"
#include "datatypes.h"
#include "commands.h"
#include "cobs.h"

int main(){
    
    struct DataFrame_t message;
	char data[] = {'0x0F','0'};
    float current = 2.546;
    
    float2Bytes(data[1], current);

	for(unsigned int i=0; i < sizeof(data); i++)
        message.data[i] = data[i];
    message.length = sizeof(data);
    message.crc = 0x0000;
    message.status = FRAME_STATUS_OK;
    message.operation = FRAME_OP_ENCODE;

    printf("Message contents: ");
    for(int i=0; i < message.length; i++){
        printf("%c ", message.data[i]);
    }
    
    printf("\n");
    printf("Message length: %i ", message.length);
    printf("\n");
    printf("Message CRC: %i ", message.crc);
    printf("\n");

    frame_encode(&message);
   
    printf("Encoded message contents: ");
    for(int i=0; i < message.length; i++){
        printf("%c ", message.data[i]);
    }
 
    printf("\n");
    printf("Encoded message length: %i ", message.length);
    printf("\n");
    printf("Encoded message CRC: %i ", message.crc);
    printf("\n");

    uint8_t Flag = frame_verify_crc(&message);
    printf("CRC Error Check Status: %i ", Flag);
    printf("\n\n");


    frame_decode(&message);

    printf("Decoded message contents: ");
    for(int i=0; i < message.length; i++){
        printf("%c ", message.data[i]);
    }
 
    printf("\n");
    printf("Decoded message length: %i ", message.length);
    printf("\n");
    printf("Decoded message CRC: %i ", message.crc);
    printf("\n");

    return 0;
}
