/*
    Experiment 4.1 - Toggle LEDs
    LEDs connected to PORTB (Active High)
    Author: Aysha Shaban Galal
*/

#include "../Drivers/DIO/DIO.h"
#include <util/delay.h>

int main(void)
{
    DIO_voidSetPortDirection(DIO_PORTB, 0xFF);  // All PORTB Output

    while(1)
    {
        DIO_voidSetPortValue(DIO_PORTB, 0xFF);  // All LEDs ON
        _delay_ms(500);
        DIO_voidSetPortValue(DIO_PORTB, 0x00);  // All LEDs OFF
        _delay_ms(500);
    }
}
