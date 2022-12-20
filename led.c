#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    //Set PORTB5 as output or Pin 13 which is connected to builtin LED
    DDRB |= (1 << DDB5);  // Same as DDRB = DDRB | (1 << DDB5);

    //forever
    for(;;)
    {
        // set portb5 high
        PORTB |= (1 << PORTB5); // Same as PORTB = PORTB | (1 << PORTB5);

        // wait
        _delay_ms(100);

        // unset portb5 low
        PORTB &= ~(1 << PORTB5); // Same as PORTB = PORTB & ~(1 << PORTB5);

        //wait
        _delay_ms(100);

        // set portb5 bit
        PORTB |= (1 << PORTB5); // Same as PORTB = PORTB | (1 << PORTB5);

        // wait
        _delay_ms(100);

        // unset portb5 low
        PORTB &= ~(1 << PORTB5); // Same as PORTB = PORTB & ~(1 << PORTB5);

        //wait
        _delay_ms(1000);
    }
}