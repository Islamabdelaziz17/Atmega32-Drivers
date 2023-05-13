/*
 * SWITCH_Cfg.c
 *
 * Created: 1/18/2023 3:24:06 PM
 *  Author: Islam
 */ 
#include "SWITCH_Cfg.h"

extern const SWITCH_strPinCfg_t SWITCH_strPinCfg[NUMBER_OF_SWITCHES] =
{      /*PIN Status*/	  /* Trigger Option*/	/*Fuctionallity*/	/*PIN NUMBER*/
	{SWITCH_enuActiveHIGH,SWITCH_enuFallingEdge,SWITCH_enuIncreament,DIO_enuPin26},
	{SWITCH_enuActiveHIGH,SWITCH_enuFallingEdge,SWITCH_enuDecreament,DIO_enuPin27}	
};
