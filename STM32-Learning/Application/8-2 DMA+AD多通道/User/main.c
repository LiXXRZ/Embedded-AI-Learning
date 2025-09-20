#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t AD0, AD1;

int main (void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "AD0:");
	OLED_ShowString(2, 1, "AD1:");

	while(1)
	{
		
		OLED_ShowNum(1, 5, advalue[0], 4);
		OLED_ShowNum(2, 5, advalue[1], 4);
		
		Delay_ms(100);
	}
}
