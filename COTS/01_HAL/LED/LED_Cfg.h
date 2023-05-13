

#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "..\..\LIB\Std_Types.h"
#include "..\..\00_MCAL\DIO\DIO.h"

#define NUMBER_OF_LEDS 16

typedef enum
{
	LED_enuActiveLOW = 0,
	LED_enuActiveHIGH = 1

}LED_tenuConfig;


typedef struct
{
  LED_tenuConfig LED_ActiveLogic;
  DIO_tenuPins LED_PINVALUE;

}LED_strPinCfg_t;

extern const LED_strPinCfg_t LED_strPinCfg[NUMBER_OF_LEDS];

#endif /* LED_CFG_H_ */