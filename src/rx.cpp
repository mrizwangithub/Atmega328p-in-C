// Receiver operation in Atmega328P

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#define BAUD 9600
#define F_CPU 16000000UL
#define UBRR_VALUE ((F_CPU / 16 / BAUD) - 1)

#include <avr/io.h>

void Config_USART(void)
{
    // UBRR is a 16 bits register
    UBRR0L = (unsigned char)UBRR_VALUE;        // Setting UBRR0 lower byte
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8); // Setting UBRR0 upper byte

    UCSR0B |= (1 << TXEN0);                  // Enable transmitter
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Seting 8 bit data
}

unsigned char USART_Receive()
{
    // Wait for data to be received

    while (!(UCSR0A & (1 << RXC0))); // Checks whether rx buffer is ready to be read.

    return UDR0;
}

void USART_Transmit(unsigned char data)
{
    // While UDRE0 is 0 it will wait

    while (!(UCSR0A & (1 << UDRE0)))
        ; // Checks whether tx buffer is ready to receive data to transmit

    UDR0 = data;
}

int main(void)
{
    Config_USART();

    unsigned char rx = 0x00;
    DDRB |= (1 << 5);

    for (;;)
    {
        rx = USART_Receive();
        // if(rx != 0x00)
        // {
        //     PORTB ^= (1 << 5);
        // }
        USART_Transmit(rx);
    }
}
