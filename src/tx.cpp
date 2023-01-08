// Transmitter operation in Atmega328P
// This program starts/stops a Serial Tx session on external interrupts

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#define BAUD 9600
#define F_CPU 16000000UL
#define UBRR_VALUE ((F_CPU / 16 / BAUD) - 1)

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile bool isSet = false;

void Config_USART(void)
{
    // UBRR is a 16 bits register
    UBRR0L = (unsigned char)UBRR_VALUE;        // Setting UBRR0 lower byte
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8); // Setting UBRR0 upper byte

    UCSR0B |= (1 << TXEN0);                  // Enable transmitter
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Seting 8 bit data
}

void USART_Transmit(unsigned char data)
{
    // While UDRE0 is 0 it will wait

    while (!(UCSR0A & (1 << UDRE0))); // Checks whether tx buffer is ready to receive data to transmit

    UDR0 = data;
}

void Config_Ext_Int(void){
    SREG |= (1 << 7);
    EICRA |= (1 << 1) | 1;
    EIMSK |= 1;
    DDRB |= (1 << 5);
    PORTB &= ~(1 << 5);
}

int main(void)
{
    Config_Ext_Int();
    Config_USART();

    int x = 0;

    for (;;)
    {
        if(isSet){
            USART_Transmit(0x30 + x % 10); // 0x30 is to offset to 0 with reference to ASCII table
            x++;

            _delay_ms(100);
        }
    }
}

ISR(INT0_vect){
    isSet = !isSet;
    PORTB ^= (1 << 5); // Toggles the bit.
 }
