#include "ADC.h" 
#include "ADC_piv.h" 

#define TIMEOUT_ADC         500
static u8 Global_u8ADC_Enabled;

void ADC_vidEnable()
{
	u8 Local_u8ADCSRA = 0;
	Local_u8ADCSRA = ADC0->ADCSRA;
	Local_u8ADCSRA |= ADC_ENABLE;
	ADC0->ADCSRA = Local_u8ADCSRA;
	Global_u8ADC_Enabled = 1;
}

void ADC_vidDisable()
{
	u8 Local_u8ADCSRA = 0;
	Local_u8ADCSRA = ADC0->ADCSRA;
	Local_u8ADCSRA &= ~(ADC_ENABLE);
	ADC0->ADCSRA = Local_u8ADCSRA;
	Global_u8ADC_Enabled = 0;
}

ADC_enuErrorStatus_t ADC_enuStartCoversion()
{
	ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK;
	if(Global_u8ADC_Enabled)
	{
		u8 Local_u8ADCSRA = 0;
		Local_u8ADCSRA = ADC0->ADCSRA;
		Local_u8ADCSRA |= ADC_START_CONVERSION;
		ADC0->ADCSRA = Local_u8ADCSRA;
	}
	else
	{
		Local_enuErrorStat = ADC_enuNotOk;
	}
	return Local_enuErrorStat;
}

void ADC_enuEnableAutoTrigger()
{
	u8 Local_u8ADCSRA = 0;
	Local_u8ADCSRA = ADC0->ADCSRA;
	Local_u8ADCSRA |= ADC_AUTO_TRIGGER_ENABLE;
	ADC0->ADCSRA = Local_u8ADCSRA;
}

void ADC_enuEnableInterrupt()
{
	u8 Local_u8ADCSRA = 0;
	Local_u8ADCSRA = ADC0->ADCSRA;
	Local_u8ADCSRA |= ADC_ENABLE_INTERRUPT;
	ADC0->ADCSRA = Local_u8ADCSRA;
}

ADC_enuErrorStatus_t ADC_enuSetPrescaler(u8 ADC_Prescaler)
{
	ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK;
	if(ADC_Prescaler >= ADC_PRESCALER_DIV_BY_2 && ADC_Prescaler <= ADC_PRESCALER_DIV_BY_128)
	{
		u8 Local_u8ADCSRA = 0;
		Local_u8ADCSRA = ADC0->ADCSRA;
		Local_u8ADCSRA &= (ADC_PRESCALER_MASK);
		Local_u8ADCSRA |= ADC_Prescaler;
		ADC0->ADCSRA = Local_u8ADCSRA;
	}
	else
	{
		Local_enuErrorStat = ADC_enuNotOk;
	}
	return Local_enuErrorStat;
}

ADC_enuErrorStatus_t ADC_enuSetReferenceClock(u8 ADC_ReferenceClock)
{
		ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK;
		if(ADC_ReferenceClock == ADC_EXTERNAL_VREF || ADC_ReferenceClock == ADC_INTERNAL_VCC_5 || ADC_ReferenceClock == ADC_INTERNAL_VCC_2_56)
		{
			u8 Local_u8ADMUX = 0;
			Local_u8ADMUX = ADC0->ADMUX;
			Local_u8ADMUX &= (ADC_REFERECE_CLOCK_MASK);
			Local_u8ADMUX |= ADC_ReferenceClock;
			ADC0->ADMUX = Local_u8ADMUX;
		}
		else
		{
			Local_enuErrorStat = ADC_enuNotOk;
		}
		return Local_enuErrorStat;
}

ADC_enuErrorStatus_t ADC_enuSetJustification(u8 ADC_JustificationOption)
{
	ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK;
	if(ADC_JustificationOption == ADC_LEFT_JUSTIFIED || ADC_JustificationOption == ADC_RIGHT_JUSTIFIED)
	{
		u8 Local_u8ADMUX = 0;
		Local_u8ADMUX = ADC0->ADMUX;
		Local_u8ADMUX &= (ADC_JUSTIFICATION_MASK);
		Local_u8ADMUX |= ADC_JustificationOption;
		ADC0->ADMUX = Local_u8ADMUX;
	}
	else
	{
		Local_enuErrorStat = ADC_enuNotOk;
	}
	return Local_enuErrorStat;
}

