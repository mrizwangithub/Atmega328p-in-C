/*
FOR acting on when signal goes low while its normally high.

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

#define mySREG *((volatile uint8_t *)0x5F)
#define myPCICR *((volatile uint8_t *)0x68)
#define myPCMSK2 *((volatile uint8_t *)0x6D)
#define myDDRB *((volatile uint8_t *)0x24)

volatile uint8_t portdhistory = 0xFF; // default 0xFF is high because the pull-up.

//volatile uint8_t portDintendedSignalProcessed =0;

int main(void)
{
	mySREG |= (1 << 7); // Set global interrupt enable bit

	myPCICR |= (1 << 2); // Enable Port D for PCI

	myPCMSK2 |= 0xFF; // Enable all pins of Port D for pin change interrupt signal

	myDDRB |= (1 << 5); // Set pin 13/pb5 as output. (Builtin LED)

	for (;;)
	{
		//portDintendedSignalProcessed = 0xFF;
	}
}

ISR(PCINT2_vect) // Port D pin change interrupt vector
{
	uint8_t changedbits = PIND ^ portdhistory;

	portdhistory = PIND;

	switch (changedbits ^ PIND) // For acting on change when signal goes low
	{
		case (1 << PORTD0):  /* PCINT0 changed */
		{
		}
		break;
		case (1 << PORTD1):  /* PCINT1 changed */
		{
		}
		break;
		case (1 << PORTD2):  /* PCINT2 changed */
		{
		}
		break;
		case (1 << PORTD3):  /* PCINT3 changed */
		{
		}
		break;
		case (1 << PORTD4):  /* PCINT4 changed */
		{
			PORTB ^= (1 << 5);
		}
		break;
		case (1 << PORTD5):  /* PCINT5 changed */
		{
		}
		break;
		case (1 << PORTD6):  /* PCINT6 changed */
		{
		}
		break;
		case (1 << PORTD7):  /* PCINT7 changed */
		{
		}
		break;
	}
}