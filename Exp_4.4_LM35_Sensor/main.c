/*
    Experiment 4.4 - LM35 Temperature Sensor on PA1
    Display temperature level on LEDs
    Author: Aysha Shaban Galal
*/

#include "../Drivers/DIO/DIO.h"
#include "../Drivers/ADC/ADC.h"
#include <util/delay.h>

int main(void)
{
    DIO_voidSetPortDirection(DIO_PORTB, 0xFF);
    ADC_voidInit();

    while(1)
    {
        uint16_t adc = ADC_u16ReadChannel(ADC_CHANNEL_1);  // PA1
        float voltage = (adc * 5.0) / 1023.0;
        float temp = voltage * 100.0;  // LM35: 10mV/°C

        uint8_t led_count = (uint8_t)(temp / 5);  // Every 5°C one LED
        if(led_count > 8) led_count = 8;

        uint8_t pattern = (1 << led_count) - 1;
        DIO_voidSetPortValue(DIO_PORTB, pattern);

        _delay_ms(500);
    }
}
