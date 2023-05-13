/*
 * SevenSegmentPushButton.c
 *
 * Created: 1/20/2023 2:50:07 PM
 * Author : Islam
 */ 
#define F_CPU 8000000UL

#include "SSEG.h"
#include "SSEG_Cfg.h"
#include "..\..\..\01_HAL\SWITCH_DRIVER\SWITCH\SWITCH.h"
#include "..\..\..\01_HAL\SWITCH_DRIVER\SWITCH\SWITCH_Cfg.h"
#include <util/delay.h>

int main(void)
{
   
	SSEG_tenuErrorStatus Local_enuSSEGE1rrorStatus,Local_enuSSEGE2rrorStatus,Local_enuInitErrorStatus;
	SSEG_tenuErrorStatus Local_enuWSITCHErrorstat;
	u8 Local_u8SwitchValue = 0;
	//Initialize Pins Of the MCU
	Local_enuInitErrorStatus = SSEG_enunInit();
	u8 Local_u8DisplayedCounter = 0;
    while (1) 
    {
		//Delay for Debouncing Problem
		_delay_ms(150);
		//Get Pin Value Of the PushButton
		Local_enuWSITCHErrorstat = SWITCH_enuGetSwitchValue(0,&Local_u8SwitchValue);
		//Check If Pressed Or Not
		if(Local_u8SwitchValue == SWITCH_enuPressed)
		{
			//Clear 7-segments display
			SSEG_enuClearDisplay(1);
			SSEG_enuClearDisplay(0);
			
			if(SWITCH_strPinCfg[0].SWITCH_TO_DO == SWITCH_enuIncreament)
			{
				//Display the Counter On the displays
				Local_enuSSEGE1rrorStatus = SSEG_enuDisplay((Local_u8DisplayedCounter%10),1);
				Local_enuSSEGE2rrorStatus = SSEG_enuDisplay((Local_u8DisplayedCounter/10),0);
			}
			//Increament the counter value
			Local_u8DisplayedCounter++;
			//Verify Configuered maximum number to be displayed on the 7-segments
			if(Local_u8DisplayedCounter > SSEG_MAX_DISPLAYED_NUM)
			{
				Local_u8DisplayedCounter=0;
			}
		}
	

		
		
		
    }
}

