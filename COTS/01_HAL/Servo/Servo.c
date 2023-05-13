/********************
Servo Source File
*********************/

#include "Timer.h"
#include "Servo.h"

void Servo_vidInit()
{
	TMR1_Init_FastPWM_InputCapture(SERVO_PERIOD_TIME_MS);
}

Servo_enuErrorstatus_t Servo_enuSetAngle(u8 Cpy_ServoAngleDeg)
{
	Servo_enuErrorstatus_t Local_enuServoErrorstat = Servo_enuOK;
	u16 Local_ServoAngle = 0;
	if(Cpy_ServoAngleDeg >= SERVO_MIN_ANGLE_DEG && Cpy_ServoAngleDeg<= SERVO_MAX_ANGLE_DEG)
	{
		Local_ServoAngle = (Cpy_ServoAngleDeg*SERVO_ANGLE_MAP_VALU)+SERVO_MIN_ON_TIME_US;
		TMR1_Set_CompareMatchA(Local_ServoAngle);
	}
	else
	{
		Local_enuServoErrorstat = Servo_enuNOK;
	}
	return Local_enuServoErrorstat;
}