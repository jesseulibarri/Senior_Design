#ifndef DATATYPES_H
#define DATATYPES_H
//#include "stm32l4xx.h"
//#include "FreeRTOS.h"
//#include "queue.h"

#define   DATAFRAME_SIZE              128
#define   SAMPLE_BUF_LENGTH          2000

typedef enum{
    FRAME_OP_ENCODE,
    FRAME_OP_DECODE,
    FRAME_OP_NONE
} FRAME_OP;

typedef enum{
    FRAME_STATUS_OK,
    FRAME_STATUS_ERR,
    FRAME_STATUS_ENCODED,
    FRAME_STATUS_DECODED
} FRAME_STATUS;

struct DataFrame_t{
    unsigned char            data[DATAFRAME_SIZE];
    unsigned int                 length;
    unsigned int                    crc;
    FRAME_OP                  operation;
    FRAME_STATUS                 status;
};

#endif
