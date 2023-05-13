/********************************* 
    ADC Interface File   
*********************************/ 
#include "../../../LIB/Std_types.h"

#ifndef ADC_H 
#define ADC_H 

//ADC SINGLE ENDED INPUT CONFIGS
#define ADC_SINGLE_ENDED_CHANNEL0 0x00
#define ADC_SINGLE_ENDED_CHANNEL1 0x01
#define ADC_SINGLE_ENDED_CHANNEL2 0x02
#define ADC_SINGLE_ENDED_CHANNEL3 0x03
#define ADC_SINGLE_ENDED_CHANNEL4 0x04
#define ADC_SINGLE_ENDED_CHANNEL5 0x05
#define ADC_SINGLE_ENDED_CHANNEL6 0x06
#define ADC_SINGLE_ENDED_CHANNEL7 0x07

//LEFT AND RIGHT JUSTIFICATION MASKS FOR THE ADCH:ADCL 
#define ADC_LEFT_JUSTIFIED  0x20
#define ADC_RIGHT_JUSTIFIED 0x00

//REFERENCE CLOCK SELECTION OPTIONS
#define ADC_EXTERNAL_VREF     0x00
#define ADC_INTERNAL_VCC_5    0x40
#define ADC_INTERNAL_VCC_2_56 0xC0


//PRESCALER DIVISION SELECTION OPTIONS
#define ADC_PRESCALER_DIV_BY_2   0x01
#define ADC_PRESCALER_DIV_BY_4   0x02
#define ADC_PRESCALER_DIV_BY_8   0x03
#define ADC_PRESCALER_DIV_BY_16  0x04
#define ADC_PRESCALER_DIV_BY_32  0x05
#define ADC_PRESCALER_DIV_BY_64  0x06
#define ADC_PRESCALER_DIV_BY_128 0x07



//ADC AUTO TRIGGER ENABLE OPTIONS --> SFIOR REGS 
#define ADC_TRIGGER_FREE_RUNNING_MODE		0x00
#define ADC_TRIGGER_ANALOG_COMPARATOR		0x10
#define ADC_TRIGGER_XTI0					0x20
#define ADC_TRIGGER_TIM0_COMPARE_MATCH		0x30
#define ADC_TRIGGER_TIM0_OVERFLOW			0x40
#define ADC_TRIGGER_TIM1_COMPARE_MATCH_B	0x50
#define ADC_TRIGGER_TIM1_OVERFLOW 			0x60
#define ADC_TRIGGER_TIM1_CAPTURE  			0x70


 
typedef enum
{
	ADC_enuOK,
	ADC_enuNotOk	 
}ADC_enuErrorStatus_t;
 
/*---- Enables ADC PERIPHERAL------*/
/*----------Return void------------*/
void ADC_vidEnable();
/*__________________________________________________*/

/*---- Disables ADC PERIPHERAL------*/
/*----------Return void------------*/
void ADC_vidDisable();
/*__________________________________________________*/

/*---- GET DATA REGISTER JUSTIFICATION (RIGHT||LEFT)------*/
/*----------Return void------------*/
static void ADC_vidGetDataJustification(u8* Adc_pu8JustificationType);
/*__________________________________________________*/

/*---- Starts the Conversion ------*/
/*----------Returns Error Status------------*/
ADC_enuErrorStatus_t ADC_enuStartCoversion();
/*__________________________________________________*/

/*-------------- Enable Auto Trigger -----------*/
/*----------Returns Void-------------------*/
void ADC_enuEnableAutoTrigger();
/*__________________________________________________*/

/*-------------- Enable ADC Interrupt -----------*/
/*----------Returns Void-------------------*/
void ADC_enuEnableInterrupt();
/*__________________________________________________*/

/*---- Set pre-scaler Division Value ------*/
/*-----PRESCALER DIVISION SELECTION OPTIONS

		1-ADC_PRESCALER_DIV_BY_2_MASK
		2-ADC_PRESCALER_DIV_BY_4_MASK
		3-ADC_PRESCALER_DIV_BY_8_MASK
		4-ADC_PRESCALER_DIV_BY_16_MASK
		5-ADC_PRESCALER_DIV_BY_32_MASK
		6-ADC_PRESCALER_DIV_BY_64_MASK
		7-ADC_PRESCALER_DIV_BY_128_MASK
*/
/*----------Returns Error Status------------------*/

ADC_enuErrorStatus_t ADC_enuSetPrescaler(u8 ADC_Prescaler);
/*__________________________________________________*/

/*-------------- Select Reference Clock -----------*/
/*-----REFERENCE CLOCK SELECTION OPTIONS

		1-ADC_EXTERNAL_VREF
		2-ADC_INTERNAL_VCC_5
		3-ADC_INTERNAL_VCC_2_56
*/
/*----------Returns Error Status-------------------*/

ADC_enuErrorStatus_t ADC_enuSetReferenceClock(u8 ADC_ReferenceClock);
/*__________________________________________________*/

/*-------------- Set Data Registers Justification -----------*/
/*-----Justification Options:

		1-ADC_LEFT_JUSTIFIED_MASK
		2-ADC_RIGHT_JUSTIFIED_MASK
*/
/*----------Returns Error status-------------------*/
ADC_enuErrorStatus_t ADC_enuSetJustification(u8 ADC_JustificationOption);
/*__________________________________________________*/

/*-------------- Select ADC Channel -----------*/
/*-----Selection Options:

		1-ADC_SINGLE_ENDED_CHANNEL0
		2-ADC_SINGLE_ENDED_CHANNEL1
		3-ADC_SINGLE_ENDED_CHANNEL2
		4-ADC_SINGLE_ENDED_CHANNEL3
		5-ADC_SINGLE_ENDED_CHANNEL4
		6-ADC_SINGLE_ENDED_CHANNEL5
		7-ADC_SINGLE_ENDED_CHANNEL6
		8-ADC_SINGLE_ENDED_CHANNEL6
*/
/*----------Returns Error status-------------------*/

ADC_enuErrorStatus_t ADC_enuSelectChannel(u8 ADC_Channel);
/*__________________________________________________*/

/*-------------- Read Converted Data -----------*/
/*----------Returns Error status & The data read -------------------*/
ADC_enuErrorStatus_t ADC_enuGetConvertedData(u16* ADC_Reading);
/*__________________________________________________*/

/*-------------- Check if Conversion is done or not -----------*/
/*----------Returns Error status-------------------*/
static ADC_enuErrorStatus_t ADC_enuCheckConversion();
 
 /*__________________________________________________*/

 /*-------------- Trigger the Conversion of the ADC on specific mode  -----------*/
 /*-------Select Options
	ADC_TRIGGER_FREE_RUNNING_MODE
	ADC_TRIGGER_ANALOG_COMPARATOR
	ADC_TRIGGER_XTI0
	ADC_TRIGGER_TIM0_COMPARE_MATCH
	ADC_TRIGGER_TIM0_OVERFLOW
	ADC_TRIGGER_TIM1_COMPARE_MATCH_B
	ADC_TRIGGER_TIM1_OVERFLOW
	ADC_TRIGGER_TIM1_CAPTURE
 */
 /*----------Returns Error status-------------------*/
 ADC_enuErrorStatus_t ADC_enuSetTriggerMode(u8 ADC_AutoTriggerMode);
 
 
#endif /*ADC_H*/ 
