#include "Timer.h"
#include "Timer_cfg.h"
#include "math.h"

#define TIMER_BASE_ADDRESS  0x43
#define TIMER_RESOLUTION    256
#define ATMEGA_F_CPU		8
#define TIME_MILISEC		1000
#define COMPARE_MATCH_VAL	250


#define TIFR_TOV0 0x01
#define TIFR_OCF0 0x02

typedef struct
{
	u8 OCR2;
	u8 TCNT2;
	u8 TCCR2;
	u16 ICR1;
	u16 OCR1B;
	u16 OCR1A;
	u8 TCNT1L;
	u8 TCNT1H;
	u8 TCCR1B;
	u8 TCCR1A;
	u8 SFIOR;
	u8 OCDR;
	u8 OSCCAL;
	u8 TCNT0;
	u8 TCCR0;
	u8 MCUCSR;
	u8 MCUCR;
	u8 TWCR;
	u8 SPMCR;
	u8 TIFR;
	u8 TIMSK;
	u8 GIFR;
	u8 GICR;
	u8 OCR0;
}Timer_strReg_t;

volatile Timer_strReg_t * const Timer = (volatile Timer_strReg_t*) TIMER_BASE_ADDRESS;
TMR0cbf_t Timer0Cbf = NULL;

void TMR0_vidInitPreCompile(void)
{
	u8 Local_u8TCCR0 = Timer->TCCR0;
	u8 Local_u8TIMSK = Timer->TIMSK;
	u8 Local_u8Mode = 0,Local_u8ClkCfg = 0,Local_u8InterruptCfg = 0;
	Local_u8TCCR0 &= TMR02_MODE_RESET_MASK;
	
	#if TIMER0_MODE_CFG == TMR02_MODE_NORMAL
	Local_u8Mode = TMR02_MODE_NORMAL;
	#elif TIMER0_MODE_CFG == TMR02_MODE_CTC_TOGGLE
	Local_u8Mode = TMR02_MODE_CTC_TOGGLE;
	#elif TIMER0_MODE_CFG == TMR02_MODE_CTC_SET
	Local_u8Mode = TMR02_MODE_CTC_SET;
	#elif TIMER0_MODE_CFG == TMR02_MODE_CTC_CLEAR
	Local_u8Mode = TMR02_MODE_CTC_CLEAR;
	#elif TIMER0_MODE_CFG == TMR02_MODE_PWM_PHASE_CORRECT_SET
	Local_u8Mode = TMR02_MODE_PWM_PHASE_CORRECT_SET;
	#elif TIMER0_MODE_CFG == TMR02_MODE_PWM_PHASE_CORRECT_CLEAR
	Local_u8Mode = TMR02_MODE_PWM_PHASE_CORRECT_CLEAR;
	#elif TIMER0_MODE_CFG == TMR02_MODE_PWM_PHASE_CORRECT_DISCONNECTED
	Local_u8Mode = TMR02_MODE_PWM_PHASE_CORRECT_DISCONNECTED;
	#elif TIMER0_MODE_CFG == TMR02_MODE_FPWM_DISCONNECTED
	Local_u8Mode = TMR02_MODE_FPWM_DISCONNECTED;
	#elif TIMER0_MODE_CFG == TMR02_MODE_FPWM_SET
	Local_u8Mode = TMR02_MODE_FPWM_SET;
	#elif TIMER0_MODE_CFG == TMR02_MODE_FPWM_CLEAR
	Local_u8Mode = TMR02_MODE_FPWM_CLEAR;
	#endif
	
	#if TIMER0_MODE_CFG == TMR02_CLK_ON
	Local_u8ClkCfg = TMR02_CLK_ON;
	#elif TIMER0_MODE_CFG == TMR02_CLK_OFF
	Local_u8ClkCfg = TMR02_CLK_OFF;
	#elif TIMER0_MODE_CFG == TMR0_CLK_PRESCALER_8
	Local_u8ClkCfg = TMR0_CLK_PRESCALER_8;
	#elif TIMER0_MODE_CFG == TMR0_CLK_PRESCALER_64
	Local_u8ClkCfg = TMR0_CLK_PRESCALER_64;
	#elif TIMER0_MODE_CFG == TMR0_CLK_PRESCALER_256
	Local_u8ClkCfg = TMR0_CLK_PRESCALER_256;
	#elif TIMER0_MODE_CFG == TMR0_CLK_PRESCALER_1024
	Local_u8ClkCfg = TMR0_CLK_PRESCALER_1024;
	#elif TIMER0_MODE_CFG == TMR0_XCLK_FALLING_EDGE
	Local_u8ClkCfg = TMR0_XCLK_FALLING_EDGE;
	#elif TIMER0_MODE_CFG == TMR0_XCLK_RISING_EDGE
	Local_u8ClkCfg = TMR0_XCLK_RISING_EDGE;
	#endif
	
	#if TIMER0_ENABLE_INTERRUPT == TMR0_OV_INTERRUPT_ENABLE
	Local_u8InterruptCfg = TMR0_OV_INTERRUPT_ENABLE;
	Local_u8TIMSK |= Local_u8InterruptCfg;
	Timer->TIMSK = Local_u8TIMSK;
	#elif TIMER0_ENABLE_INTERRUPT == TMR0_OC_INTERRUPT_ENABLE
	Local_u8InterruptCfg = TMR0_OC_INTERRUPT_ENABLE;
	Local_u8TIMSK |= Local_u8InterruptCfg;
	Timer->TIMSK = Local_u8TIMSK;
	#endif
	
	#if TIMER0_ENABLE_FOC == 1
	Local_u8TCCR0 |= TMR02_FOC;
	#endif
	
	Local_u8TCCR0 |= Local_u8Mode;
	
	Local_u8TCCR0 &= TMR02_CLK_OFF;
	Local_u8TCCR0 |= Local_u8ClkCfg;
	
	Timer->TCCR0 = Local_u8TCCR0;
	//Timer->TCCR0 = 0x01;
}
TMR_enuErrorStatus TMR0_vidInitPostCompile(TMR02Config_t* Addr_pstr_Modulecfg)
{
	TMR_enuErrorStatus Local_enuErrorstat = TMR_enuOK;
	u8 Local_u8TCCR0 = 0;
	if(Addr_pstr_Modulecfg != NULL)
	{
		Local_u8TCCR0 = Timer->TCCR0;
		Local_u8TCCR0 &= TMR02_MODE_RESET_MASK;
		Local_u8TCCR0 |= Addr_pstr_Modulecfg->Mode;
		Timer->TCCR0 = Local_u8TCCR0;
		
	
		Local_u8TCCR0 &= TMR02_CLK_OFF;
		Local_u8TCCR0 |= Addr_pstr_Modulecfg->Clock_Cfg;
		Timer->TCCR0 = Local_u8TCCR0;
		
	}
	else
	{
		Local_enuErrorstat = TMR_enuNullPtr;
	}
	return Local_enuErrorstat;
}

