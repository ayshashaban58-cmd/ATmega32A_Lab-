#include "TIMER.h"
#include "../DIO/DIO.h"
#include <avr/io.h>

void TIMER1_voidInit_PWM(void)
{
    // OC1A (PD5) as output
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

    // Fast PWM Mode 14 (TOP = ICR1)
    TCCR1A = (1<<WGM11) | (1<<COM1A1);
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS11); // Prescaler 8

    ICR1 = 2499;   // Default 1kHz @ 16MHz/8
}

void TIMER1_voidSetFrequency(uint16_t Copy_u16Freq_Hz)
{
    ICR1 = (1000000UL / Copy_u16Freq_Hz) - 1;   // 8MHz / 8 = 1MHz
}

void TIMER1_voidSetDutyCycle(uint8_t Copy_u8Duty)
{
    if(Copy_u8Duty > 100) Copy_u8Duty = 100;
    OCR1A = (ICR1 * Copy_u8Duty) / 100;
}
