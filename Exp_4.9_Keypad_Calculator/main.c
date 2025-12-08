#include "../Drivers/KEYPAD/KEYPAD.h"
#include "../Drivers/LCD/LCD.h"
#include <util/delay.h>

uint8_t num1 = 0, num2 = 0, op = 0;
uint8_t current = 0;

int main(void)
{
    KEYPAD_voidInit();
    LCD_voidInit();
    LCD_voidSendString("Simple Calc");

    while(1)
    {
        uint8_t key = KEYPAD_u8GetPressedKey();

        if(key != 0xFF)
        {
            LCD_voidGoToXY(1,0);
            if(key >= '0' && key <= '9')
            {
                if(op == 0)
                {
                    num1 = num1 * 10 + (key - '0');
                    LCD_voidSendChar(key);
                }
                else
                {
                    num2 = num2 * 10 + (key - '0');
                    LCD_voidSendChar(key);
                }
            }
            else if(key == '+' || key == '-' || key == '*' || key == '/')
            {
                op = key;
                LCD_voidSendChar(key);
            }
            else if(key == '=')
            {
                uint32_t result = 0;
                switch(op)
                {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/': if(num2!=0) result = num1 / num2; break;
                }
                LCD_voidClear();
                LCD_voidSendString("Result:");
                LCD_voidWriteNumber(result);
                num1 = num2 = op = 0;
            }
            else if(key == 'C')
            {
                LCD_voidClear();
                LCD_voidSendString("Simple Calc");
                num1 = num2 = op = 0;
            }
            _delay_ms(300);
        }
    }
}
