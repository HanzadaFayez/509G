/*
 * Servo_Prog.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Hanzada
 */
#include "Servo_Interface.h"
#include "Timer_Interface.h"
void H_Servo_Void_ServoInit(void)
{ /* lazm ywslo frequency 50HZ */
	M_Timer_Void_PWMInit(TIMER1_CHANNEL);
	M_Timer_Void_PWMSetFrequency(50);
}
void H_Servo_Void_ServoSetAngel(u8 Copy_U8_Angel)
{
	f32 Local_F32_Value = ((Copy_U8_Angel * 5.0 ) /180.0) + 5.0 ;
	/* total time is 20ms,time on =1ms,5% duty cycle -> angel -90, time on =2ms,10% -> angel 90 */
	M_Timer_Void_PWMSetDutyCycle(TIMER1_CHANNEL,Local_F32_Value);
}
void H_Servo_Void_ServoStart(void)
{
	M_Timer_Void_PWMStart(TIMER1_CHANNEL);
}
void H_Servo_Void_ServoStop(void)
{
	M_Timer_Void_PWMStop(TIMER1_CHANNEL);
}
