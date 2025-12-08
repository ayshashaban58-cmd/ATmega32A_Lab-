#include "KEYPAD.h"
#include "../DIO/DIO.h"
#include <util/delay.h>

static const uint8_t KPD_Values[4][4] = KPD_ARR;

void KEYPAD_voidInit(void)
{
    // Rows → Output (PD4-PD7)
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN4, DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN5, DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN6, DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN7, DIO_OUTPUT);

    // Columns → Input Pull-up (PD0-PD3)
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN0, DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN1, DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN2, DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT, DIO_PIN3, DIO_INPUT);

    DIO_voidSetPortValue(KEYPAD_PORT, 0xFF); // Pull-up on columns + rows high
}

uint8_t KEYPAD_u8GetPressedKey(void)
{
    uint8_t Local_u8Row, Local_u8Col;

    for(Local_u8Row = 0; Local_u8Row < 4; Local_u8Row++)
    {
        DIO_voidSetPinValue(KEYPAD_PORT, Local_u8Row + 4, DIO_LOW); // Activate row

        for(Local_u8Col = 0; Local_u8Col < 4; Local_u8Col++)
        {
            if(DIO_u8GetPinValue(KEYPAD_PORT, Local_u8Col) == DIO_LOW)
            {
                _delay_ms(20); // Debounce
                while(DIO_u8GetPinValue(KEYPAD_PORT, Local_u8Col) == DIO_LOW);
                DIO_voidSetPinValue(KEYPAD_PORT, Local_u8Row + 4, DIO_HIGH);
                return KPD_Values[Local_u8Row][Local_u8Col];
            }
        }
        DIO_voidSetPinValue(KEYPAD_PORT, Local_u8Row + 4, DIO_HIGH); // Deactivate row
    }
    return 0xFF; // No key pressed
}
