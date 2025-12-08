#include "UART.h"
#include <avr/io.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VALUE ((F_CPU/(16UL*BAUD))-1)

void UART_voidInit(void)
{
    // Baud rate
    UBRRH = (uint8_t)(UBRR_VALUE >> 8);
    UBRRL = (uint8_t)UBRR_VALUE;

    // Enable TX & RX
    UCSRB = (1<<TXEN) | (1<<RXEN);

    // 8-bit data, 1 stop bit, no parity
    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
}

void UART_voidSendChar(uint8_t Copy_u8Data)
{
    while(!(UCSRA & (1<<UDRE)));
    UDR = Copy_u8Data;
}

void UART_voidSendString(const char* Copy_pcString)
{
    while(*Copy_pcString)
        UART_voidSendChar(*Copy_pcString++);
}

uint8_t UART_u8ReceiveChar(void)
{
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}

void UART_voidSendNumber(uint32_t Copy_u32Number)
{
    char buff[11];
    sprintf(buff, "%lu", Copy_u32Number);
    UART_voidSendString(buff);
}
