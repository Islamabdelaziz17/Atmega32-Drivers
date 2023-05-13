#include "Scheduler.h"
#include "Schedulercfg.h"
#include "Timer.c"

static u16 Global_TimerOvCounts;
static TMR02Config_t Timer0Cfg;

static void Schedule_vidTasks()
{
	static u8 Local_u8ticktimeMS = 0;
	u8 Local_u8Iterator = 0;
	Local_u8ticktimeMS += TICK_TIME_MS;
	for(Local_u8Iterator = 0;Local_u8Iterator<TASK_enuCOUNT;Local_u8Iterator++)
	{
		if(Local_u8ticktimeMS % Tasks[Local_u8Iterator].CyclicTime_MS == 0)
		{
			Tasks[Local_u8Iterator].Taskfn();
		}
		else
		{ 
			/*Do Nothing*/
		}
	}
	
	
}

void Scheduler_vidInit()
{
	TMR0_enuRegisterCallback_CTC(&Schedule_vidTasks);
	TMR0_enuSetTickTimeMS(TICK_TIME_MS, TMR02_CLK_PRES_64,&Global_TimerOvCounts);
	Timer0Cfg.Mode = TMR02_MODE_CTC;
	Timer0Cfg.Clock_Cfg = TMR0_CLK_PRESCALER_64;
	TMR0_vidInitPostCompile(&Timer0Cfg);
	
}
Scheduler_enuErrorStatus_t Scheduler_enuStart()
{
	while(1);
	return Schedular_enuOK;
}


