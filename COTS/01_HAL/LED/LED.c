/*
 * Led File.c
 *
 * Created: 1/17/2023 8:28:31 PM
 * Author : Islam
 */ 

#include "LED.h"
#include "LED_Cfg.h"


LED_tenuErrorStatus LED_enuLEDON(u8 Cpy_enuLedNumber)
{
	//Initializing DIO TARGET PINS FIRST AS OUTPUT
	DIO_tenuErrorStatus InitStatus = DIO_enuInit();
	
	LED_tenuErrorStatus Local_enuLEDErrorStat = LED_enuOk;
	DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuOk;
	
	/*Validating Arguments*/
	/*IF THE LED NUMBER EXCEEDS THE PRE-CONFIGUERD NUMBER OF LEDS IN CONFIGURATION FILE*/
	if(Cpy_enuLedNumber >= NUMBER_OF_LEDS)
	{
		Local_enuLEDErrorStat = LED_enuNotOk;
	}
	else
	{
		/*IF THE LED IS ACTIVE HIGH THEN SET THE PIN HIGH USING DIO SET PIN FUNCTION*/
		if(LED_strPinCfg[Cpy_enuLedNumber].LED_ActiveLogic == LED_enuActiveHIGH)
		{
			 Local_enuDIOErrorstat = DIO_enuSetPin(LED_strPinCfg[Cpy_enuLedNumber].LED_PINVALUE);
		}
		/*IF THE LED IS ACTIVE LOW THEN CLEAR THE PIN LOW USING DIO CLEAR PIN FUNCTION*/
		else if(LED_strPinCfg[Cpy_enuLedNumber].LED_ActiveLogic == LED_enuActiveLOW)
		{
			 Local_enuDIOErrorstat = DIO_enuClearPin(LED_strPinCfg[Cpy_enuLedNumber].LED_PINVALUE);
		}
	
		/*VALIDATING PIN STATUS AS OUTPUT*/
		if(Local_enuDIOErrorstat != DIO_enuOk)
		{
			Local_enuLEDErrorStat = LED_enuNotOk;
		}
	}
	//Finally returns function status
	return Local_enuLEDErrorStat;
}

LED_tenuErrorStatus LED_enuLEDOFF(u8 Cpy_enuLedNumber)
{
	//Initializing DIO TARGET PINS FIRST AS OUTPUT
	DIO_tenuErrorStatus InitStatus = DIO_enuInit();
	
	LED_tenuErrorStatus Local_enuLEDErrorStat = LED_enuOk;
	DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuOk;
	/*Validating Arguments*/
	/*IF THE LED NUMBER EXCEEDS THE PRE-CONFIGUERD NUMBER OF LEDS IN CONFIGURATION FILE*/
	if(Cpy_enuLedNumber >= NUMBER_OF_LEDS)
	{
		Local_enuLEDErrorStat = LED_enuNotOk;
	}
	else
	{
		/*IF THE LED IS ACTIVE HIGH THEN CLEAR THE PIN LOW USING DIO CLEAR PIN FUNCTION*/
		if(LED_strPinCfg[Cpy_enuLedNumber].LED_ActiveLogic == LED_enuActiveHIGH)
		{
			Local_enuDIOErrorstat = DIO_enuClearPin(LED_strPinCfg[Cpy_enuLedNumber].LED_PINVALUE);
		}
		/*IF THE LED IS ACTIVE LOW THEN SET THE PIN HIGH USING DIO SET PIN FUNCTION*/
		else if(LED_strPinCfg[Cpy_enuLedNumber].LED_ActiveLogic == LED_enuActiveLOW)
		{
			Local_enuDIOErrorstat = DIO_enuSetPin(LED_strPinCfg[Cpy_enuLedNumber].LED_PINVALUE);
		}
	
		/*VALIDATING PIN STATUS AS OUTPUT*/
		if(Local_enuDIOErrorstat != DIO_enuOk)
		{
			Local_enuLEDErrorStat = LED_enuNotOk;
		}
	}
	//Finally returns function status
	return Local_enuLEDErrorStat;
	
}