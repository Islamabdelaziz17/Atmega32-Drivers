/*
* PingPong-LCD.c
*
* Created: 2/10/2023 2:16:48 PM
* Author : islam
*/
#include "../../00_MCAL/DIO/DIO.h"
#include "../../01_HAL/SWITCH/SWITCH.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "util/delay.h"


#define LEFT	0
#define RIGHT	3
#define ONE		1

u8 LCD_PingPongStick_Block0[8] = {
	0x00,
	0x18,
	0x18,
	0x18,
	0x18,
	0x18,
	0x18,
	0x00
};

u8 LCD_Ball_Block1[8] ={
	0x00,
	0x0E,
	0x11,
	0x11,
	0x11,
	0x11,
	0x0E,
	0x00
};


int main(void)
{
	u8 Local_u8ButtonVal;
	s8 Local_u8StepCounter;
	u8 Local_u8LeftStickPos,Local_u8RightStickPos,Local_u8BallPos = 0,
	Local_Player1Counter,Local_Player2Counter,Local_u8flag;
	
	
	Local_u8ButtonVal = 0;
	Local_u8StepCounter = 2;
	Local_u8LeftStickPos = 0;
	Local_u8LeftStickPos = 0;
	Local_Player1Counter = 0;
	Local_Player2Counter = 0;
	Local_u8flag = 0;

	DIO_enuInit();
	LCD_vidInit();
	
	
	while(1)
	{
		_delay_ms(100);
		SWITCH_enuGetSwitchValue(LEFT,&Local_u8ButtonVal);
		if(Local_u8ButtonVal == 0)
		{
			Local_u8LeftStickPos ^= ONE;
		}
		SWITCH_enuGetSwitchValue(RIGHT,&Local_u8ButtonVal);
		if(Local_u8ButtonVal == 0)
		{
			Local_u8RightStickPos ^= ONE;
		}
		LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
		LCD_enuWrite_Special_Pattern(LCD_PingPongStick_Block0,0,Local_u8LeftStickPos,LCD_YPOS0);
		LCD_enuWrite_Special_Pattern(LCD_PingPongStick_Block0,0,Local_u8RightStickPos,LCD_YPOS15);
		
		LCD_enuGotoXY(LCD_XPOS_FIRST_LINE,LCD_YPOS2);
		LCD_enuWriteNumber(Local_Player1Counter);
		LCD_enuGotoXY(LCD_XPOS_FIRST_LINE,LCD_YPOS13);
		LCD_enuWriteNumber(Local_Player2Counter);
		
		Local_u8BallPos ^= ONE;
		LCD_enuWrite_Special_Pattern(LCD_Ball_Block1,1,Local_u8BallPos,Local_u8StepCounter);
		
		if(Local_u8BallPos != Local_u8LeftStickPos)
		{
			if(Local_u8StepCounter == LCD_YPOS0)
			{
				Local_Player2Counter++;
				Local_u8StepCounter++;
			}
		}
		else
		{
			/*Do Nothing*/
		}
		
		if(Local_u8BallPos != Local_u8RightStickPos)
		{
			if(Local_u8StepCounter == LCD_YPOS15)
			{
				Local_Player1Counter++;
				Local_u8StepCounter++;
			}
		}
		else
		{
			/*Do Nothing*/
		}
		
		if(Local_u8flag == 0)
		{
			Local_u8StepCounter++;
		}
		else
		{
			Local_u8StepCounter--;
			if(Local_u8StepCounter == LCD_DDRAM_LINE_1_START)
			{
				Local_u8flag = 0;
			}
		}
		if(Local_u8StepCounter > LCD_DDRAM_LINE_1_END)
		{
			Local_u8flag = 1;
		}
		if(Local_Player1Counter == 3)
		{
			LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
			LCD_enuWriteString("Player 1 wins :>");
			_delay_ms(5000);
			Local_Player1Counter = 0;
			Local_Player2Counter = 0;
		}
		if(Local_Player2Counter == 3)
		{
			LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
			LCD_enuWriteString("Player 2 wins :>");
			_delay_ms(5000);
			Local_Player2Counter = 0;
			Local_Player1Counter = 0;
		}
		
	}
	
	
}

