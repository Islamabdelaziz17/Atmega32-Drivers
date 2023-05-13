/*
 * SSEG.c
 *
 * Created: 1/20/2023 2:51:14 PM
 *  Author: Islam
 */ 
#include "SSEG.h"
#include "SSEG_Cfg.h"
#include "..\..\00_MCAL\DIO.h"
#include "..\..\00_MCAL\DIO_Cfg.h"

SSEG_tenuErrorStatus SSEG_enunInit(void)
{
	DIO_tenuErrorStatus Local_enuDIOErrorStatus  = DIO_enuInit();
	SSEG_tenuErrorStatus Local_enuSSEGErrorstat = SSEG_enuOk;
	//VERIFY STATUS
	if(Local_enuDIOErrorStatus != DIO_enuOk)
	{
		Local_enuSSEGErrorstat = SSEG_enuNotOk;
	}
	return Local_enuSSEGErrorstat;
}
SSEG_tenuErrorStatus SSEG_enuClearDisplay(u8 Cpy_u8SSEGCounter)
{
	u8 Local_u8LedCounter = 0;
	DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuOk;
	SSEG_tenuErrorStatus Local_enuSSEGErrorstat = SSEG_enuOk;
	//CLEARING LEDS OF THE DISPLAY
	for(Local_u8LedCounter=0;Local_u8LedCounter<SSEGS_NUM_OF_PINS;Local_u8LedCounter++)
	{
		if(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_ActiveLogic == SSEG_enuActiveHIGH)
		{
			DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuClearPin(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_Pins[Local_u8LedCounter]);
		}
		else if(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_ActiveLogic == SSEG_enuActiveLOW)
		{
			DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuSetPin(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_Pins[Local_u8LedCounter]);
		}
	}
	
	if(Local_enuDIOErrorstat != DIO_enuOk)
	{
		Local_enuSSEGErrorstat = SSEG_enuNotOk;
	}
		
		
	return Local_enuSSEGErrorstat;
}

SSEG_tenuErrorStatus SSEG_enuDisplay(u8 Cpy_enuSSEGNumber,u8 Cpy_u8SSEGCounter)
{

	u8 Local_u8LedCounter = 0;
	u8 Local_u8DigitBinaryCode= 0;
	DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuOk;
	SSEG_tenuErrorStatus Local_enuSSEGErrorstat = SSEG_enuOk;

	Local_u8LedCounter = 0;
	/*CHECK DISPLAY CONFIGURATIONS IF COMMON ANODE/CATHODE*/
	if(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_ActiveLogic == SSEG_enuActiveHIGH)
	{
		/*GET THE BINARY VALUE TO BE DISPLAYED ON THE 7-SEGMENT*/
		Local_u8DigitBinaryCode = SSEG_LookUpTable[Cpy_enuSSEGNumber];
		/*GET BIT BY BIT VALUE OF EACH LED IN THE 7-SEGMENT DISPLAY*/
		while (Local_u8DigitBinaryCode != 0)
		{
			/*IF BIT IS HIGH SET THE BIT USING DIO_SETPIN*/
			if((Local_u8DigitBinaryCode & 0x01) == 1)
			{
				Local_enuDIOErrorstat = DIO_enuSetPin(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_Pins[Local_u8LedCounter]);
			}
			/*IF BIT IS LOW CLEAR THE BIT USING DIO_CLEARIN*/
			else
			{
				Local_enuDIOErrorstat = DIO_enuClearPin(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_Pins[Local_u8LedCounter]);
			}
			//SHIFT LEFT BY ONE TO REMOVE THE CHECKED CURRENT BIT
			Local_u8DigitBinaryCode = (Local_u8DigitBinaryCode>>1);
			//INCREAMENT THE COUNTER OF LEDS CHECKED
			Local_u8LedCounter++;
		}
	
	}
	/*CHECK DISPLAY CONFIGURATIONS IF COMMON ANODE/CATHODE*/
	else if(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_ActiveLogic == SSEG_enuActiveLOW)
	{
		/*GET THE BINARY VALUE TO BE DISPLAYED ON THE 7-SEGMENT*/
		Local_u8DigitBinaryCode = SSEG_LookUpTable[Local_u8LedCounter];
		/*GET BIT BY BIT VALUE OF EACH LED IN THE 7-SEGMENT DISPLAY*/
		while (Local_u8DigitBinaryCode != 0)
		{
			/*IF BIT IS HIGH SET THE BIT USING DIO_SETPIN*/
			if(Local_u8DigitBinaryCode&0x1 == 1)
			{
				Local_enuDIOErrorstat = DIO_enuClearPin(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_Pins[Local_u8LedCounter]);
			}
			/*IF BIT IS LOW CLEAR THE BIT USING DIO_CLEARIN*/
			else
			{
				Local_enuDIOErrorstat = DIO_enuSetPin(SSEG_strPinCfg[Cpy_u8SSEGCounter].SSEG_Pins[Local_u8LedCounter]);
			}
			//SHIFT LEFT BY ONE TO REMOVE THE CHECKED CURRENT BIT
			Local_u8DigitBinaryCode = (Local_u8DigitBinaryCode>>1);
			//INCREAMENT THE COUNTER OF LEDS CHECKED
			Local_u8LedCounter++;
		}
		
	}
	//VERIFY STATUS
	if(Local_enuDIOErrorstat != DIO_enuOk)
	{
		Local_enuSSEGErrorstat = SSEG_enuNotOk;
	}
		
		
	return Local_enuSSEGErrorstat;
	
	
}