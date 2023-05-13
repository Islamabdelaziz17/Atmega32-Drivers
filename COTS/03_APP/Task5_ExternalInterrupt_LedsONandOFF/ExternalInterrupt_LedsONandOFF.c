/*
 * External_Interrupts.c
 *
 * Created: 1/27/2023 10:09:42 AM
 * Author : Islam
 */ 

#define F_CPU 80000000UL
#include "External_Interrupts.h"
#include "avr/interrupt.h"
#include "../../00_MCAL/Global_Interrupt/Global_Interrupt.h"
#include "../../01_HAL/SWITCH/SWITCH.h"
#include "../../01_HAL/SWITCH/SWITCH_Cfg.h"
#include "../../01_HAL/LED/LED.h"
#include "../../01_HAL/LED/LED_Cfg.h"

volatile u8 Global_u8LedCounter = 0; 
volatile u8 Global_u8DebounceCounter = 0;
volatile u8 Global_u8InterruptPinValue = 0;

ISR(INT0_vect)
{
	SWITCH_enuGetSwitchValue(0,&Global_u8InterruptPinValue);
	if(Global_u8InterruptPinValue == 0)
	{
		Global_u8DebounceCounter++;
	}
	else
	{
		Global_u8DebounceCounter--;
		if(Global_u8DebounceCounter < 0)
		{
			Global_u8DebounceCounter = 0;
		}
	}
	if(Global_u8DebounceCounter == 5)
	{
		Global_u8DebounceCounter = 0;
		LED_enuLEDON(Global_u8LedCounter++);
	}



}
ISR(INT1_vect)
{
	SWITCH_enuGetSwitchValue(1,&Global_u8InterruptPinValue);
	if(Global_u8InterruptPinValue == 0)
	{
		Global_u8DebounceCounter++;
	}
	else
	{
		Global_u8DebounceCounter--;
		if(Global_u8DebounceCounter < 0)
		{
			Global_u8DebounceCounter = 0;
		}
	}
	if(Global_u8DebounceCounter == 1)
	{
		Global_u8DebounceCounter = 0;	
		LED_enuLEDOFF(--Global_u8LedCounter);
	}

}
int main(void)
{
	DIO_tenuErrorStatus Local_enuDIOerrorstat  = DIO_enuInit();
	Global_Interrupt_voidEnable();
	External_Interrupt_tenuErrorStatus Local_enuErrorStat = External_Interrupt_enuInit();
    while (1) 
    {
		
    }
}



