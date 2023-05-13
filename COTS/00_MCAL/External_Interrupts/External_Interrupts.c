/*
 * External_Interrupts.c
 *
 * Created: 1/27/2023 10:31:16 AM
 *  Author: Islam
 */
 
#include "External_Interrupts.h"
#include "External_Interrupts_Cfg.h"
#include "External_Interrupts_Prv.h"
#include "../../LIB/Bit_math.h"

External_Interrupt_tenuErrorStatus External_Interrupt_enuInit(void)
{
	u8 Local_u8Interrptscounter = 0;
	u8 Local_u8Temp = 0;
	External_Interrupt_tenuErrorStatus External_Interrupt_enuErrorStat = External_Interrupt_enuOk;	
	
	#if INT0_MODE != NO_MODE
		SET_BIT(GICR,INT0_BIT_NUM);
	#endif
	#if INT1_MODE != NO_MODE
		SET_BIT(GICR,INT1_BIT_NUM);
	#endif
	#if INT2_MODE != NO_MODE
		SET_BIT(GICR,INT2_BIT_NUM);
	#endif
	
	#if INT0_MODE == MODE_RISING_EDGE
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits);
			Local_u8Temp |= MODE_RISING_EDGE;
			MCUCR = Local_u8Temp;
	#elif INT0_MODE == MODE_FALLING_EDGE
		    Local_u8Temp = MCUCR;
		    Local_u8Temp &= ~(Mask_Config_Bits);
		    Local_u8Temp |= MODE_FALLING_EDGE;
		    MCUCR = Local_u8Temp;
	#elif INT0_MODE == MODE_LOW_LEVEL
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits);
			Local_u8Temp |= MODE_LOW_LEVEL;
			MCUCR = Local_u8Temp;
	#elif INT0_MODE == MODE_ON_CHANGE
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits);
			Local_u8Temp |= MODE_ON_CHANGE;
			MCUCR = Local_u8Temp;
	#else INT0_MODE == NO_MODE
			/*NOCHANGE*/
	#endif
	
	#if INT1_MODE == MODE_RISING_EDGE
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits<<2);
			Local_u8Temp |= (MODE_RISING_EDGE<<2);
			MCUCR = Local_u8Temp;
	#elif INT1_MODE == MODE_FALLING_EDGE
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits<<2);
			Local_u8Temp |= (MODE_FALLING_EDGE<<2);
			MCUCR = Local_u8Temp;
	#elif INT1_MODE == MODE_LOW_LEVEL
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits<<2);
			Local_u8Temp |= (MODE_LOW_LEVEL<<2);
			MCUCR = Local_u8Temp;
	#elif INT1_MODE == MODE_ON_CHANGE
			Local_u8Temp = MCUCR;
			Local_u8Temp &= ~(Mask_Config_Bits<<2);
			Local_u8Temp |= (MODE_ON_CHANGE<<2);
			MCUCR = Local_u8Temp;
	#else INT1_MODE == NO_MODE
			/*NOCHANGE*/
	#endif
	
	#if INT2_MODE == INT2_MODE_RISING_EDGE
			SET_BIT(MCUCSR,MCUCSR_ISC2);
	#elif INT2_MODE == MODE_FALLING_EDGE
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#else INT2_MODE == NO_MODE
			/*NOCHANGE*/
	#endif

	return External_Interrupt_enuErrorStat;
}