ADC_enuErrorStatus_t ADC_enuSelectChannel(u8 ADC_Channel)
{
	ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK;
	if(ADC_Channel >= ADC_SINGLE_ENDED_CHANNEL0 && ADC_Channel <= ADC_SINGLE_ENDED_CHANNEL7)
	{
		u8 Local_u8ADMUX = 0;
		Local_u8ADMUX = ADC0->ADMUX;
		Local_u8ADMUX &= (ADC_CHANNELS_MASK);
		Local_u8ADMUX |= ADC_Channel;
		ADC0->ADMUX = Local_u8ADMUX;
	}
	else
	{
		Local_enuErrorStat = ADC_enuNotOk;
	}
	return Local_enuErrorStat;
	
}

ADC_enuErrorStatus_t ADC_enuGetConvertedData(u16* ADC_Reading)
{
	ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK,Local_CheckConversionStatus;
	u8 Local_u8JustificationType = 0;
	u16 Local_ADC_Reading = 0;
	if(Global_u8ADC_Enabled)
	{
		Local_CheckConversionStatus = ADC_enuCheckConversion();
		
		if(Local_CheckConversionStatus == ADC_enuOK)
		{
			ADC_vidGetDataJustification(&Local_u8JustificationType);
			if(Local_u8JustificationType == ADC_LEFT_JUSTIFIED)
			{
				Local_ADC_Reading = ((ADC0->ADCL >> 6) | (ADC0->ADCH << 2));
			}
			else 
			{
				 Local_ADC_Reading = ((ADC0->ADCL) | (ADC0->ADCH << 8));
			}
			*ADC_Reading = Local_ADC_Reading;
		}
		else
		{
			Local_enuErrorStat = ADC_enuNotOk;
		}
	}
	else
	{
		Local_enuErrorStat = ADC_enuNotOk;
	}
	
	return Local_enuErrorStat;	
	
}
static ADC_enuErrorStatus_t ADC_enuCheckConversion()
{
	ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuNotOk;
	u8 Local_TimeOut = 0;
	while((!(ADC0->ADCSRA & ADC_CONVERSION_STATUS)) && Local_TimeOut <= TIMEOUT_ADC)
	{
		Local_TimeOut++;
	}
	if(ADC0->ADCSRA & ADC_CONVERSION_STATUS)
	{
		Local_enuErrorStat = ADC_enuOK;
		ADC0->ADCSRA |= ADC_CONVERSION_STATUS; 
	}
	return Local_enuErrorStat;
}

static void ADC_vidGetDataJustification(u8* Adc_pu8JustificationType)
{
	*Adc_pu8JustificationType = (ADC0->ADMUX & ADC_LEFT_JUSTIFIED);
}

 ADC_enuErrorStatus_t ADC_enuSetTriggerMode(u8 ADC_AutoTriggerMode)
 {
	 ADC_enuErrorStatus_t Local_enuErrorStat = ADC_enuOK;
	 u8 Local_u8_SFIOR = 0;
	 //if(ADC_AutoTriggerMode >= ADC_TRIGGER_ANALOG_COMPARATOR && ADC_AutoTriggerMode <= ADC_TRIGGER_TIM1_CAPTURE)
	 if(Global_u8ADC_Enabled)
	 {
		  Local_u8_SFIOR = SFIOR;
		  Local_u8_SFIOR &= ADC_TRIGGER_MODE_MASK;
		  Local_u8_SFIOR |= ADC_AutoTriggerMode;
		  SFIOR = Local_u8_SFIOR;
	 }
	 else
	 {
		 Local_enuErrorStat = ADC_enuNotOk;
	 }
	return Local_enuErrorStat;
	 
 }