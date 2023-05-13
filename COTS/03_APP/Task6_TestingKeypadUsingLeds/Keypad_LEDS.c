/*
 * KeyPad.c
 *
 * Created: 1/27/2023 3:03:10 PM
 * Author : Islam
 */ 

#include "../../LIB/AVR_Atmega32_Interface_Registers.h"
#include "Keypad.h"
#include "../../01_HAL/LED/LED.h"
#include "../../01_HAL/LED/LED_Cfg.h"

int main(void)
{
	u8 Local_u8KeypadVal = 0;
	DIO_enuInit();
	PORTD = 0xFF;
    while (1) 
    {
		Keypad_enuGetKey(&Local_u8KeypadVal);
		if(Local_u8KeypadVal > 0)
		{
			LED_enuLEDON((Local_u8KeypadVal-1) % NUMBER_OF_LEDS);
		}
		
	}
}

