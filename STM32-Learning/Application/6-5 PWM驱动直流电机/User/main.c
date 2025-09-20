#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"

uint16_t Num;
int8_t Speed;

int main (void)
{
	Motor_Init();
	Key_Init();
	OLED_Init();
	OLED_ShowString(1, 1, "Speed:");
	Motor_SetSpeed(0);
	
	while(1)
	{
		Num = Key_GetNum();
		
		if(Num == 1)
		{
			Speed += 20;
			if(Speed > 100)
			{
				Speed = -100;
			}
		}
		
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1, 7, Speed, 3);
	}
}
