#include "Schedulercfg.h"
#include "LED.c"
#include "LED_Cfg.c"

void LED_vidON(void)
{
	LED_enuLEDON(0);
}
void LED_vidOFF(void)
{
	LED_enuLEDOFF(0);
}


const Scheduler_strTasks_Cfg_t Tasks[TASK_enuCOUNT] =
{
	[Task1] =
	{
		.CyclicTime_MS = 1000,
		.Taskfn = LED_vidON
	},
	[Task2] =
	{
		.CyclicTime_MS = 2000,
		.Taskfn = LED_vidOFF
	}
};
