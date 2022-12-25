#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000

int main(void){

    DDRB |= _BV(DDB5);

    TCNT1 = 65535 - (F_CPU/1024);

    TCCR1B = (1 << CS10) | (1 << CS12);

    TCCR1A = 0x00;

    TIMSK1 = (1 << TOIE1);

    sei();

    while (1)
    {
        ;;
    }
}

ISR(TIMER1_OVF_vect){
    PORTB ^= _BV(PORTB5);
    TCNT1 = 65535 - (F_CPU/1024);
}