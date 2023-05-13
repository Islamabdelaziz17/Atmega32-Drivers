/*
 * Global_Interrupt.c
 *
 * Created: 1/27/2023 9:49:11 AM
 *  Author: Islam
 */ 

#include "Global_Interrupt_Cfg.h"
#include "Global_Interrupt_Prv.h"
#include "Global_Interrupt.h"
#include "../../LIB/Bit_math.h"

void Global_Interrupt_voidEnable(void)
{
	SET_BIT(SREG,GIE_BIT_NUMBER);
}

void Global_Interrupt_voidDisable(void)
{
	CLR_BIT(SREG,GIE_BIT_NUMBER);
}