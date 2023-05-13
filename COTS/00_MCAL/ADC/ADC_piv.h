/********************************* 
    ADC Private File   
*********************************/ 
 
#ifndef ADC_PIV_H 
#define ADC_PIV_H 
 
#define ADC0_BASEADDRESS			0x24
  
#define ADC_CHANNELS_MASK			0x70
#define ADC_PRESCALER_MASK			0xFC
#define ADC_REFERECE_CLOCK_MASK		0x3F
#define ADC_JUSTIFICATION_MASK		0xDF
#define ADC_TRIGGER_MODE_MASK       0x1F

#define ADC_START_CONVERSION		0x40
#define ADC_ENABLE					0x80
#define ADC_AUTO_TRIGGER_ENABLE		0X20
#define ADC_ENABLE_INTERRUPT		0x04
#define ADC_CONVERSION_STATUS       0x10

#define SFIOR	*((volatile u8*)0x50)
 typedef struct 
 {
	 u8 ADCL;
	 u8 ADCH;
	 u8 ADCSRA;
	 u8 ADMUX;
	 
 }ADC_t;
 
volatile ADC_t * const ADC0 = (volatile ADC_t*) ADC0_BASEADDRESS;

 
#endif /*ADC_PIV_H*/ 
