/*
 * PushButton_Led_Inc_Dec.c
 *
 * Created: 1/18/2023 3:22:31 PM
 * Author : Islam
 */ 
#define F_CPU 8000000UL
#include "SWITCH.h"
#include "SWITCH_Cfg.h"
#include "..\..\..\01_HAL\LED_DRIVER\LED\LED.h"
#include "..\..\..\01_HAL\LED_DRIVER\LED\LED_Cfg.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	static u8 Local_u8LedsOnCounter = 0;    
	volatile u8 Local_pu8SwitchValue;
	u8 Local_u8Counter = 0;
	SWITCH_tenuErrorStatus Local_enuSwitchErrorstat ;
	//Initializing DIO TARGET PINS FIRST OUT/IN
	DIO_tenuErrorStatus InitStatus = DIO_enuInit();
    while(1) 
    {
		for(Local_u8Counter = 0;Local_u8Counter<NUMBER_OF_SWITCHES;Local_u8Counter++)
		{
		    _delay_ms(120);
		 	Local_enuSwitchErrorstat = SWITCH_enuGetSwitchValue(Local_u8Counter,&Local_pu8SwitchValue);

			//LED_enuLEDON(Local_u8LedsOnCounter);
			if(Local_pu8SwitchValue == SWITCH_enuPressed)
			{
				if(SWITCH_strPinCfg[Local_u8Counter].SWITCH_TO_DO == SWITCH_enuIncreament)
				{
					LED_enuLEDON(Local_u8LedsOnCounter);
					Local_u8LedsOnCounter++;
					Local_u8LedsOnCounter%=NUMBER_OF_LEDS;
				}
				else if(SWITCH_strPinCfg[Local_u8Counter].SWITCH_TO_DO == SWITCH_enuDecreament)
				{
					//LED_enuLEDON(Local_u8LedsOnCounter);
					LED_enuLEDOFF(Local_u8LedsOnCounter);
					Local_u8LedsOnCounter--;
					Local_u8LedsOnCounter%=NUMBER_OF_LEDS;
				}

			}
			
		}
		
    }
}

