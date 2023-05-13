#define F_CPU 8000000UL
#include "LCD.h"
#include "LCD_cfg.h"
#include "util/delay.h"

void LCD_vidInit()
{
	LCD_enuSendCommand(FUNCTION_SET_CMD);
	LCD_enuSendCommand(DISPLAY_ON_CMD);
	LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
}

LCD_enuErrorStat_t LCD_enuSendCommand(u8 Cpy_u8Command)
{
	u8 Local_u8Command = Cpy_u8Command,Local_u8Counter = 0;
	LCD_enuErrorStat_t Local_enuLCDErrorstat = LCD_enuOK;
	
	Local_enuLCDErrorstat = DIO_enuClearPin(LCD_enuRS);
	
	Local_enuLCDErrorstat = DIO_enuClearPin(LCD_enuRW);
	
	for(Local_u8Counter = 0;Local_u8Counter<8;Local_u8Counter++)
	{
		/*IF BIT IS HIGH SET THE BIT USING DIO_SETPIN*/
		if((Local_u8Command & 0x01) == 1)
		{
			Local_enuLCDErrorstat = DIO_enuSetPin(LCD_strCfg[0].Lcd_pu8Pins[Local_u8Counter]);
		}
		/*IF BIT IS LOW CLEAR THE BIT USING DIO_CLEARIN*/
		else
		{
			Local_enuLCDErrorstat = DIO_enuClearPin(LCD_strCfg[0].Lcd_pu8Pins[Local_u8Counter]);
		}
		//SHIFT LEFT BY ONE TO REMOVE THE CHECKED CURRENT BIT
		Local_u8Command = (Local_u8Command>>1);
		//INCREAMENT THE COUNTER OF Bits CHECKED
	}
	
	Local_enuLCDErrorstat = DIO_enuSetPin(LCD_enuEnable);
	_delay_ms(2);
	Local_enuLCDErrorstat = DIO_enuClearPin(LCD_enuEnable);
	
	return Local_enuLCDErrorstat;
	
}

LCD_enuErrorStat_t LCD_enuSendData(u8 Cpy_u8Data)
{
	u8 Local_u8Data = Cpy_u8Data,Local_u8Counter = 0;
	LCD_enuErrorStat_t Local_enuLCDErrorstat = LCD_enuOK;
	
	Local_enuLCDErrorstat = DIO_enuSetPin(LCD_enuRS);
	
	Local_enuLCDErrorstat = DIO_enuClearPin(LCD_enuRW);
	
	for(Local_u8Counter = 0;Local_u8Counter<8;Local_u8Counter++)
	{
		/*IF BIT IS HIGH SET THE BIT USING DIO_SETPIN*/
		if((Local_u8Data & 0x01) == 1)
		{
			Local_enuLCDErrorstat = DIO_enuSetPin(Local_u8Counter);
		}
		/*IF BIT IS LOW CLEAR THE BIT USING DIO_CLEARIN*/
		else
		{
			Local_enuLCDErrorstat = DIO_enuClearPin(Local_u8Counter);
		}
		//SHIFT LEFT BY ONE TO REMOVE THE CHECKED CURRENT BIT
		Local_u8Data = (Local_u8Data>>1);
		//INCREAMENT THE COUNTER OF Bits CHECKED
	}
	
	Local_enuLCDErrorstat = DIO_enuSetPin(LCD_enuEnable);
	_delay_ms(2);
	Local_enuLCDErrorstat = DIO_enuClearPin(LCD_enuEnable);
	
	return Local_enuLCDErrorstat;
}

