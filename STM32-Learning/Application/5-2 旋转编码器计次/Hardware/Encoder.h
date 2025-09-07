#ifndef __ENCODER_H
#define __ENCODER_H
int16_t Encoder_Get(void);
void Encoder_Init(void);
void EXTI1_IRQHandler(void);
void EXTI0_IRQHandler(void);
#endif
