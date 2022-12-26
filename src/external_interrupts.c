#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

// #define mySREG *((volatile uint8_t*) 0x5F)
// #define myExtIntReg *((volatile uint8_t*) 0x3D) 
// #define myExtIntControlReg *((volatile uint8_t*) 0x69)

volatile int toggle = 0;

int main(void){

    sei(); // Enable global interrupt
    
    //External Interrupt Control Register A
    EICRA |= 0B00000011; // Rising edge configure. EICRA Mem address = 0x69

    // External Interrupt Mask Register. To configrue microcontroller to be ready to sense external interrupt as INT1 or INT0 
    EIMSK |= 0B00000001; // INT1 . EIMSK Address = 0x3D

    DDRB |= 0B11111111;

    while (1) {;;}
}

 ISR(INT0_vect){

    if(toggle)
    {
        PORTB |= 0B00100000;
    }
    else{
        PORTB &= 0B11011111;
    }

    toggle = 1 - toggle;
 }