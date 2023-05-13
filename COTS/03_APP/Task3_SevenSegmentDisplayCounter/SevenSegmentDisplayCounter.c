/*
 * SevenSegmentDisplayCounter.c
 *
 * Created: 1/20/2023 2:50:07 PM
 * Author : Islam
 */ 
#define F_CPU 8000000UL

#include "..\..\01_HAL\SSEG\SSEG.h"
#include "..\..\01_HAL\SSEG\SSEG_Cfg.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   
	SSEG_tenuErrorStatus Local_enuSSEGE1rrorStatus,Local_enuSSEGE2rrorStatus,Local_enuInitErrorStatus;
	u8 Local_u8DisplayedCounter;
	//Initialize Pins Of the MCU
	Local_enuInitErrorStatus = SSEG_enunInit();
    while (1) 
    {
		//Display the Counter On the dSeven Segments Display
		for(int Local_u8DisplayedCounter=0;Local_u8DisplayedCounter<SSEG_MAX_DISPLAYED_NUM;Local_u8DisplayedCounter++)
		{
			Local_enuSSEGE1rrorStatus = SSEG_enuDisplay((Local_u8DisplayedCounter%10),1);
			Local_enuSSEGE2rrorStatus = SSEG_enuDisplay((Local_u8DisplayedCounter/10),0);
			/*Wait Before Clearing*/
			_delay_ms(1000);
			/*Clear the display*/
			SSEG_enuClearDisplay(1);
			SSEG_enuClearDisplay(0);
		
		}
		
    }
}

