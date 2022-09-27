/*
 * Servo_Interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Hanzada
 */

#ifndef HAL_SERVO_SERVO_INTERFACE_H_
#define HAL_SERVO_SERVO_INTERFACE_H_
#include "STD.h"
#include "BitMath.h"
void H_Servo_Void_ServoInit(void);
void H_Servo_Void_ServoSetAngel(u8);
void H_Servo_Void_ServoStart(void);
void H_Servo_Void_ServoStop(void);

#endif /* HAL_SERVO_SERVO_INTERFACE_H_ */
