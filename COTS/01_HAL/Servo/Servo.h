/********************
Servo Interface File
*********************/


#include "Std_Types.h"
#include <math.h>

#define SERVO_PERIOD_TIME_MS	20U

#define SERVO_MIN_ON_TIME_US	750U
#define SERVO_MAX_ON_TIME_US	2500U

#define SERVO_MIN_ANGLE_DEG	0U
#define SERVO_MAX_ANGLE_DEG	180U

#define SERVO_ANGLE_MAP_VALU	ceil((SERVO_MAX_ON_TIME_US - SERVO_MIN_ON_TIME_US)/SERVO_MAX_ANGLE_DEG)


typedef enum
{
	Servo_enuOK,
	Servo_enuNOK
	
}Servo_enuErrorstatus_t;

void Servo_vidInit();
Servo_enuErrorstatus_t Servo_enuSetAngle(u8 Cpy_ServoAngleDeg);
