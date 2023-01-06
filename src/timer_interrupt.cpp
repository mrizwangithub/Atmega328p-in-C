#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){

    // Initialize the timer interrupt 1
    TIMSK1 |= 0b00000010;

    // Compare mode setting 
    TCCR1A &= 0b11111100;

    // Pre-scalar setting
    TCCR1B |= 0b00001000;
    TCCR1B &= 0b11101111;
    TCCR1B |= 0b00000100;
    TCCR1B &= 0b11111100;

    OCR1AH = 0xF4l;
    OCR1AL = 0x24;

    TCNT1H = 0x00; 
    TCNT1L = 0x00; 

    sei();

    DDRB |= (1 << 5);

    for(;;){}
}

ISR(TIMER1_COMPA_vect){
    PORTB ^= (1 << 5);
}