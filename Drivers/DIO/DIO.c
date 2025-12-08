#include "DIO.h"

void DIO_voidSetPinDirection(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Dir)
{
    if (Copy_u8Pin > 7) return;

    switch(Copy_u8Port)
    {
        case DIO_PORTA:
            if(Copy_u8Dir == DIO_OUTPUT) SET_BIT(DDRA, Copy_u8Pin);
            else                         CLR_BIT(DDRA, Copy_u8Pin);
            break;
        case DIO_PORTB:
            if(Copy_u8Dir == DIO_OUTPUT) SET_BIT(DDRB, Copy_u8Pin);
            else                         CLR_BIT(DDRB, Copy_u8Pin);
            break;
        case DIO_PORTC:
            if(Copy_u8Dir == DIO_OUTPUT) SET_BIT(DDRC, Copy_u8Pin);
            else                         CLR_BIT(DDRC, Copy_u8Pin);
            break;
        case DIO_PORTD:
            if(Copy_u8Dir == DIO_OUTPUT) SET_BIT(DDRD, Copy_u8Pin);
            else                         CLR_BIT(DDRD, Copy_u8Pin);
            break;
    }
}

void DIO_voidSetPinValue(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Value)
{
    if (Copy_u8Pin > 7) return;

    switch(Copy_u8Port)
    {
        case DIO_PORTA:
            if(Copy_u8Value == DIO_HIGH) SET_BIT(PORTA, Copy_u8Pin);
            else                         CLR_BIT(PORTA, Copy_u8Pin);
            break;
        case DIO_PORTB:
            if(Copy_u8Value == DIO_HIGH) SET_BIT(PORTB, Copy_u8Pin);
            else                         CLR_BIT(PORTB, Copy_u8Pin);
            break;
        case DIO_PORTC:
            if(Copy_u8Value == DIO_HIGH) SET_BIT(PORTC, Copy_u8Pin);
            else                         CLR_BIT(PORTC, Copy_u8Pin);
            break;
        case DIO_PORTD:
            if(Copy_u8Value == DIO_HIGH) SET_BIT(PORTD, Copy_u8Pin);
            else                         CLR_BIT(PORTD, Copy_u8Pin);
            break;
    }
}

uint8_t DIO_u8GetPinValue(uint8_t Copy_u8Port, uint8_t Copy_u8Pin)
{
    if (Copy_u8Pin > 7) return 0;

    switch(Copy_u8Port)
    {
        case DIO_PORTA: return READ_BIT(PINA, Copy_u8Pin);
        case DIO_PORTB: return READ_BIT(PINB, Copy_u8Pin);
        case DIO_PORTC: return READ_BIT(PINC, Copy_u8Pin);
        case DIO_PORTD: return READ_BIT(PIND, Copy_u8Pin);
        default: return 0;
    }
}

void DIO_voidSetPortDirection(uint8_t Copy_u8Port, uint8_t Copy_u8Dir)
{
    switch(Copy_u8Port)
    {
        case DIO_PORTA: DDRA = Copy_u8Dir; break;
        case DIO_PORTB: DDRB = Copy_u8Dir; break;
        case DIO_PORTC: DDRC = Copy_u8Dir; break;
        case DIO_PORTD: DDRD = Copy_u8Dir; break;
    }
}

void DIO_voidSetPortValue(uint8_t Copy_u8Port, uint8_t Copy_u8Value)
{
    switch(Copy_u8Port)
    {
        case DIO_PORTA: PORTA = Copy_u8Value; break;
        case DIO_PORTB: PORTB = Copy_u8Value; break;
        case DIO_PORTC: PORTC = Copy_u8Value; break;
        case DIO_PORTD: PORTD = Copy_u8Value; break;
    }
}
