
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart_functions.h"
#include <util/delay.h>




int main() {
DDRB = 0xFF;
    
uart1_init();

while(1) {

    //Send a value via UART
    uint8_t i;
    for(i = 0; i < 255; i++) {
        PORTB = 0x01;
        while (!(UCSR1A&(1<<UDRE1)));    // Wait for previous transmissions
            UDR1 = i;    // Send data byte
        while (!(UCSR1A&(1<<UDRE1)));    // Wait for previous transmissions
        _delay_ms(100);
        PORTB = 0x00;
    }//for

}//while
}//main
