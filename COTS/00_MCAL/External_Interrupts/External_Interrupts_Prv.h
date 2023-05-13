/*
 * External_Interrupts_Prv.h
 *
 * Created: 1/27/2023 10:34:14 AM
 *  Author: Islam
 */ 


#ifndef EXTERNAL_INTERRUPTS_PRV_H_
#define EXTERNAL_INTERRUPTS_PRV_H_

#define  MCUCR	*(((volatile u8*)0x55))
#define  MCUCSR	*(((volatile u8*)0x54))
#define  GICR	*(((volatile u8*)0x5B))
#define  GIFR	*(((volatile u8*)0x5A))

#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3
#define MCUCSR_ISC2 6


#define MODE_RISING_EDGE	0b11
#define MODE_FALLING_EDGE	0b10
#define MODE_LOW_LEVEL		0b00
#define MODE_ON_CHANGE		0b01
#define INT2_MODE_RISING_EDGE 0b1
#define INT2_MODE_FALLING_EDGE 0b0
#define Mask_Config_Bits 0b11
#define NO_MODE 4

#define INT0 0
#define INT1 1
#define INT2 2

#define INT0_PIN_NUMBER 26
#define INT0_PIN_NUMBER 27


#endif /* EXTERNAL_INTERRUPTS_PRV_H_ */