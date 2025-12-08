#include "ADC.h"
#include <avr/io.h>

void ADC_voidInit(void)
{
    // AVCC with external capacitor at AREF pin
    ADMUX  = (1<<REFS0);
    // ADC Enable + Prescaler 128 → 125kHz @ 16MHz
    ADCSRA = (1<<ADEN) | (7<<ADPS0);
}

uint16_t ADC_u16ReadChannel(uint8_t Copy_u8Channel)
{
    ADMUX = (ADMUX & 0xF8) | (Copy_u8Channel & 0x07);
    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC));
    return ADC;
}
