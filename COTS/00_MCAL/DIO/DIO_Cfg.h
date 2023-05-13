/**************************/
/* DIO Configuration File */
/**************************/

#include "..\..\..\LIB\Std_Types.h"

#ifndef DIO_CFG_H
#define DIO_CFG_H

#define DIO_DIR_INPUT 0
#define DIO_DIR_OUTPUT 1

#define DIO_INPUT_PULL_UP 0 
#define DIO_INPUT_PULL_Down 1


typedef struct
{
    u8 DIO_PIN_DIR; 
    u8 DIO_InputStatus;
}DIO_strPinCfg_t;

extern const DIO_strPinCfg_t DIO_strPinCfg[32];

#endif /*DIO_CFG_H*/
