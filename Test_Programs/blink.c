/***************************************************
 * Blink tester program. The first program to go 
 * onto our senior design uC!!
 * ************************************************/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int main() {

DDRB |= (1 << PB0); //PORTB.0 output

    while(1) {
        PORTB ^= (1 << PB0);
        _delay_ms(500);
    }

return 0;
}//main
