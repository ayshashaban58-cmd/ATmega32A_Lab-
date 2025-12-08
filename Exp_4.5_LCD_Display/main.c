/*
    Experiment 4.5 - LCD 16x2 + LM35 Temperature Display
    Shows real-time temperature from LM35 on PA1
    Author: Aysha Shaban Galal
*/

#include "../Drivers/LCD/LCD.h"
#include "../Drivers/ADC/ADC.h"
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
    LCD_voidInit();
    ADC_voidInit();

    LCD_voidSendString("Aysha Shaban");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendString("Temp Monitor");
    _delay_ms(2000);
    LCD_voidClear();

    while(1)
    {
        uint16_t adc = ADC_u16ReadChannel(ADC_CHANNEL_1);
        float voltage = (adc * 5.0) / 1023.0;
        float temp = voltage * 100.0;

        char buffer[20];
        sprintf(buffer, "Temp: %.2f C", temp);

        LCD_voidGoToXY(0, 0);
        LCD_voidSendString(buffer);
        LCD_voidGoToXY(1, 0);
        LCD_voidSendString("ATmega32A Lab  ");

        _delay_ms(800);
    }
}