TMR_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u8 Copy_u8Clock,u16 * Add_pu8OV_Counts)
{
	TMR_enuErrorStatus Local_enuErrorStat = TMR_enuOK;
	f32 Local_OV_Time = 0,Local_NumberOfOVs = 0,Local_PreLoadValue = 0,Local_DecimalPortion = 0;
	u8 Local_TCCR0 = Timer->TCCR0;
	
	if((Local_TCCR0 & TMR02_MODE_CTC) == TMR02_MODE_CTC)
	{
		Timer->OCR0 = (u8)COMPARE_MATCH_VAL;
		*Add_pu8OV_Counts = ((u32)Copy_u16TickTime * (u32)TIME_MILISEC)/(u32)COMPARE_MATCH_VAL;
	}
	else
	{
		Local_OV_Time = (((f32)Copy_u8Clock/(f32)ATMEGA_F_CPU) * (f32)TIMER_RESOLUTION);
		Local_NumberOfOVs = ((f32)Copy_u16TickTime * (f32)TIME_MILISEC)/Local_OV_Time;
		Local_DecimalPortion = (Local_NumberOfOVs - (u32)Local_NumberOfOVs);
		Local_PreLoadValue = TIMER_RESOLUTION * (1-Local_DecimalPortion);
		*Add_pu8OV_Counts = ceil(Local_NumberOfOVs);
		Timer->TCNT0 = (u8)Local_PreLoadValue;
	}

	
	return Local_enuErrorStat;

}

