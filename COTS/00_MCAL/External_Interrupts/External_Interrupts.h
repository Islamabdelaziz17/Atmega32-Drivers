/*
 * External_Interrupts.h
 *
 * Created: 1/27/2023 10:31:36 AM
 *  Author: islam
 */ 

#include "../../LIB/Std_Types.h"

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

typedef enum
{
	External_Interrupt_enuOk = 0,
	External_Interrupt_enuNotOk = 1,

}External_Interrupt_tenuErrorStatus;

External_Interrupt_tenuErrorStatus External_Interrupt_enuInit(void);
void External_Interrupt_voidEnable(u8 Cpy_u8ExternalIterruptNum);
void External_Interrupt_voidDisable(u8 Cpy_u8ExternalIterruptNum);



#endif /* EXTERNAL_INTERRUPTS_H_ */