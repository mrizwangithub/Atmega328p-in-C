/*
Pin change interrupt handling with detecting the pin that 
triggered interrupt and with safety to ensure that signal that immediately follows 
when button is released after first press is ignored and not proccessed as if it was 
an intended change
*/

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define mySREG *((volatile uint8_t *)0x5F)
#define myPCICR *((volatile uint8_t *)0x68)
#define myPCMSK2 *((volatile uint8_t *)0x6D)
#define myDDRB *((volatile uint8_t *)0x24)

volatile uint8_t portdhistory = 0x00; // default is low because the pull-down

volatile uint8_t portDfirstSignalProcessed = 0x00;

int main(void)
{
    mySREG |= (1 << 7); // Set global interrupt enable bit

    myPCICR |= (1 << 2); // Enable Port D for PCI

    myPCMSK2 |= (1 << 4); // Enable pin 5 of Port D for interrupt signal

    myDDRB |= (1 << 5); // Set pin 13/pb5 as output. (Builtin LED)

    for (;;)
    {
    }
}

ISR(PCINT2_vect)
{
    uint8_t changedbits;

    changedbits = PIND ^ portdhistory;
    portdhistory = PIND;

    if (changedbits & (1 << PD0)) /* PCINT0 changed */
    {
    }

    if (changedbits & (1 << PD1)) /* PCINT1 changed */
    {
    }

    if (changedbits & (1 << PD2)) /* PCINT2 changed */
    {
    }

    if (changedbits & (1 << PD3)) /* PCINT3 changed */
    {
    }

    if (changedbits & (1 << PD4)) /* PCINT4 changed */
    {
        if (portDfirstSignalProcessed & (1 << PD4)) // Check to ignore the following pin signal change that comes immediately with button release after the first press.
        {
            portDfirstSignalProcessed &= ~(1 << PD4); // Make sure to unset the flag so later if I intentionally send another pin change signal/press down button, that is not ignored by the check above. 
            return;
        }

        PORTB ^= (1 << 5);

        portDfirstSignalProcessed |= (1 << PD4); // Set the flag in custom variable to track that first(button press down) signal change is processed. 
    }

    if (changedbits & (1 << PD5)) /* PCINT5 changed */
    {
    }

    if (changedbits & (1 << PD6)) /* PCINT6 changed */
    {
    }

    if (changedbits & (1 << PD7)) /* PCINT7 changed */
    {
    }
}