/*
 *************************** ***************************
 *     BushButton Switch interface File		*
 ************************* *************************
 *
 * Created: 1/18/2023 3:23:04 PM
 *  Author: Islam
 */ 

#include "..\..\..\00_MCAL\DIO_Driver\DIO_Driver\DIO.h"

#ifndef SWITCH_H_
#define SWITCH_H_

typedef enum
{
	SWITCH_enuOk = 0,
	SWITCH_enuNotOk = 1

}SWITCH_tenuErrorStatus;


typedef enum
{
	SWITCH_enuPressed = 0,
	SWITCH_enuReleased = 1

}SWITCH_tenuStatus;


/**************************/
/* Switch get status Function
Input: Pin Number (Range from 0 -31)
Output: Returned switch status by address
*/
/**************************/
SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(DIO_tenuPins Cpy_enuPinNumber,volatile u8* Add_pu8SwitchStatus);


#endif /* SWITCH_H_ */