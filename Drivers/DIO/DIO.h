/*
    DIO.h
    Author : Aysha Shaban Galal
    Layer  : MCAL
    SWC    : DIO / GPIO
*/

#ifndef DIO_H_
#define DIO_H_

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"
#include <avr/io.h>

#define PORTA   (*(volatile uint8_t*)0x3B)
#define DDRA    (*(volatile uint8_t*)0x3A)
#define PINA    (*(volatile uint8_t*)0x39)

#define PORTB   (*(volatile uint8_t*)0x38)
#define DDRB    (*(volatile uint8_t*)0x37)
#define PINB    (*(volatile uint8_t*)0x36)

#define PORTC   (*(volatile uint8_t*)0x35)
#define DDRC    (*(volatile uint8_t*)0x34)
#define PINC    (*(volatile uint8_t*)0x33)

#define PORTD   (*(volatile uint8_t*)0x32)
#define DDRD    (*(volatile uint8_t*)0x31)
#define PIND    (*(volatile uint8_t*)0x30)

/* Port Numbers */
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

/* Pin Numbers */
#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7

/* Direction */
#define DIO_INPUT   0
#define DIO_OUTPUT  1

/* Value */
#define DIO_LOW     0
#define DIO_HIGH    1

/* APIs */
void DIO_voidSetPinDirection(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Dir);
void DIO_voidSetPinValue    (uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Value);
uint8_t DIO_u8GetPinValue   (uint8_t Copy_u8Port, uint8_t Copy_u8Pin);

void DIO_voidSetPortDirection(uint8_t Copy_u8Port, uint8_t Copy_u8Dir);
void DIO_voidSetPortValue    (uint8_t Copy_u8Port, uint8_t Copy_u8Value);
uint8_t DIO_u8GetPortValue   (uint8_t Copy_u8Port);

#endif
