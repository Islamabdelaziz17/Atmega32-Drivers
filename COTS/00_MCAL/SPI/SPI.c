#include "SPI.h"

#define SPI_BASEADDRESS		 0x2D

#define SPI_2XSPEED_MASK	 0x01
#define SPIF_FLAG			 0x80
#define SPI_INTERRUPT_ENABLE 0x80

typedef struct
{
	u8 SPCR;
	u8 SPSR;
	u8 SPDR;
}SPI_Reg_t;

volatile SPI_Reg_t* const SPI = (volatile SPI_Reg_t*)SPI_BASEADDRESS;


SPI_enuErrorStatus_t SPI_enuInit(SPI_Cfg_t* Cpy_strCfg)
{
	SPI_enuErrorStatus_t Local_enuSpiErrorStatus = SPI_enuOK;
	u8 Local_SPCR,Local_SPSR;
	if(Cpy_strCfg)
	{
		Local_SPSR = SPI->SPSR;
		Local_SPCR = SPI->SPCR;
		
		if(((Cpy_strCfg->SPI_Mode) & SPI_2XSPEED_MASK) == SPI_2XSPEED_MASK)
		{
			Local_SPSR |= SPI_2XSPEED_MASK;
			Cpy_strCfg->SPI_Mode &= (~SPI_2XSPEED_MASK);
			SPI->SPSR = Local_SPSR;
		}
		else
		{
			Local_SPCR |= ((Cpy_strCfg->SPI_Mode) | (Cpy_strCfg->SPI_ClockRate));
		}
		
		SPI->SPCR |= Local_SPCR;
	}
	else
	{
		Local_enuSpiErrorStatus = SPI_enuNULLPTR;
	}
	return Local_enuSpiErrorStatus;
}

SPI_enuErrorStatus_t SPI_enuIs_Done()
{
	SPI_enuErrorStatus_t Local_enuSpiErrorStatus = SPI_enuOK;
	if((SPI->SPSR & SPIF_FLAG) == SPIF_FLAG)
	{
		Local_enuSpiErrorStatus = SPI_enuSPI_DONE;
	}
	else
	{
		Local_enuSpiErrorStatus = SPI_enuSPI_NOTDONE;
	}
	return Local_enuSpiErrorStatus;
}

void SPI_vidEnableInterrupt()
{
	SPI->SPCR |= SPI_INTERRUPT_ENABLE;
}

SPI_enuErrorStatus_t SPI_enuSendmsgAsyncZerocopy(u8* Add_pu8Msg, u32 Cpy_u8Size,SPI_Cbf add_pvidCbf)
{
	SPI_enuErrorStatus_t Local_enuSpiErrorStatus = SPI_enuOK;
	if(Global_SPI_strSendReqHandler.Status == SPI_enuIdle)
	{
		if(Add_pu8Msg)
		{
			Global_SPI_strSendReqHandler.buffer = Add_pu8Msg;
			Global_SPI_strSendReqHandler.Size = Cpy_u8Size;
			Global_SPI_strSendReqHandler.Idx = 0;
			Global_SPI_strSendReqHandler.NotifyCbf = add_pvidCbf;
			Global_SPI_strSendReqHandler.Status = SPI_enuBusy;
			SPI->SPDR = Global_SPI_strSendReqHandler.buffer[Global_SPI_strSendReqHandler.Idx];
			Global_SPI_strSendReqHandler.Idx++;
		}
		else
		{
			Local_enuSpiErrorStatus = SPI_enuNOK;
		}
	}
	else
	{
		Local_enuSpiErrorStatus = SPI_enuNOK;
	}
	return Local_enuSpiErrorStatus;
}

SPI_enuErrorStatus_t SPI_enuRecvmsgAsync(u8* Add_pu8Msg, u32 Cpy_u8Size,SPI_Cbf add_pvidCbf)
{
	SPI_enuErrorStatus_t Local_enuSpiErrorStatus = SPI_enuOK;
	if(Global_SPI_strRecvReqHandler.Status == SPI_enuIdle)
	{
		if(Add_pu8Msg)
		{
			Global_SPI_strRecvReqHandler.buffer = Add_pu8Msg;
			Global_SPI_strRecvReqHandler.Size = Cpy_u8Size;
			Global_SPI_strRecvReqHandler.Idx = 0;
			Global_SPI_strRecvReqHandler.NotifyCbf = add_pvidCbf;
			Global_SPI_strRecvReqHandler.Status = SPI_enuBusy;
		}
		else
		{
			Local_enuSpiErrorStatus = SPI_enuNOK;
		}
	}
	else
	{
		Local_enuSpiErrorStatus = SPI_enuNOK;
	}
	return Local_enuSpiErrorStatus;
	
}

void __vector_12(void)  __attribute__((signal));
void __vector_12(void)
{
	
	/*Receive*/
	if(Global_SPI_strRecvReqHandler.Idx<Global_SPI_strRecvReqHandler.Size)
	{
		Global_SPI_strRecvReqHandler.buffer[Global_SPI_strRecvReqHandler.Idx++] = SPI->SPDR;
	}
	else
	{
		Global_SPI_strRecvReqHandler.Status = SPI_enuIdle;
		if(Global_SPI_strRecvReqHandler.NotifyCbf)
		{
			Global_SPI_strRecvReqHandler.NotifyCbf();
		}
		else
		{
			/*Do Nothing*/
		}
		
	}
	/*Transmit*/
	if(Global_SPI_strSendReqHandler.Idx<Global_SPI_strSendReqHandler.Size)
	{
		SPI->SPDR = Global_SPI_strSendReqHandler.buffer[Global_SPI_strSendReqHandler.Idx++];
	}
	else
	{
		Global_SPI_strSendReqHandler.Status = SPI_enuIdle;
		if(Global_SPI_strSendReqHandler.NotifyCbf)
		{
			Global_SPI_strSendReqHandler.NotifyCbf();
		}
		else
		{
			/*Do Nothing*/
		}
		
	}
	
}


