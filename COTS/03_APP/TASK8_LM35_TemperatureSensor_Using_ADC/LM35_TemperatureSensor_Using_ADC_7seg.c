/*
 * LM35_TemperatureSensor_Using_ADC_7seg.c
 *
 * Created: 2/8/2023 11:30:13 AM
 * Author : islam
 */ 
#include "../../../00_MCAL/ADC_Driver/ADC/ADC.h"
#include "../../01_HAL/SSEG/SSEG.h"
#include "../../01_HAL/SSEG/SSEG_Cfg.h"
#include "LM35.h"
#include "LM35_cfg.h"

u8 Local_Lm35Reading = 1;
u8 Local_PrevLm35Reading = 0;

int main(void)
{
	
    DIO_enuInit();
	ADC_vidEnable();
	ADC_enuSelectChannel(ADC_SINGLE_ENDED_CHANNEL0);
	ADC_enuSetReferenceClock(ADC_INTERNAL_VCC_5);
	ADC_enuSetJustification(ADC_RIGHT_JUSTIFIED);
	ADC_enuSetPrescaler(ADC_PRESCALER_DIV_BY_128);
    while (1) 
    {
		LM35_enuReadValue(0,&Local_Lm35Reading);
		if(Local_Lm35Reading != Local_PrevLm35Reading)
		{	
			SSEG_enuClearDisplay(0);
			SSEG_enuClearDisplay(1);
			Local_PrevLm35Reading = Local_Lm35Reading;
		}
		SSEG_enuDisplay(Local_Lm35Reading%10,1);
		SSEG_enuDisplay(Local_Lm35Reading/10,0);
    }
}

