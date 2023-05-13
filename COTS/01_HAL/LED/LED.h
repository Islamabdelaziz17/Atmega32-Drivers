/**********************/
/*LED INTERAFCE FILE  */
/*********************/

#include "..\..\..\00_MCAL\DIO.h"

#ifndef LED_H_
#define LED_H_

typedef enum
{
	LED_enuOk = 0,
	LED_enuNotOk = 1

}LED_tenuErrorStatus;

/**************************/
/* LED SET ON Function
Input: Pin Number (Range from 0 -31)
*/
/**************************/
LED_tenuErrorStatus LED_enuLEDON(DIO_tenuPins Cpy_enuPinNumber);

/**************************/
/* LED SET OFF Function
Input: Pin Number (Range from 0 -31)
*/
/**************************/
LED_tenuErrorStatus LED_enuLEDOFF(DIO_tenuPins Cpy_enuPinNumber);
#endif /* LED_H_ */