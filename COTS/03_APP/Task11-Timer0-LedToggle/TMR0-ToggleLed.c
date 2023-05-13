/*
 * Timer0 Toogle led every 500ms.c
 *
 * Created: 3/10/2023 11:54:34 AM
 * Author : Islam
 */ 

#include "Timer.h"
#include "LED.h"
#include "Global_Interrupt.h"

u16 Global_TimerOvCounts = 0;

void Notify(void)
{
	static u8 Toggle_led_flag = 0x55;
	static u16 counter = 0;
	counter++;
	if(counter == Global_TimerOvCounts)
	{
		if(Toggle_led_flag == 0x55)
		{
			LED_enuLEDON(0);
			counter = 0;
			Toggle_led_flag = ~Toggle_led_flag;
		}
		else
		{
			LED_enuLEDOFF(0);
			counter = 0;
			Toggle_led_flag = ~Toggle_led_flag;
		}
		
	}
	else
	{
		/*Do Nothing*/
	}
	
}

int main(void)
{
	TMR02Config_t Timer0Cfg;
	DIO_enuInit();
	Global_Interrupt_voidEnable();
	TMR0_enuRegisterCallback_OV(Notify);
	TMR0_enuSetTickTimeMS(500, TMR02_CLK_PRES_0,&Global_TimerOvCounts);
	Timer0Cfg.Mode = TMR02_MODE_NORMAL;
	Timer0Cfg.Clock_Cfg = TMR02_CLK_ON;
	TMR0_vidInitPostCompile(&Timer0Cfg);
	
    while (1) 
    {
		/*Do Nothing*/
    }
}

