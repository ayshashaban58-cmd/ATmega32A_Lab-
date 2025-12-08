#include "../Drivers/TIMER/TIMER.h"
#include <util/delay.h>

int main(void)
{
    TIMER1_voidInit_PWM();

    while(1)
    {
        TIMER1_voidSetFrequency(523); // C5 note
        TIMER1_voidSetDutyCycle(50);
        _delay_ms(500);

        TIMER1_voidSetFrequency(587); // D5
        _delay_ms(500);

        TIMER1_voidSetFrequency(659); // E5
        _delay_ms(500);

        TIMER1_voidSetDutyCycle(0);   // Silence
        _delay_ms(1000);
    }
}
