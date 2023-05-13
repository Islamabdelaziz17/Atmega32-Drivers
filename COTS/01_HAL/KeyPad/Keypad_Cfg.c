/*
 * Keypad_Cfg.c
 *
 * Created: 1/27/2023 3:04:39 PM
 *  Author: Islam
 */ 

#include "../../../00_MCAL/DIO_Driver/DIO_Driver/DIO.h"
#include "../../../LIB//AVR_Atmega32_Interface_Registers.h"
#include "Keypad_Cfg.h"
extern const u8 Keypad_u8[KEYPAD_ROWS][KEYPAD_COLS] =
{
	/* Values for each key in the 4x4*/
	  {1,   2,    3,  4},       
	  {5,   6,    7,  8},
	  {9,   10,   11,  12},
	  {13,  14,   15,  16} 
};

extern const u8 Keypad_u8RowsConfig[KEYPAD_ROWS] ={DIO_enuPin24,DIO_enuPin25,DIO_enuPin26,DIO_enuPin27};
extern const u8 Keypad_u8ColsConfig[KEYPAD_COLS] ={DIO_enuPin28,DIO_enuPin29,DIO_enuPin30,DIO_enuPin31};

