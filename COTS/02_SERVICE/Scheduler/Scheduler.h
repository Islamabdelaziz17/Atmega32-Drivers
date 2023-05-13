/*********************************
Scheduler Interface File
*********************************/
#include "Schedulercfg.h"

#ifndef Scheduler_H
#define Scheduler_H

#define TICK_TIME_MS	1

typedef enum
{
	Schedular_enuOK,
	Schedular_enuNOK
	
}Scheduler_enuErrorStatus_t;



void Scheduler_vidInit();
Scheduler_enuErrorStatus_t Scheduler_enuStart();
static void Schedule_vidTasks();



#endif /*Schedular_H*/
