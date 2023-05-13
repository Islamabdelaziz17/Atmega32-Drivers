/*
 * Keypad_Cfg.h
 *
 * Created: 1/27/2023 3:04:10 PM
 *  Author: Islam
 */ 

#include "../../../LIB/Std_Types.h"

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4
#define KEYPAD_NUMS 1
#define LOW 0

extern const u8 Keypad_u8[KEYPAD_ROWS][KEYPAD_COLS];
extern const u8 Keypad_u8RowsConfig[KEYPAD_ROWS];
extern const u8 Keypad_u8ColsConfig[KEYPAD_COLS];

#endif /* KEYPAD_CFG_H_ */