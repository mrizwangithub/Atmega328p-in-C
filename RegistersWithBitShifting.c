#include <stdio.h>

#define myPORTB *((volatile uint8_t*) 0x25)  // Memory address of port b. Same as PORTB in io.h library
#define myPORTB_DIRECTION_REGISTER *((volatile uint8_t*) 0x24) // Memory address of PORTB pin's direction register

int main(void)
{
    myPORTB_DIRECTION_REGISTER |= (1 << 5);

    for(;;)
    {
        myPORTB |= (1 << 5);
        for(long i = 0; i < 200000; i++) {myPORTB |= (1 << 5);}

        myPORTB &= ~(1 << 5); // Same as PORTB = 0;
        for(long i = 0; i < 200000; i++) {myPORTB &= ~(1 << 5);}

        myPORTB |= (1 << 5);
        for(long i = 0; i < 200000; i++) {myPORTB |= (1 << 5);}

        myPORTB &= ~(1 << 5);
        for(long i = 0; i < 1000000; i++) {myPORTB &= ~(1 << 5);}
    }
}