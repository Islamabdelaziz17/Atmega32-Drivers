/*
 * SSEG_Cfg.c
 *
 * Created: 1/20/2023 2:52:00 PM
 *  Author: Islam
 */ 

#include "SSEG_Cfg.h"

/*First 7 Segment Display Configured on PORT A*/
const u8 SSEG1_Pins_Nums[SSEGS_NUM_OF_PINS] =
{
	[0] = DIO_enuPin0,
	[1] = DIO_enuPin1,
	[2] = DIO_enuPin2,
	[3] = DIO_enuPin3,
	[4] = DIO_enuPin4,
	[5] = DIO_enuPin5,
	[6] = DIO_enuPin6,
	[7] = DIO_enuPin7
};
/*Second 7 Segment Display Configured on PORT C*/
const u8 SSEG2_Pins_Nums[SSEGS_NUM_OF_PINS] =
{
	[0] = DIO_enuPin16,
	[1] = DIO_enuPin17,
	[2] = DIO_enuPin18,
	[3] = DIO_enuPin19,
	[4] = DIO_enuPin20,
	[5] = DIO_enuPin21,
	[6] = DIO_enuPin22,
	[7] = DIO_enuPin23
};
/*NUMBERS FROM 0-9 LOOKUP TABLE TO BE DISPLAYED*/
u8 SSEG_LookUpTable[10] = {
	
	[0] = 0b0111111,
	[1] = 0b0000110,
	[2] = 0b1011011,
	[3] = 0b1001111,
	[4] = 0b1100110,
	[5] = 0b1101101,
	[6] = 0b1111101,
	[7] = 0b0000111,
	[8] = 0b1111111,
	[9] = 0b1101111
	
};

/*Display Configurations*/
const SSEG_strPinCfg_t SSEG_strPinCfg[SSEGS_NUMS] = {
	
	{SSEG_enuActiveHIGH,SSEG1_Pins_Nums}

};