#ifndef LCD_H_
#define LCD_H_

void LCD_voidInit(void);
void LCD_voidSendCommand(uint8_t Copy_u8Cmd);
void LCD_voidSendChar(uint8_t Copy_u8Char);
void LCD_voidSendString(const char *Copy_pcString);
void LCD_voidClear(void);
void LCD_voidGoToXY(uint8_t Copy_u8Row, uint8_t Copy_u8Col);
void LCD_voidWriteNumber(uint32_t Copy_u32Number);

#endif
