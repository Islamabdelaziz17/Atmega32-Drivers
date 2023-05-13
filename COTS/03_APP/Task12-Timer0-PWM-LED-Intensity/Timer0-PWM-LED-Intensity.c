/*
* Timer0-PWM-LED-INTENSITY.c
*
* Created: 2/28/2023 11:54:34 AM
* Author : ?slam
*/

#include "Timer.h"
#include "LED.h"
#include "SWITCH.h"
#include <util/delay.h>


void Notify(void)
{
	static u8 counter = 0;
	u8 SwitchInc_value = 1;
	u8 SwitchDec_value = 1;

	_delay_ms(150);
	SWITCH_enuGetSwitchValue(0,&SwitchInc_value);
	SWITCH_enuGetSwitchValue(1,&SwitchDec_value);
	if(SwitchInc_value == 0)
	{
		if(counter >= 255)
		{
			counter = 255;
		}
		else
		{
			counter++;
		}
		TMR0_SetCompareValue(counter);
	}
	if(SwitchDec_value == 0)
	{
		if(counter <= 0)
		{
			counter = 0;
		}
		else
		{
			counter--;
		}
		TMR0_SetCompareValue(counter);
	}
	
	
}

int main(void)
{
	TMR02Config_t Timer0Cfg;
	DIO_enuInit();
	Timer0Cfg.Mode = TMR02_MODE_FPWM_CLEAR;
	Timer0Cfg.Clock_Cfg = TMR02_CLK_ON;
	TMR0_vidInitPostCompile(&Timer0Cfg);
	TMR0_SetCompareValue(0);
	
	while (1)
	{
		Notify();
	}
}

