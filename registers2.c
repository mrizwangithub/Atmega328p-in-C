/*
This file DOES NOT use any libraries provided with avr-gcc compiler.

Manipulating port to blink built in LED connected to Pin 13 which is internally controlled by PORT B.
PORTB is a set of pins controlled by a byte size (8bits) register having 
memory address 0x25. Memory addresses can be found in ATMega328p Datasheet section 13.4.

DDRB(Data direction register) at 0x24 is also a byte sized register dedicated to 
configure pins on PORTB either as input or output direction.
*/

#include <stdio.h>

#define myPORTB *((volatile uint8_t*) 0x25)  // Memory address of port b. Same as PORTB in io.h library
#define myPORTB_DIRECTION_REGISTER *((volatile uint8_t*) 0x24)

#define SixthBitHigh_Binary 0b00100000 // Binary which will set the 6th bit high from right and everything else low.

int main(void)
{
    myPORTB_DIRECTION_REGISTER = SixthBitHigh_Binary; //00100000 sets PB5 as output

    for(;;)
    {
        myPORTB = SixthBitHigh_Binary; // Same as PORTB = 32; Pin 13 Builtin LED 
        for(long i = 0; i < 100000; i++) {myPORTB = SixthBitHigh_Binary;} // Adding to cause delay artificiialy

        myPORTB = 0; // Same as PORTB = 0;
        for(long i = 0; i < 100000; i++) {myPORTB = 0;}

        myPORTB = SixthBitHigh_Binary;
        for(long i = 0; i < 100000; i++) {myPORTB = SixthBitHigh_Binary;}

        myPORTB = 0;
        for(long i = 0; i < 1000000; i++) {myPORTB = 0;}
    }
}