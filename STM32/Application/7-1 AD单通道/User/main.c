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
		AD0 = AD_Getvalue(ADC_Channel_0);
		AD1 = AD_Getvalue(ADC_Channel_1);
		
		OLED_ShowNum(1, 5, AD0, 4);
		OLED_ShowNum(2, 5, AD1, 4);
		
		Delay_ms(100);
	}
}