TMR_enuErrorStatus TMR0_enuRegisterCallback_OV(TMR0cbf_t Cpy_TMR0Cbf)
{
	Timer->TIMSK |= TMR0_OV_INTERRUPT_ENABLE;
	TMR_enuErrorStatus Local_enuErrorstat = TMR_enuOK;
	if(Cpy_TMR0Cbf != NULL)
	{
		Timer0Cbf = Cpy_TMR0Cbf;
	}
	else
	{
		Local_enuErrorstat = TMR_enuNullPtr;
	}
	return Local_enuErrorstat;
}

TMR_enuErrorStatus TMR0_enuRegisterCallback_CTC(TMR0cbf_t Cpy_TMR0Cbf)
{
	Timer->TIMSK |= TMR0_OC_INTERRUPT_ENABLE;
	TMR_enuErrorStatus Local_enuErrorstat = TMR_enuOK;
	if(Cpy_TMR0Cbf != NULL)
	{
		Timer0Cbf = Cpy_TMR0Cbf;
	}
	else
	{
		Local_enuErrorstat = TMR_enuNullPtr;
	}
	return Local_enuErrorstat;
}

TMR_enuErrorStatus TMR0_SetCompareValue(u8 Cpy_TMR0_OCR0)
{
	TMR_enuErrorStatus Local_enuErrorstat = TMR_enuOK;
	if(Cpy_TMR0_OCR0 >= 0 && Cpy_TMR0_OCR0 < TIMER_RESOLUTION)
	{
		Timer->OCR0 = Cpy_TMR0_OCR0;
	}
	else
	{
		Local_enuErrorstat = TMR_enuNOK;
	}
	return Local_enuErrorstat;
}

void TMR1_Init_FastPWM_InputCapture(u8 Cpy_u8PeriodTime_MS)
{
	TMR_enuErrorStatus Local_enuErrorstat = TMR_enuOK;
	u8 Local_u8TCCR1A = Timer->TCCR1A;
	u8 Local_u8TCCR1B = Timer->TCCR1B;
	u16 Local_u16TopTicks = 0,Local_u16Ticktime = 1;
	
	Local_u8TCCR1A &= ~TMR1_FASTPWM_NON_INVERTINGMODE;
	Local_u8TCCR1A |= TMR1_FASTPWM_NON_INVERTINGMODE;
	
	Local_u8TCCR1B &= ~TMR1_MODE_FASTPWM_ICU;
	Local_u8TCCR1B |= TMR1_MODE_FASTPWM_ICU;
		
	Local_u8TCCR1A &= TMR02_CLK_OFF;
	Local_u8TCCR1A |= TMR0_CLK_PRESCALER_8;
	
	/*Assumed Pre-scaler to be /8*/
	
	Local_u16TopTicks = Cpy_u8PeriodTime_MS*TIME_MILISEC/Local_u16Ticktime;
	
	/*Set Top Counts*/
	Timer->ICR1 = Local_u16TopTicks;
	
	/*Start Timer 1*/
	Timer->TCCR1A = Local_u8TCCR1A;
	Timer->TCCR1B = Local_u8TCCR1B;
	return Local_enuErrorstat;

}

void TMR1_Set_CompareMatchA(u16 Cpy_u16OnTime_us)
{
	TMR_enuErrorStatus Local_enuErrorstat = TMR_enuOK;
	/*On Time*/
	Timer->OCR1A = Cpy_u16OnTime_us;
	return Local_enuErrorstat;
}

void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	Timer->TIFR |= TIFR_OCF0;	
	if(Timer0Cbf != NULL)
	{
		Timer0Cbf();
	}
	else
	{
		/*DO NOTHING*/
	}
	

}

void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	Timer->TIFR |= TIFR_TOV0;
	if(Timer0Cbf != NULL)
	{
		Timer0Cbf();
	}
	else
	{
		/*DO NOTHING*/
	}
	

}