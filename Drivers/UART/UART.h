#ifndef UART_H_
#define UART_H_

void UART_voidInit(void);
void UART_voidSendChar(uint8_t Copy_u8Data);
void UART_voidSendString(const char* Copy_pcString);
uint8_t UART_u8ReceiveChar(void);
void UART_voidSendNumber(uint32_t Copy_u32Number);

#endif
