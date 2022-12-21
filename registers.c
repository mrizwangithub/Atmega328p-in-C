/*
This file uses libraries provided with avr-gcc compiler.

Manipulating port to blink built in LED connected to Pin 13 which is internally controlled by PORT B.
PORTB is a set of pins controlled by a byte size (8bits) register having 
memory address 0x25. Memory addresses can be found in ATMega328p Datasheet section 13.4.

DDRB(Data direction register) at 0x24 is also a byte sized register dedicated to 
configure pins on PORTB either as input or output direction.
*/

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void){

    // setup
    DDRB = 32; //32 in decimal translates to 00100000 in binary which will set the 6th bit from right (in direction register) to high that will eventually treat the 6th bit from right(Pin 13 on UNO) in PORTB as output 

    volatile  uint8_t* pointerToPortB = (uint8_t*)0x25; // Memory address of port b
    
    //forever
    for(;;)
    {
        PORTB = 32; //Same as *pointerToPortB = 32;  

        _delay_ms(150);

        PORTB = 0; // Same as *pointerToPortB = 0;

        _delay_ms(100);

        PORTB = 32;

        _delay_ms(150);

        PORTB = 0;

        _delay_ms(1000);
    }
}