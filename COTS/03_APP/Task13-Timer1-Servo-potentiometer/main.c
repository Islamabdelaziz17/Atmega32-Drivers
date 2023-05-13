/*
* Servo_Pot.c
*
* Created: 3/11/2023 3:29:48 PM
* Author : islam
*/
#include "DIO.h"
#include "ADC.h"
#include "Servo.h"
#include <util/delay.h>

int main(void)
{
	u16 Local_ConvertedReading = 0;
	
	DIO_enuInit();
	
	ADC_vidEnable();
	ADC_enuSelectChannel(ADC_SINGLE_ENDED_CHANNEL0);
	ADC_enuSetReferenceClock(ADC_INTERNAL_VCC_5);
	ADC_enuSetJustification(ADC_RIGHT_JUSTIFIED);
	ADC_enuSetPrescaler(ADC_PRESCALER_DIV_BY_8);
	
	Servo_vidInit();
	
	while (1)
	{
		
		ADC_enuGetConvertedData(&Local_ConvertedReading,ADC_SINGLE_ENDED_CHANNEL0);
		
		Local_ConvertedReading /= 6;
		
		if(Local_ConvertedReading <= 0)
		{
			Servo_enuSetAngle(0);
		}
		else if(Local_ConvertedReading >= 180)
		{
			Servo_enuSetAngle(180);
		}
		else
		{
			Servo_enuSetAngle(Local_ConvertedReading);
		}
		
		
		
	}
}

