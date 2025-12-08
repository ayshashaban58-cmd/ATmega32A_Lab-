#ifndef ADC_H_
#define ADC_H_

#include "../../Utils/STD_TYPES.h"

#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7

void ADC_voidInit(void);
uint16_t ADC_u16ReadChannel(uint8_t Copy_u8Channel);

#endif
