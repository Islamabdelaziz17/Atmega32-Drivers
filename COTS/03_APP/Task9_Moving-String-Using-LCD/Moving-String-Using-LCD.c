/*
*Moving-String-Using-LCD.c
*
* Created: 2/10/2023 2:16:48 PM
* Author : islam
*/
#include "../../00_MCAL/DIO/DIO.h"
#include "../../01_HAL/SWITCH/SWITCH.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "util/delay.h"


#define UP		0
#define LEFT	1
#define RIGHT	2
#define DOWN	3

u8 LCD_M_Block0[8] = {
	0x00,
	0x00,
	0x06,
	0x06,
	0x04,
	0x04,
	0x00,
	0x00
};


u8 LCD_LA_Block1[8] = {
	0x00,
	0x02,
	0x02,
	0x0A,
	0x06,
	0x1F,
	0x00,
	0x00
};

u8 LCD_S_Block2[8] = {
	0x00,
	0x00,
	0x00,
	0x15,
	0x15,
	0x1F,
	0x00,
	0x00
};

u8 LCD_I_Block3[8] = {
	0x00,
	0x08,
	0x08,
	0x08,
	0x08,
	0x08,
	0x00,
	0x00
};

int main(void)
{
	u8 Local_u8ButtonVal;
	s8 Local_u8StepCounter;
	u8 Local_u8LcdSelectedLine;
	
	Local_u8ButtonVal = 0;
	Local_u8StepCounter = 5;
	Local_u8LcdSelectedLine = 0;
	
	DIO_enuInit();
	LCD_vidInit();
	LCD_enuWrite_Special_Pattern(LCD_M_Block0,0,LCD_XPOS_FIRST_LINE,Local_u8StepCounter);
	LCD_enuWrite_Special_Pattern(LCD_LA_Block1,1,LCD_XPOS_FIRST_LINE,Local_u8StepCounter+1);
	LCD_enuWrite_Special_Pattern(LCD_S_Block2,2,LCD_XPOS_FIRST_LINE,Local_u8StepCounter+2);
	LCD_enuWrite_Special_Pattern(LCD_I_Block3,3,LCD_XPOS_FIRST_LINE,Local_u8StepCounter+3);
	while (1)
	{
		_delay_ms(150);
		SWITCH_enuGetSwitchValue(UP,&Local_u8ButtonVal);
		if(Local_u8ButtonVal == 0)
		{
			LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
			LCD_enuWrite_Special_Pattern(LCD_M_Block0,0,LCD_XPOS_FIRST_LINE,Local_u8StepCounter);
			LCD_enuWrite_Special_Pattern(LCD_LA_Block1,1,LCD_XPOS_FIRST_LINE,Local_u8StepCounter+1);
			LCD_enuWrite_Special_Pattern(LCD_S_Block2,2,LCD_XPOS_FIRST_LINE,Local_u8StepCounter+2);
			LCD_enuWrite_Special_Pattern(LCD_I_Block3,3,LCD_XPOS_FIRST_LINE,Local_u8StepCounter+3);
			Local_u8LcdSelectedLine = LCD_XPOS_FIRST_LINE;
			
		}
		SWITCH_enuGetSwitchValue(DOWN,&Local_u8ButtonVal);
		if(Local_u8ButtonVal == 0)
		{
			LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
			LCD_enuWrite_Special_Pattern(LCD_M_Block0,0,LCD_XPOS_SECOND_LINE,Local_u8StepCounter);
			LCD_enuWrite_Special_Pattern(LCD_LA_Block1,1,LCD_XPOS_SECOND_LINE,Local_u8StepCounter+1);
			LCD_enuWrite_Special_Pattern(LCD_S_Block2,2,LCD_XPOS_SECOND_LINE,Local_u8StepCounter+2);
			LCD_enuWrite_Special_Pattern(LCD_I_Block3,3,LCD_XPOS_SECOND_LINE,Local_u8StepCounter+3);
			Local_u8LcdSelectedLine = LCD_XPOS_SECOND_LINE;
			
		}
		SWITCH_enuGetSwitchValue(LEFT,&Local_u8ButtonVal);
		if(Local_u8ButtonVal == 0)
		{
			--Local_u8StepCounter;
			if((Local_u8StepCounter) < LCD_DDRAM_LINE_1_START)
			{
				Local_u8StepCounter = LCD_DDRAM_LINE_1_START;
			}
			LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
			LCD_enuWrite_Special_Pattern(LCD_M_Block0,0,Local_u8LcdSelectedLine,Local_u8StepCounter);
			LCD_enuWrite_Special_Pattern(LCD_LA_Block1,1,Local_u8LcdSelectedLine,Local_u8StepCounter+1);
			LCD_enuWrite_Special_Pattern(LCD_S_Block2,2,Local_u8LcdSelectedLine,Local_u8StepCounter+2);
			LCD_enuWrite_Special_Pattern(LCD_I_Block3,3,Local_u8LcdSelectedLine,Local_u8StepCounter+3);
			
			
		}
		SWITCH_enuGetSwitchValue(RIGHT,&Local_u8ButtonVal);
		if(Local_u8ButtonVal == 0)
		{
			Local_u8StepCounter++;
			if(Local_u8LcdSelectedLine == LCD_XPOS_FIRST_LINE)
			{
				if((Local_u8StepCounter+3) > LCD_DDRAM_LINE_1_END)
				{
					Local_u8StepCounter = LCD_DDRAM_LINE_1_END-3;
				}
				else
				{
					/*Do Nothing*/
				}
			}
			else if(Local_u8LcdSelectedLine == LCD_XPOS_SECOND_LINE)
			{
				if((Local_u8StepCounter+3) > LCD_DDRAM_LINE_1_END)
				{
					Local_u8StepCounter = LCD_DDRAM_LINE_1_END-3;
				}
				else
				{
					/*Do Nothing*/
				}
			}
			else
			{
				/*Do Nothing*/
			}
			LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
			LCD_enuWrite_Special_Pattern(LCD_M_Block0,0,Local_u8LcdSelectedLine,Local_u8StepCounter);
			LCD_enuWrite_Special_Pattern(LCD_LA_Block1,1,Local_u8LcdSelectedLine,Local_u8StepCounter+1);
			LCD_enuWrite_Special_Pattern(LCD_S_Block2,2,Local_u8LcdSelectedLine,Local_u8StepCounter+2);
			LCD_enuWrite_Special_Pattern(LCD_I_Block3,3,Local_u8LcdSelectedLine,Local_u8StepCounter+3);
			
		}
		
	}
}

