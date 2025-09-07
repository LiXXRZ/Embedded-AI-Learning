#ifndef __SENSER_H
#define __SENSER_H
void Senser_Init(void);
uint16_t Senser_Get(void);
void EXTI15_10_IRQHandler(void);
#endif
