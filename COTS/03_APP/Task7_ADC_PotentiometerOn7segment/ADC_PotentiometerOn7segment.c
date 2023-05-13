/*
* ADC.c
*
* Created: 2/5/2023 11:21:54 AM
* Author : Islam
*/
#include "ADC.h"
#include "../../01_HAL/SSEG/SSEG.h"
#include "../../01_HAL/SSEG/SSEG_Cfg.h"

int main(void)
{
	u16 Local_ConvertedReading = 0;
	ADC_enuErrorStatus_t Local_ErrorStat = ADC_enuOK;
	u8 Local_ClearFlag = 1;
	DIO_enuInit();
	
	ADC_vidEnable();
	ADC_enuSelectChannel(ADC_SINGLE_ENDED_CHANNEL0);
	ADC_enuSetReferenceClock(ADC_INTERNAL_VCC_5);
	ADC_enuSetJustification(ADC_RIGHT_JUSTIFIED);
	ADC_enuSetPrescaler(ADC_PRESCALER_DIV_BY_128);
	
	while (1)
	{
		ADC_enuGetConvertedData(&Local_ConvertedReading,ADC_SINGLE_ENDED_CHANNEL0);
		Local_ConvertedReading /= 10;
		if(Local_ConvertedReading<=0)
		{
			if(Local_ClearFlag)
			{
				SSEG_enuClearDisplay(0);
				SSEG_enuClearDisplay(1);
				Local_ClearFlag = 0;
			}
			SSEG_enuDisplay(0,0);
			SSEG_enuDisplay(0,1);
			
		}
		else if(Local_ConvertedReading>=99)
		{
			if(Local_ClearFlag != 1)
			{
				SSEG_enuClearDisplay(0);
				SSEG_enuClearDisplay(1);
				Local_ClearFlag = 1;
			}
			SSEG_enuDisplay(9,0);
			SSEG_enuDisplay(9,1);
			
		}
		else
		{
			if(Local_ClearFlag != 1)
			{
				SSEG_enuClearDisplay(0);
				SSEG_enuClearDisplay(1);
				Local_ClearFlag = 1;
			}
			SSEG_enuDisplay(Local_ConvertedReading%10,1);
			SSEG_enuDisplay(Local_ConvertedReading/10,0);
		}


	}
}

