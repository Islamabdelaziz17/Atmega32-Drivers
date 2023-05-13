/*
 * Keypad.h
 *
 * Created: 1/27/2023 3:03:42 PM
 *  Author: Islam
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../../LIB/Std_Types.h"

typedef enum
{
	Keypad_enuOk = 0,
	Keypad_enuNotOk = 1,

}Keypad_tenuErrorStatus;


Keypad_tenuErrorStatus Keypad_enuGetKey(volatile u8*);



#endif /* KEYPAD_H_ */