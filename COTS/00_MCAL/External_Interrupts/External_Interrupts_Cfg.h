/*
 * External_Interrupts_Cfg.h
 *
 * Created: 1/27/2023 10:31:48 AM
 *  Author: islam
 */ 

#include "../../00_MCAL/DIO/DIO.h"
#include "External_Interrupts_Prv.h"

#ifndef EXTERNAL_INTERRUPTS_CFG_H_
#define EXTERNAL_INTERRUPTS_CFG_H_

#define EXTERNAL_INTERRUPT_NUMS 3

#define INT0_BIT_NUM  6
#define INT1_BIT_NUM  7
#define INT2_BIT_NUM  5

#define INT0_MODE MODE_FALLING_EDGE
#define INT1_MODE MODE_FALLING_EDGE
#define INT2_MODE NO_MODE


#endif /* EXTERNAL_INTERRUPTS_CFG_H_ */