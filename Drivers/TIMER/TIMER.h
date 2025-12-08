#ifndef TIMER_H_
#define TIMER_H_

void TIMER1_voidInit_PWM(void);
void TIMER1_voidSetFrequency(uint16_t Copy_u16Freq_Hz);
void TIMER1_voidSetDutyCycle(uint8_t Copy_u8Duty); // 0-100%

#endif
