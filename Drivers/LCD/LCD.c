#include "LCD.h"
#include "../DIO/DIO.h"
#include <util/delay.h>
#include <stdio.h>

#define LCD_RS   DIO_PIN0
#define LCD_EN   DIO_PIN1
#define LCD_D4   DIO_PIN4
#define LCD_D5   DIO_PIN5
#define LCD_D6   DIO_PIN6
#define LCD_D7   DIO_PIN7

static void LCD_voidPulse(void)
{
    DIO_voidSetPinValue(DIO_PORTC, LCD_EN, DIO_HIGH);
    _delay_us(1);
    DIO_voidSetPinValue(DIO_PORTC, LCD_EN, DIO_LOW);
    _delay_us(100);
}

static void LCD_voidSend4Bits(uint8_t Copy_u8Data)
{
    DIO_voidSetPinValue(DIO_PORTC, LCD_D4, (Copy_u8Data >> 0) & 1);
    DIO_voidSetPinValue(DIO_PORTC, LCD_D5, (Copy_u8Data >> 1) & 1);
    DIO_voidSetPinValue(DIO_PORTC, LCD_D6, (Copy_u8Data >> 2) & 1);
    DIO_voidSetPinValue(DIO_PORTC, LCD_D7, (Copy_u8Data >> 3) & 1);
}

void LCD_voidSendCommand(uint8_t Copy_u8Cmd)
{
    DIO_voidSetPinValue(DIO_PORTC, LCD_RS, DIO_LOW);
    LCD_voidSend4Bits(Copy_u8Cmd >> 4);
    LCD_voidPulse();
    LCD_voidSend4Bits(Copy_u8Cmd);
    LCD_voidPulse();
}

void LCD_voidSendChar(uint8_t Copy_u8Char)
{
    DIO_voidSetPinValue(DIO_PORTC, LCD_RS, DIO_HIGH);
    LCD_voidSend4Bits(Copy_u8Char >> 4);
    LCD_voidPulse();
    LCD_voidSend4Bits(Copy_u8Char);
    LCD_voidPulse();
}

void LCD_voidInit(void)
{
    DIO_voidSetPinDirection(DIO_PORTC, LCD_RS, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTC, LCD_EN, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTC, LCD_D4, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTC, LCD_D5, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTC, LCD_D6, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTC, LCD_D7, DIO_OUTPUT);

    _delay_ms(40);
    LCD_voidSendCommand(0x33);
    LCD_voidSendCommand(0x32);
    LCD_voidSendCommand(0x28); // 4-bit mode
    LCD_voidSendCommand(0x0C); // Display on
    LCD_voidSendCommand(0x06); // Increment cursor
    LCD_voidSendCommand(0x01); // Clear
    _delay_ms(2);
}

void LCD_voidSendString(const char *Copy_pcString)
{
    while(*Copy_pcString)
        LCD_voidSendChar(*Copy_pcString++);
}

void LCD_voidClear(void)
{
    LCD_voidSendCommand(0x01);
    _delay_ms(2);
}

void LCD_voidGoToXY(uint8_t Copy_u8Row, uint8_t Copy_u8Col)
{
    uint8_t Local_u8Address = (Copy_u8Row == 0) ? (0x80 + Copy_u8Col) : (0xC0 + Copy_u8Col);
    LCD_voidSendCommand(Local_u8Address);
}

void LCD_voidWriteNumber(uint32_t Copy_u32Number)
{
    char buff[16];
    sprintf(buff, "%lu", Copy_u32Number);
    LCD_voidSendString(buff);
}
