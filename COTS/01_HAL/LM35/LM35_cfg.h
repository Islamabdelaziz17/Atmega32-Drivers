/********************************* 
    LM35 Configuration File   
*********************************/ 
#include "../../../LIB/Std_Types.h"
#ifndef LM35_CFG_H 
#define LM35_CFG_H 

#define NUMBER_OF_LM35_SENSORS 1

#define LM35_REFERENCE_VOLT INTERNAL_VCC_5

typedef enum{
	
	Lm35_enuADC_Channel0 = 0,
	Lm35_enuADC_Channel1,
	Lm35_enuADC_Channel2,
	Lm35_enuADC_Channel3,
	Lm35_enuADC_Channel4,
	Lm35_enuADC_Channel5,
	Lm35_enuADC_Channel6,
	Lm35_enuADC_Channel7
		
}Lm35_enuADChannnel_t;

typedef struct{
	
	Lm35_enuADChannnel_t Channel_Number;
	
}LM35_strConfig_t;

extern const LM35_strConfig_t LM35_strConfig[NUMBER_OF_LM35_SENSORS];
 
#endif /*LM35_CFG_H*/ 
