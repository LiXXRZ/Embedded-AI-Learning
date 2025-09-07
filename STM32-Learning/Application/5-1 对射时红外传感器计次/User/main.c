#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Senser.h"

uint8_t KeyNum;

int main (void)
{
	OLED_Init();
	Senser_Init();
	
	OLED_ShowString(1, 1, "Count:");
	
	while(1)
	{
		OLED_ShowNum(1, 7, Senser_Get(), 5);
	}
}
