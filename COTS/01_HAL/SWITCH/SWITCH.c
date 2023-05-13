/*
 *************************** *************************
 *     BushButton Switch File.c		*
 ************************* *************************
 *
 * Created: 1/18/2023 3:23:04 PM
 *  Author: Islam
 */ 
#include "SWITCH.h"
#include "SWITCH_Cfg.h"


SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(u8 Cpy_SwitchNumber,volatile u8*Add_pu8SwitchStatus)
{

	SWITCH_tenuErrorStatus Local_enuSWITCHErrorStat = SWITCH_enuOk;
	DIO_tenuErrorStatus Local_enuDIOErrorstat = DIO_enuOk;
	
	/*Validating Arguments*/
	/*IF THE Switch NUMBER EXCEEDS THE PRE-CONFIGUERD NUMBER OF LEDS IN CONFIGURATION FILE*/
	if(Cpy_SwitchNumber >= NUMBER_OF_SWITCHES)
	{
		Local_enuSWITCHErrorStat = SWITCH_enuNotOk;
	}
	else
	{
	    Local_enuDIOErrorstat = DIO_enuGetPin(SWITCH_strPinCfg[Cpy_SwitchNumber].SWITCH_PINVALUE,Add_pu8SwitchStatus);
		
		/*VALIDATING PIN STATUS AS OUTPUT*/
		if(Local_enuDIOErrorstat != DIO_enuOk)
		{
			Local_enuSWITCHErrorStat = SWITCH_enuNotOk;
		}
	}
	return Local_enuSWITCHErrorStat;
	
}