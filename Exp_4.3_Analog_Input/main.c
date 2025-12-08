/*
    Experiment 4.3 - Analog Input (Potentiometer on PA0)
    Show value on 8 LEDs (Bargraph style)
    Author: Aysha Shaban Galal
*/

#include "../Drivers/DIO/DIO.h"
#include "../Drivers/ADC/ADC.h"
#include <util/delay.h>

int main(void)
{
    DIO_voidSetPortDirection(DIO_PORTB, 0xFF);  // LEDs Output
    ADC_voidInit();

    while(1)
    {
        uint16_t adc_value = ADC_u16ReadChannel(ADC_CHANNEL_0);  // PA0
        uint8_t led_level = adc_value / 128;   // 1023 / 128 = 8 levels (0-7)
        if(led_level > 7) led_level = 7;

        uint8_t pattern = (1 << (led_level + 1)) - 1;  // 00000001, 00000011, etc.
        DIO_voidSetPortValue(DIO_PORTB, pattern);

        _delay_ms(100);
    }
}
