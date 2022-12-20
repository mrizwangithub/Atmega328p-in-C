#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRB = 32; //00100000 sets PB5 as output

    for(;;)
    {
        volatile  uint8_t* pointerToPortB = (uint8_t*)0x25; // Memory address of port b

        *pointerToPortB = 32; // Same as PORTB = 32;

        for(long i = 0; i < 100000; i++) {PORTB = 32;}

        *pointerToPortB = 0; // Same as PORTB = 0;

        for(long i = 0; i < 100000; i++) {PORTB = 0;}
    }
}