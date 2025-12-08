#include "../Drivers/UART/UART.h"
#include "../Drivers/DIO/DIO.h"
#include <util/delay.h>

int main(void)
{
    UART_voidInit();
    DIO_voidSetPortDirection(DIO_PORTB, 0xFF);

    UART_voidSendString("UART Ready!\r\n");

    while(1)
    {
        uint8_t received = UART_u8ReceiveChar();

        if(received == '1') DIO_voidSetPortValue(DIO_PORTB, 0xFF);
        if(received == '0') DIO_voidSetPortValue(DIO_PORTB, 0x00);

        UART_voidSendChar(received);     // Echo
        UART_voidSendString("\r\n");
    }
}
