
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "uart_functions.h"

//NOTE: RXD0 is PORT E bit 0
//      TXD0 is PORT E bit 1

uint8_t i;

int main() {

uart_init();

while(1) {

    for(i = 0; i < 255; i++) {
        UDR0 = i;
        _delay_ms(100);
    }
    i = 0;

}
}//main


