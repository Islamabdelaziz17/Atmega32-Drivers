/*
 * SSEG_Cfg.h
 *
 * Created: 1/20/2023 2:51:47 PM
 *  Author: Islam
 */ 

#include "SSEG.h"
#include "..\..\..\LIB\Std_Types.h"
#include <stdlib.h>

#ifndef SSEG_CFG_H_
#define SSEG_CFG_H_

/*CONFIGURE THESE MACROS BASED ON YOUR CONFIGURARTIONS*/

#define SSEGS_NUMS 1			//NUMBER OF 7 SEGMENTS		
#define SSEG_MAX_DISPLAYED_NUM  pow(10,SSEGS_NUMS)
extern u8 SSEG_LookUpTable[10];
extern const SSEG_strPinCfg_t SSEG_strPinCfg[SSEGS_NUMS];

#endif /* SSEG_CFG_H_ */