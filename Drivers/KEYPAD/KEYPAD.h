#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../Utils/STD_TYPES.h"

#define KEYPAD_PORT     DIO_PORTD


#define KPD_ARR         {{'1','2','3','A'},\
                         {'4','5','6','B'},\
                         {'7','8','9','C'},\
                         {'*','0','#','D'}}

void KEYPAD_voidInit(void);
uint8_t KEYPAD_u8GetPressedKey(void);

#endif
