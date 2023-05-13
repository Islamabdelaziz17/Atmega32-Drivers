/*
 *************************** *************************
 *     BushButton Switch interface Config.h		*
 ************************* *************************
 *
 * Created: 1/18/2023 3:23:04 PM
 *  Author: Islam
 */ 
#include "..\..\..\00_MCAL\DIO_Driver\DIO_Driver\DIO.h"

#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#define NUMBER_OF_SWITCHES 2

typedef enum
{
	SWITCH_enuActiveLOW = 0,
	SWITCH_enuActiveHIGH = 1

}SWITCH_tenuConfig;

typedef enum
{
	SWITCH_enuFallingEdge= 0,
	SWITCH_enuRisingEdge = 1

}SWITCH_tenuTriggerOption;

typedef enum
{
	SWITCH_enuIncreament = 0,
	SWITCH_enuDecreament = 1

}SWITCH_tenuSpecificFunctionality;

typedef struct
{
	SWITCH_tenuConfig SWITCH_ActiveLogic; //ACTIVE LOW OR HIGH
	SWITCH_tenuTriggerOption SWITCH_TriggerOption; //FALLING OR RISING EDGE
	SWITCH_tenuSpecificFunctionality SWITCH_TO_DO; //FUNCTIONALITY IN APPLICATION
	DIO_tenuPins SWITCH_PINVALUE; //PIN VALUE ACCORDING TO THE TARGET
	

}SWITCH_strPinCfg_t;

//ARRAY OF SWITCH CONFIGURATIONS
extern const SWITCH_strPinCfg_t SWITCH_strPinCfg[NUMBER_OF_SWITCHES];

#endif /* SWITCH_CFG_H_ */