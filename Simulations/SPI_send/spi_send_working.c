#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


void SPI_init() {
	// set up SPI (slave mode, clk low on idle, leading edge sample)
	SPCR = (1 << SPE) | (0 << MSTR) | (0 << CPOL) | (0 << CPHA);
	SPSR = (1<<SPR1) | (1<<SPR0);
}//SPI_init


/******************************************************************************
* Function: SPI_send
* Parameters: message var holds int to be sent
* Return: none
* Description: Function will take in a message to send through SPI. It will 
*   write the data to the SPI data register and then wait for the message to 
*   send before returning.
*******************************************************************************/

void SPI_send(uint16_t message) {
   // PORTE &= ~(1 << PE5); // enable bar graph

    SPDR = message; // write message to SPI data register
    while(bit_is_clear(SPSR, SPIF)) {}  // wait for data to send

    //PORTE |= (1 << PE6);      // move data from shift to storage reg.
   // PORTE &= ~(1 << PE6);     // change 3-state back to high Z

    //PORTE |= (1 << PE5); // disable bar graph

}//SPI_send



int main() {

uint16_t i = 0;
DDRB = (1<<PB3);   //PORTB output for SPI
//PORTB |= (1<<PB0);

SPI_init();

while(1) {

    char lo = i & 0xFF;
    char hi = i >> 8;

    SPI_send(hi);
    SPI_send(lo);
    i++;
    _delay_ms(100);

}//while
return 0;
}//main
