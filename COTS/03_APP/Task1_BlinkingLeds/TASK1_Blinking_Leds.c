/*
 * Task1_Blinking_leds.c
 *
 * Created: 1/18/2023 11:39:48 AM
 * Author : Islam
 */ 

#define F_CPU 8000000UL
#include "..\..\01_HAL\LED\LED.h"
#include "..\..\01_HAL\LED\LED_Cfg.h"
#include "..\..\..\LIB\Std_Types.h"
#include <util/delay.h>

int main(void)
{
	//Led Number Counter
    u8 Local_u8ledcounter = 0;
	/*LOOPING ON EACH LED TO SET IT TON HEN AFTER 100MS SET IT OFF AGAIN (ASCENDINGLY) & WHEN THE FIRST CYCLE FINISHES BLINK BACK ON THEN OFF (DESCENDINGLY)*/
    while (1) 
    {
		for(Local_u8ledcounter=0;Local_u8ledcounter<NUMBER_OF_LEDS;Local_u8ledcounter++)
		{
			//Seting the led status ON
			LED_enuLEDON(Local_u8ledcounter);
			//Led stays on for 100ms 
			_delay_ms(100);
			//Seting the led status OFF
			LED_enuLEDOFF(Local_u8ledcounter);
		}
		for(Local_u8ledcounter=NUMBER_OF_LEDS-1;Local_u8ledcounter>=0;Local_u8ledcounter--)
		{
			//Seting the led status ON
			LED_enuLEDON(Local_u8ledcounter);
			//Led stays on for 100ms 
			_delay_ms(100);
			//Seting the led status OFF
			LED_enuLEDOFF(Local_u8ledcounter);
		}
		
    }
}

