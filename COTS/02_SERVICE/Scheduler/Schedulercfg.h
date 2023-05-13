/*********************************
Scheduler Configuration File
*********************************/

#ifndef Scheduler_CFG_H
#define Scheduler_CFG_H

#include "Std_Types.h"

typedef void(*Taskcbf)(void);

typedef struct
{
	u8 CyclicTime_MS;
	Taskcbf Taskfn;
}Scheduler_strTasks_Cfg_t;

typedef enum
{
	Task1,
	Task2,
	TASK_enuCOUNT
}Tasks_enu_t;

extern const Scheduler_strTasks_Cfg_t Tasks[TASK_enuCOUNT];


#endif /*Schedular_CFG_H*/
