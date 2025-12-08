/*
    Experiment 4.2 - Input Switches Control LEDs
    Switches: PD0-PD3 (Active Low + Internal Pull-up)
    LEDs: PB0-PB3
    Author: Aysha Shaban Galal
*/

#include "../Drivers/DIO/DIO.h"
#include <util/delay.h>

int main(void)
{
    // LEDs Output
    DIO_voidSetPortDirection(DIO_PORTB, 0xFF);

    // Switches Input + Pull-up
    for(uint8_t i = 0; i < 4; i++)
    {
        DIO_voidSetPinDirection(DIO_PORTD, i, DIO_INPUT);
        DIO_voidSetPinValue(DIO_PORTD, i, DIO_HIGH);   // Enable Pull-up
    }

    while(1)
    {
        uint8_t switches_state = 0;
        for(uint8_t i = 0; i < 4; i++)
        {
            if(DIO_u8GetPinValue(DIO_PORTD, i) == DIO_LOW)  // Pressed
                switches_state |= (1 << i);
        }
        DIO_voidSetPortValue(DIO_PORTB, switches_state);
        _delay_ms(50);  // Simple debounce
    }
}
