#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void){

  DDRB = 0b00000011; // Sets PB0 and PB1 to outputs

  while(1){

    PORTB = 0b00000001; // Turns on only PB0
    _delay_ms(2000); // Delays 2000ms (2s)

    PORTB = 0b00000010; // Turns on only PB1
    _delay_ms(2000); // Delays 2000ms (2s)

     PORTB = 0b00000001; // Turns on only PB0
    _delay_ms(1000); // Delays 1000ms (1s)

    PORTB = 0b00000010; // Turns on only PB1
    _delay_ms(1000); // Delays 1000ms (1s)

     PORTB = 0b00000001; // Turns on only PB0
    _delay_ms(500); // Delays 500ms (0.5s)

    PORTB = 0b00000010; // Turns on only PB1
    _delay_ms(500); // Delays 500ms (0.5s)
    
  }
  return(0);
}