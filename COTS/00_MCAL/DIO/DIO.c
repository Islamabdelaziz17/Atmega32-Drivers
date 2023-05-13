/***************************/
/*     DIO File.c		  */
/*************************/

#include "..\..\..\LIB\Bit_math.h"
#include "DIO.h"
#include "DIO_Cfg.h"
#include "Dio_Prv.h"
#include "..\..\..\LIB\Std_Types.h"

//#include "..\..\..\LIB\AVR_Atmega32_Interface_Registers.h"
#include <avr/io.h>

DIO_tenuErrorStatus DIO_enuInit(void)
{
	/*Local Error status variable for functional safety status*/
	DIO_tenuErrorStatus Local_enuErrorstat = DIO_enuOk;
	
	/*Local loop counter to loop on DIO ports for their initialization*/
    u8 DIO_u8LocalCounter = 0;
	/*Local Variable will be carrying the current port number needs to be initialized*/
    u8 Local_u8PortNumber;
	/*Local Variable will be carrying the current pin number in the predefined port that needs to be initialized*/
    u8 Local_u8PinNumber;

	/*Initializing loop on the number of target pins Pre-configured in the interface file */
    for(DIO_u8LocalCounter=0;DIO_u8LocalCounter<DIO_enuNumberofPins;DIO_u8LocalCounter++)
    {
		/*Get the port number to identify if its Port A || B || C ||D */
        Local_u8PortNumber = DIO_u8LocalCounter/8;
		/*Get the PIN number ranges from 0-7*/
        Local_u8PinNumber = DIO_u8LocalCounter%8;
		
		/*----------Validating Arguments----------V*/
		/*Verify If Port number is Valid or Not[A||B||C||D]*/
		if(Local_u8PortNumber > 3)
		{
			Local_enuErrorstat = DIO_enuNotOk;
		}
		/*Verifying if Pin number is In/Out Range */
		else if(Local_u8PinNumber > 7)
		{
			Local_enuErrorstat = DIO_enuNotOk;
		}
		/*Verifying the Pre-configured pins if there's any wrong configurations*/
		else if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_PIN_DIR != DIO_DIR_OUTPUT || DIO_strPinCfg[DIO_u8LocalCounter].DIO_PIN_DIR != DIO_DIR_INPUT)
		{
			Local_enuErrorstat = DIO_enuNotOk;
		}
		else if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_InputStatus != DIO_INPUT_PULL_UP ||DIO_strPinCfg[DIO_u8LocalCounter].DIO_InputStatus != DIO_INPUT_PULL_Down)
		{
			Local_enuErrorstat = DIO_enuNotOk;
		}
		
		/*Based on the selected port and the configuration  starting the initialization process*/
		/*Calling the set/clear macro from the "Bit_Math.h" interface*/
        switch(Local_u8PortNumber)
        {
            case(DIO_PORTA):
                if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_PIN_DIR == DIO_DIR_OUTPUT)
                {
                    SET_BIT(DDRA,Local_u8PinNumber);
                }
                else
                {
                    CLR_BIT(DDRA,Local_u8PinNumber);
                    if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_InputStatus == DIO_INPUT_PULL_UP)
                    {
                        SET_BIT(PORTA,Local_u8PinNumber);
                    }
                }
                break;
            case(DIO_PORTB):
                if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_PIN_DIR == DIO_DIR_OUTPUT)
                {
                    SET_BIT(DDRB,Local_u8PinNumber);
                }
                else
                {
                    CLR_BIT(DDRB,Local_u8PinNumber);
                    if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_InputStatus == DIO_INPUT_PULL_UP)
                    {
                        SET_BIT(PORTB,Local_u8PinNumber);
                    }
                }
                break;
            case(DIO_PORTC):
                if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_PIN_DIR == DIO_DIR_OUTPUT)
                {
                    SET_BIT(DDRC,Local_u8PinNumber);
                }
                else
                {
                    CLR_BIT(DDRC,Local_u8PinNumber);
                    if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_InputStatus == DIO_INPUT_PULL_UP)
                    {
                        SET_BIT(PORTC,Local_u8PinNumber);
                    }
                }
                break;
            case(DIO_PORTD):
                if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_PIN_DIR == DIO_DIR_OUTPUT)
                {
                    SET_BIT(DDRD,Local_u8PinNumber);
                }
                else
                {
                    CLR_BIT(DDRD,Local_u8PinNumber);
                    if(DIO_strPinCfg[DIO_u8LocalCounter].DIO_InputStatus == DIO_INPUT_PULL_UP)
                    {
                        SET_BIT(PORTD,Local_u8PinNumber);
                    }
                }
                break;

        }
    }
	//Finally returns function status
    return Local_enuErrorstat;
}

DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber)
{
	/*Local Error status variable for functional safety status*/
	DIO_tenuErrorStatus Local_enuErrorstat = DIO_enuOk;
	
	/*Local Variable will be carrying the current port number*/
	u8 Local_u8PortNumber;
	/*Local Variable will be carrying the current pin number in the predefined port that needs to be Set*/
	u8 Local_u8PinNumber;
	
	/*Get the port number to identify if its Port A || B || C ||D */
	Local_u8PortNumber = Cpy_enuPinNumber/8;
	/*Get the PIN number ranges from 0-7*/
	Local_u8PinNumber = Cpy_enuPinNumber%8;
	
	/*Validating Arguments*/
	/*Validating if pin number is out of range or not*/
	if(Cpy_enuPinNumber >= DIO_enuNumberofPins)
	{
		Local_enuErrorstat = DIO_enuNotOk;
	}
	/*Based on the selected port starting the Setting process*/
	/*Calling the set  macro from the "Bit_Math.h" interface*/
	switch(Local_u8PortNumber)
	{
		case(DIO_PORTA):
			SET_BIT(PORTA,Local_u8PinNumber);
		    break;
		case(DIO_PORTB):
			SET_BIT(PORTB,Local_u8PinNumber);
		    break;
		case(DIO_PORTC):
			SET_BIT(PORTC,Local_u8PinNumber);
		    break;
		case(DIO_PORTD):
			SET_BIT(PORTD,Local_u8PinNumber);
		    break;
	}
	//Finally returns function status
	return Local_enuErrorstat;
}

DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber)
{
	/*Local Error status variable for functional safety status*/
	DIO_tenuErrorStatus Local_enuErrorstat = DIO_enuOk;
	
	/*Local Variable will be carrying the current port number*/
	u8 Local_u8PortNumber;
	/*Local Variable will be carrying the current pin number in the predefined port that needs to be cleared*/
	u8 Local_u8PinNumber;
	
	/*Get the port number to identify if its Port A || B || C ||D */
	Local_u8PortNumber = Cpy_enuPinNumber/8;
	/*Get the PIN number ranges from 0-7*/
	Local_u8PinNumber = Cpy_enuPinNumber%8;
	
	/*Validating Arguments*/
	/*Validating if pin number is out of range or not*/
	if(Cpy_enuPinNumber >= DIO_enuNumberofPins)
	{
		Local_enuErrorstat = DIO_enuNotOk;
	}
	/*Based on the selected port starting the clearing process*/
	/*Calling the clear macro from the "Bit_Math.h" interface*/
	switch(Local_u8PortNumber)
	{
		case(DIO_PORTA):
			CLR_BIT(PORTA,Local_u8PinNumber);
			break;
		case(DIO_PORTB):
			CLR_BIT(PORTB,Local_u8PinNumber);
			break;
		case(DIO_PORTC):
			CLR_BIT(PORTC,Local_u8PinNumber);
			break;
		case(DIO_PORTD):
			CLR_BIT(PORTD,Local_u8PinNumber);
			break;
	}
	//Finally returns function status
	return Local_enuErrorstat;
;
}

DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber,volatile u8* Add_pu8PinValue)
{
	/*Local Error status variable for functional safety status*/
	DIO_tenuErrorStatus Local_enuErrorstat = DIO_enuOk;
	
	/*Local Variable will be carrying the current port number*/
	u8 Local_u8PortNumber;
	/*Local Variable will be carrying the current pin number in the predefined port that we need to get*/
	u8 Local_u8PinNumber;
	/*Local variable will be use as a temp for the input port value*/
	u8 Local_u8Valueofbit;
	/*Get the port number to identify if its Port A || B || C ||D */
	Local_u8PortNumber = Cpy_enuPinNumber/8;
	/*Get the PIN number ranges from 0-7*/
	Local_u8PinNumber = Cpy_enuPinNumber%8;
	
	/*Validating Arguments*/
	/*Validating if pin number is out of range or not*/
	if(Cpy_enuPinNumber >= DIO_enuNumberofPins)
	{
		Local_enuErrorstat = DIO_enuNotOk;
	}
	/*Validating Arguments*/
	/*Validating if the Pin value Pointer address passed is NULL or NOt*/
	if(Add_pu8PinValue == NULL)
	{
		Local_enuErrorstat = DIO_enuNullPointer;
	}
	/*Based on the selected port starting the getting process*/
	/*Calling the get macro from the "Bit_Math.h" interface*/
	switch(Local_u8PortNumber)
	{
		case(DIO_PORTA):
		*Add_pu8PinValue = GET_BIT(PINA,Local_u8PinNumber);
		break;
		case(DIO_PORTB):
		*Add_pu8PinValue = GET_BIT(PINB,Local_u8PinNumber);
		break;
		case(DIO_PORTC):
		*Add_pu8PinValue = GET_BIT(PINC,Local_u8PinNumber);
		break;
		case(DIO_PORTD):
		*Add_pu8PinValue = GET_BIT(PIND,Local_u8PinNumber);
		break;
	}
	
	//Finally returns function status
	return Local_enuErrorstat;
}