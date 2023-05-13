/*********************************
LM35 Interface File
*********************************/
#include "../../../LIB/Std_Types.h"

#ifndef LM35_H
#define LM35_H

typedef enum
{
	LM35_enuOk,
	LM35_enuNotOk
	
}Lm35_enuErrorStatus_t;

/*READS LM35 VALUE AND CONVERT IT FROM ANLOG TO DIGITAL USING THE ADC PERIPHERAL*/
/*INPUT: SENSOR ID*/
/*RETURNS THE VALUE OF THE SENSOR THROUGH A POINTER*/
/*RETURNS ERROR STATUS*/
Lm35_enuErrorStatus_t LM35_enuReadValue(u8 Cpy_u8LM35_Idx,u8*Cpy_u8ReadingVal);
#endif /*LM35_H*/