LCD_enuErrorStat_t LCD_enuGotoXY(u8 Cpy_u8Xpos, u8 Cpy_u8Ypos)
{
	u8 Local_u8Location = 0;
	LCD_enuErrorStat_t Local_enuLCDErrorstat = LCD_enuOK;
	
	if(Cpy_u8Xpos >=LCD_XPOS_FIRST_LINE && Cpy_u8Xpos <=LCD_XPOS_SECOND_LINE)
	{
		if(Cpy_u8Xpos == LCD_XPOS_FIRST_LINE)
		{
			if((Cpy_u8Ypos) <= LCD_DDRAM_LINE_1_END)
			{
				Local_u8Location = Cpy_u8Ypos;
			}
			else
			{
				Local_enuLCDErrorstat = LCD_enu_Out_OF_DDRAM_Boundary;
			}
			
		}
		else if(Cpy_u8Xpos == LCD_XPOS_SECOND_LINE)
		{
			if((LCD_DDRAM_LINE_2_START + Cpy_u8Ypos) <= LCD_DDRAM_LINE_2_END)
			{
				Local_u8Location = LCD_DDRAM_LINE_2_START + Cpy_u8Ypos;
			}
			else
			{
				Local_enuLCDErrorstat = LCD_enu_Out_OF_DDRAM_Boundary;
			}
			
		}
	}
	else
	{
		Local_enuLCDErrorstat = LCD_enu_Out_OF_DDRAM_Boundary;
	}
	
	if(Local_enuLCDErrorstat == LCD_enuOK)
	{
		LCD_enuSendCommand(Local_u8Location+LCD_DDRAM_ADDRESS_CFG);
	}
	
	return Local_enuLCDErrorstat;
	
}

LCD_enuErrorStat_t LCD_enuWriteString (u8* Add_pu8String)
{
	u8 Local_u8Counter = 0;
	LCD_enuErrorStat_t Local_enuLCDErrorstat = LCD_enuOK;
	if(Add_pu8String != NULL)
	{
		
		for(Local_u8Counter=0;Add_pu8String[Local_u8Counter]!=0;Local_u8Counter++)
		{
			LCD_enuSendData(Add_pu8String[Local_u8Counter]);
		}
	}
	else
	{
		Local_enuLCDErrorstat = LCD_enu_Null_Pointer;
	}
	
	return Local_enuLCDErrorstat;
}

LCD_enuErrorStat_t LCD_enuWriteNumber (u16 Copy_u16Number)
{
	u16 Local_u16Number = Copy_u16Number;
	u8 Local_u8NumberToString[5];
	LCD_enuErrorStat_t Local_enuLCDErrorstat = LCD_enuOK;

	itoa(Local_u16Number,Local_u8NumberToString,10);
	LCD_enuWriteString(Local_u8NumberToString);
		
	return Local_enuLCDErrorstat;
}

LCD_enuErrorStat_t LCD_enuWrite_Special_Pattern(u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	LCD_enuErrorStat_t Local_enuLCDErrorstat = LCD_enuOK;
	u8 Local_u8BlockStartAddress = 0,Local_u8Counter = 0;
	if(Add_pu8Pattern != NULL)
	{
		if(Copy_u8BlockNum >= LCD_BLOCK0 && Copy_u8BlockNum <= LCD_BLOCK7)
		{
			
			Local_u8BlockStartAddress = Copy_u8BlockNum*LCD_CGRAM_BLOCK_SIZE;
			
			/*MOVE THE AC TO CGRAM DESIRED BLOCK*/
			LCD_enuSendCommand(Local_u8BlockStartAddress+LCD_CGRAM_ADDRESS_CFG);
			
			for(Local_u8Counter = 0;Local_u8Counter<LCD_CGRAM_BLOCK_SIZE;Local_u8Counter++)
			{
				/*WRITE THE SPECIAL PATTERN IN CGRAM*/
				LCD_enuSendData(Add_pu8Pattern[Local_u8Counter]);
			}
			/*GO BACK TO DDRAM*/
			LCD_enuGotoXY(Copy_u8XPos,Copy_u8YPos);
			/*WRITE THE BLOCK NUMBER TO BE DISPLAYED ON THE LCD*/
			LCD_enuSendData(Copy_u8BlockNum);
			
		}
		else
		{
			Local_enuLCDErrorstat = LCD_enu_Out_OF_CGRAM_Boundary;
		}
		
	}
	else
	{
		Local_enuLCDErrorstat = LCD_enu_Null_Pointer;
	}
	
	return Local_enuLCDErrorstat;
	
}