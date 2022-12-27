#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#define mySREG *((volatile uint8_t*) 0x5F)
#define myEIMSK *((volatile uint8_t*) 0x3D) 
#define myEICRA *((volatile uint8_t*) 0x69)
#define myDDRB *((volatile uint8_t*) 0x24)

int main(void){

    //sei(); // Enable global interrupt
    //SREG |= (1 << 7); // To enable global interrupt bit
    mySREG |= (1 << 7);

    // External Interrupt Control Register A
    //EICRA |= (1 << 1) | 1;
    myEICRA |= (1 << 1) | 1; // 00000011 To trigger interrupt om rising edge.

    // External Interrupt Mask Register. To configrue microcontroller to be ready to sense external interrupt as INT1 or INT0 
    //EIMSK |= 1; 
    myEIMSK |= 1; // To enable/setup to act on external interrupts on signal at INT0 (Pin 2) of port B.

    // Port B data direction register
    //DDRB |= (1 << 5);
    myDDRB |= (1 << 5); // Setup pin 13 or PortB pin 5 data direction as output.

    while (1) {;;}
}

ISR(INT0_vect){
    PORTB ^= (1 << 5); // Toggles the bit.
 }