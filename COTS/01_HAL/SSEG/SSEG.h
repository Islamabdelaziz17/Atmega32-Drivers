/*
 * SSEG.h
 *
 * Created: 1/20/2023 2:51:28 PM
 *  Author: Islam
 */ 

#ifndef SSEG_H_
#define SSEG_H_

#define SSEG_NUMS 1
#define SSEG_NUMS_OF_LEDS 8
#define SSEGS_NUM_OF_PINS 9

typedef enum
{
	SSEG_enuOk = 0,
	SSEG_enuNotOk = 1

}SSEG_tenuErrorStatus;

SSEG_tenuErrorStatus SSEG_enunInit(void);
/**************************/
/* 7 SEGMENT DISPLAY A GIVEN NUMBER FUNCTION
Input: NUMBER TO DISPLAY (Range from 0 - 9)
Input: ID OF THE DISPLAY (Range from 0 - 1) 
*/
/**************************/
SSEG_tenuErrorStatus SSEG_enuDisplay(u8 Cpy_enuSSEGNumber,u8 Cpy_u8SSEGCounter);
/**************************/
/* 7 SEGMENT CLEAR THE DISPLAY FUNCTION
Input: ID OF THE DISPLAY (Range from 0 - 1)
*/
/**************************/
SSEG_tenuErrorStatus SSEG_enuClearDisplay(u8 Cpy_u8SSEGCounter);

typedef enum
{
	SSEG_enuActiveLOW = 0,
	SSEG_enuActiveHIGH = 1

}SSEG_tenuConfig;

typedef struct
{
	SSEG_tenuConfig SSEG_ActiveLogic;
	const u8 *SSEG_Pins;

}SSEG_strPinCfg_t;


#endif /* SSEG_H_ */