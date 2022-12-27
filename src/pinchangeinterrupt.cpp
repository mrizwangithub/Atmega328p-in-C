#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#define mySREG *((volatile uint8_t*) 0x5F)
#define myPCICR *((volatile uint8_t*) 0x68) 
#define myPCMSK2 *((volatile uint8_t*) 0x6D)
#define myDDRB *((volatile uint8_t*) 0x24)

volatile bool isProcessed = false;

int main(void){

    mySREG |= (1 << 7);

    myPCICR |= (1 << 2); // Enable Port D for PCI
    
    myPCMSK2 |= (1 << 4); // Enable pin 5 of Port B for interrupt signal
    
    myDDRB |= (1 << 5);

    while (1)
    {}
}

ISR(PCINT2_vect){
    
    if(isProcessed){
        isProcessed = !isProcessed;
        return;
    }

    PORTB ^= (1 << 5);
    isProcessed = true;
}