#include "LM35.h" 
#include "LM35_cfg.h" 

#define LM35_OUT_VOLTAGE 10


Lm35_enuErrorStatus_t LM35_enuReadValue(u8 Cpy_u8LM35_Idx,u8*Cpy_u8ReadingVal)
{
	u16 Local_u16AdcResolution = 0;
	u16 Local_u16Lm35_millivolt = 0;
	Lm35_enuErrorStatus_t Local_enuErrorstat = LM35_enuOk;
	
	if((Cpy_u8LM35_Idx < NUMBER_OF_LM35_SENSORS) && (Cpy_u8LM35_Idx >= 0))
	{
		Local_enuErrorstat = ADC_enuGetConvertedData(&Local_u16AdcResolution,LM35_strConfig[Cpy_u8LM35_Idx].Channel_Number);
		
		if(Local_enuErrorstat == LM35_enuOk)
		{
			Local_u16Lm35_millivolt = ((u32)Local_u16AdcResolution*5000UL)/1024;
			*Cpy_u8ReadingVal = Local_u16Lm35_millivolt/LM35_OUT_VOLTAGE;
		}
	}
	else
	{
		Local_enuErrorstat = LM35_enuNotOk;
	}
	return Local_enuErrorstat;
}