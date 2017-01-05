#ifndef DATATYPES_H
#define DATATYPES_H
#include "stm32l4xx.h"
#include "FreeRTOS.h"
#include "queue.h"

#define   DATAFRAME_SIZE              128
#define   SAMPLE_BUF_LENGTH          2000

typedef enum{
    PULLUP,
    PULLDOWN,
    NOPULL

} PULL_DIR;

typedef enum{
    DEBUG_LED,
    STATUS_A_LED,
    STATUS_B_LED
} LED_NAME;

typedef enum {
    INPUT,
    OUTPUT,
    ADC,
    AF
} PIN_MODE;

typedef enum{
    APHASE,
    BPHASE,
    CPHASE
} PHASE_NAME;

typedef enum{
    NORMAL,
    INVERTED
} FET_POLARITY;

typedef enum{
    VA=0,
    VB=1,
    VC=2,
    VN=3,
} PHASE_VOLTAGE;

typedef enum{
    IA=0,
    IB=1,
    IC=2
} PHASE_CURRENT;

typedef enum{
    AH_FET,
    AL_FET,
    BH_FET,
    BL_FET,
    CH_FET,
    CL_FET
} FET_NAME;

typedef enum{
    COMPI, /* Complementary, high and low on. duty ratio applies to high side */
    COMP, /* Complementary, high and low on. duty ratio applies to high side */
    HIGH, /* High side on, low side disabled */
    LOW,  /* Low side on, high side disabled */
    OFF  /* Both sides are off */
} PHASE_MODE;

typedef enum{
    ADC_VA,
    ADC_VB,
    ADC_VC,
    ADC_IA,
    ADC_IB,
    ADC_THROT,
    ADC_VN,
    ADC_VBAT
} ADC_NAME;

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

typedef enum{
    BUFFER_READY,
    BUFFER_EMPTY,
    BUFFER_FULL,
    BUFFER_OK,
    BUFFER_ERR
} BUFFER_STATUS;

typedef enum{
    CURRENT_SAMPLE,
    PHASE_VOLTAGE_SAMPLE
} SAMPLE_TYPE;

typedef enum{
    MOTORING,
    GENERATING,
    STOPPED,
    MEASURING,
    LOCKED,
    FAULT
} MOTOR_STATE;

typedef enum{
    VA_BUF=0,
    VB_BUF=1,
    VC_BUF=2,
    VN_BUF=3,
    IA_BUF=4,
    IB_BUF=5,
    IC_BUF=6,
    ID_BUF=7,
    IQ_BUF=8,
   POS_BUF=9,
 HALL_BUF=10
} SAMPLING_BUFFER;

typedef enum{
    READY,
    IDLE,
    SAMPLING,
    TRANSMITTING
} SAMPLING_STATE;

struct DataFrame_t{
    unsigned char            data[DATAFRAME_SIZE];
    unsigned int                 length;
    unsigned int                    crc;
    FRAME_OP                  operation;
    FRAME_STATUS                 status;
};

struct Fet_t{
    FET_NAME            name;
    GPIO_TypeDef*       port;
    uint8_t             pin;
    uint8_t             enabled; 
    /* output compare # */
    uint8_t             oc;
    /* (boolean) is negative side, ie CH3N */
    uint8_t             inv;
} _fet[6];

struct Phase_t{
    PHASE_NAME          name;
    struct Fet_t       *high;
    struct Fet_t        *low;
    PHASE_MODE          mode;
    float               duty;
} _phase[3];

struct ADC_t{
    ADC_NAME         name;
    GPIO_TypeDef    *port;
    uint8_t           pin;
    ADC_TypeDef      *adc;
    uint8_t            ch;
} _adc[9];

struct SampleBufferObj_t{
    volatile int16_t                         data[SAMPLE_BUF_LENGTH];
    volatile uint16_t                                         length;
    uint16_t                                                  target;
    uint8_t                                                     full;
    void       (*add)(struct SampleBufferObj_t *buf, int16_t sample);
    void    (*reset)(struct SampleBufferObj_t *buf, uint16_t target);
};

/* NOTE: Have to acknowledge READY flag before a new sampling session can
 * begin */
struct SamplerObj_t{
    struct SampleBufferObj_t                                      **buffers;
    uint8_t                                                          length;
    volatile SAMPLING_STATE                                           state;
    uint8_t                                                            xmit;
    uint8_t                                                          filled;
    uint16_t                                                         target;
    void    (*start)(struct SamplerObj_t *s, uint16_t target, uint8_t xmit);
    void                                (*transmit)(struct SamplerObj_t *s);
};

struct MotorState_t{
    float           iabc[3];
    float           vabc[3];
    float                vn;
    float              vbus;
    float            vab[2];
    float            iab[2];
    float            idq[2];
    float        idq_cmd[2];
    float        vdq_cmd[2];
    float        vab_cmd[2];
    float             theta;
    float                we;
    uint8_t            hall;
    float                x1;
    float                x2;
    float           obs_pos;
} motor_state;

#endif
