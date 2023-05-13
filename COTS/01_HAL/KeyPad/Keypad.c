/*
 * Keypad.c
 *
 * Created: 1/27/2023 3:03:26 PM
 *  Author: Islam
 */ 

#include "../../../LIB/Std_Types.h"
#include "../../../LIB/Bit_math.h"
#include "Keypad.h"
#include "Keypad_Cfg.h"
#include "util/delay.h"

Keypad_tenuErrorStatus Keypad_enuGetKey(volatile u8* add_pu8keyval)
{
	u8 Local_u8RowsCounter = 0,Local_u8ColsCounter = 0,Local_u8KeyVal = 100;
	Keypad_tenuErrorStatus LocalKeypad_enuErrorstat = Keypad_enuNotOk;
	for(Local_u8RowsCounter=0;Local_u8RowsCounter<KEYPAD_ROWS;++Local_u8RowsCounter)
	{
		DIO_enuClearPin(Keypad_u8RowsConfig[Local_u8RowsCounter]);
		for(Local_u8ColsCounter=0;Local_u8ColsCounter<KEYPAD_COLS;Local_u8ColsCounter++)
		{
			_delay_ms(10);
			DIO_enuGetPin(Keypad_u8ColsConfig[Local_u8ColsCounter],&Local_u8KeyVal);
			if(Local_u8KeyVal == LOW)
			{
				*add_pu8keyval = Keypad_u8[Local_u8RowsCounter][Local_u8ColsCounter];
				LocalKeypad_enuErrorstat = Keypad_enuOk;
				break;
			}
		}
		DIO_enuSetPin(Keypad_u8RowsConfig[Local_u8RowsCounter]);
		if(Local_u8KeyVal == LOW)
		{
			break;
		}

		
	}
	return LocalKeypad_enuErrorstat;
}