/*********************************
LCD Interface File
*********************************/

#include "../../../LIB/Std_Types.h"
#include "LCD_piv.h"


#ifndef LCD_H
#define LCD_H

#define FUNCTION_SET_CMD					0b00111000
#define DISPLAY_ON_CMD						0b00001100
#define DISPLAY_ON_CURSOR_ON_CMD			0b00001110
#define DISPLAY_ON_CURSOR_ON_BLINK_ON_CMD	0b00001111
#define CLEAR_DISPLAY_CMD					0b00000001

#define LCD_XPOS_FIRST_LINE 0
#define LCD_XPOS_SECOND_LINE 1

#define LCD_YPOS0	0
#define LCD_YPOS1	1
#define LCD_YPOS2	2
#define LCD_YPOS3	3
#define LCD_YPOS4	4
#define LCD_YPOS5	5
#define LCD_YPOS6	6
#define LCD_YPOS7	7
#define LCD_YPOS8	8
#define LCD_YPOS9	9
#define LCD_YPOS10	10
#define LCD_YPOS11	11
#define LCD_YPOS12	12
#define LCD_YPOS13	13
#define LCD_YPOS14	14
#define LCD_YPOS15	15


#define LCD_BLOCK0	0
#define LCD_BLOCK1	1
#define LCD_BLOCK2	2
#define LCD_BLOCK3	3
#define LCD_BLOCK4	4
#define LCD_BLOCK5	5
#define LCD_BLOCK6	6
#define LCD_BLOCK7	7


typedef enum{
	
	LCD_enuOK,
	LCD_enu_NotOk,
	LCD_enu_Out_OF_DDRAM_Boundary,
	LCD_enu_Out_OF_CGRAM_Boundary,
	LCD_enu_Null_Pointer
	
}LCD_enuErrorStat_t;


/**/
void LCD_vidInit();

LCD_enuErrorStat_t LCD_enuSendCommand(u8 Cpy_u8Command);

LCD_enuErrorStat_t LCD_enuSendData(u8 Cpy_u8Data);

LCD_enuErrorStat_t LCD_enuGotoXY(u8 Cpy_u8Xpos, u8 Cpy_u8Ypos);

LCD_enuErrorStat_t LCD_enuWrite_Special_Pattern(u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos);

LCD_enuErrorStat_t LCD_enuWriteString (u8* Add_pu8String);

LCD_enuErrorStat_t LCD_enuWriteNumber (u16 Copy_u16Number);






#endif /*LCD_H*/
