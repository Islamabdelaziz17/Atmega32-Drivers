/*********************************
Timer Interface File
*********************************/
#include "Std_types.h"
#include "Timer_cfg.h"

#ifndef Timer_H
#define Timer_H

#define TMR02_MODE_RESET_MASK							  0b10110111U

#define TMR02_MODE_NORMAL								  0x00
#define TMR02_MODE_CTC									  0x08

#define TMR02_MODE_CTC_DISCONNECTED						  0x08U
#define TMR02_MODE_CTC_TOGGLE							  0x18U
#define TMR02_MODE_CTC_CLEAR							  0x28U
#define TMR02_MODE_CTC_SET								  0x38U

#define TMR02_MODE_PWM_PHASE_CORRECT_DISCONNECTED         0x04U
#define TMR02_MODE_PWM_PHASE_CORRECT_CLEAR                0x24U
#define TMR02_MODE_PWM_PHASE_CORRECT_SET                  0x34U

#define TMR02_MODE_FPWM_DISCONNECTED					  0x48U
#define TMR02_MODE_FPWM_CLEAR							  0x68U
#define TMR02_MODE_FPWM_SET								  0x78U

#define TMR02_FOC					0x80U


#define TMR02_CLK_OFF				0b11111000U
#define TMR02_CLK_ON				0x01U

#define TMR0_CLK_PRESCALER_8		0x02U
#define TMR0_CLK_PRESCALER_64		0x03U
#define TMR0_CLK_PRESCALER_256		0x04U
#define TMR0_CLK_PRESCALER_1024		0x05U
#define TMR0_XCLK_FALLING_EDGE		0x06U
#define TMR0_XCLK_RISING_EDGE		0x07U


#define TMR2_CLK_PRESCALER_8		0x02U
#define TMR2_CLK_PRESCALER_32		0x03U
#define TMR2_CLK_PRESCALER_64		0x04U
#define TMR2_CLK_PRESCALER_128		0x05U
#define TMR2_CLK_PRESCALER_256		0x06U
#define TMR2_CLK_PRESCALER_1024		0x07U


#define TMR0_OC_INTERRUPT_ENABLE	0x02U
#define TMR0_OV_INTERRUPT_ENABLE	0x01U

#define TMR2_OC_INTERRUPT_ENABLE	0x80U
#define TMR2_OV_INTERRUPT_ENABLE	0x40U

#define TMR0_CLEAR_OV_FLAG			0x01U
#define TMR0_CLEAR_OC_FLAG			0x02U

#define TMR2_CLEAR_OV_FLAG			0x40U
#define TMR2_CLEAR_OC_FLAG			0x80U

#define TMR02_CLK_PRES_0	1
#define TMR02_CLK_PRES_8	8	
#define TMR02_CLK_PRES_64	64
#define TMR02_CLK_PRES_256	256
#define TMR02_CLK_PRES_1024	1024
#define TMR2_CLK_PRES_32	32
#define TMR2_CLK_PRES_128	128

#define TMR1_FASTPWM_NON_INVERTINGMODE	0xA0
#define TMR1_MODE_FASTPWM_ICU	0x1A


typedef void(*TMR0cbf_t)(void);

typedef struct
{
	u8  Mode;
	u8  Clock_Cfg;
	
}TMR02Config_t;

typedef enum
{
	TMR_enuOK,
	TMR_enuNOK,
	TMR_enuNullPtr
}TMR_enuErrorStatus;


/*
___________________________________
**Description : Pre-initialize Timer 0
_________________________________________
**Returns Void
_________________________________________
*/
void TMR0_vidInitPreCompile(void);
/*
___________________________________
**Description : Post initialize Timer 0 
___________________________________
**Input: struct Object with timer configurations "Addr_pstr_Modulecfg"  
_________________________________________
**Returns Error Status if wrong configurations
_________________________________________
*/
TMR_enuErrorStatus TMR0_vidInitPostCompile(TMR02Config_t* Addr_pstr_Modulecfg);
/*
___________________________________
**Description : Set Timer Clock In milliseconds
___________________________________
**Input "Copy_u8Clock" Options :
___________________________________
	- TMR02_CLK_PRES_8	
	- TMR02_CLK_PRES_64	
	- TMR02_CLK_PRES_256
	- TMR02_CLK_PRES_1024
_________________________________________
**Returns Error Status if wrong configurations
_________________________________________
*/
TMR_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u8 Copy_u8Clock,u16 * Add_pu8OV_Counts);
/*
___________________________________
**Description : Set Timer Callback function OVERFLOW MODE
___________________________________
**Input address of passed function:
_________________________________________
**Returns Error Status if wrong configurations
_________________________________________

*/
TMR_enuErrorStatus TMR0_enuRegisterCallback_OV(TMR0cbf_t Cpy_TMR0Cbf);

/*
___________________________________
**Description : Set Timer Callback function CTC MODE
___________________________________
**Input address of passed function:
_________________________________________
**Returns Error Status if wrong configurations
_________________________________________

*/
TMR_enuErrorStatus TMR0_enuRegisterCallback_CTC(TMR0cbf_t Cpy_TMR0Cbf);

TMR_enuErrorStatus TMR0_SetCompareValue(u8 Cpy_TMR0_OCR0);

void TMR1_Init_FastPWM_InputCapture(u8 Cpy_u8PeriodTime);

void TMR1_Set_CompareMatchA(u16 Cpy_u16OnTime);



#endif /*Timer_H*/
