/*
 * PushButton_Interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Hanzada
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
/*********************_INCLUDES_***********************/
#include "PushButton_Config.h"
#include "DIO_Interface.h"
#include "STD.h"
/*********************_MACROS_***********************/
#define PushB0    0
#define PushB1    1
#define PushB2    2

#define ACTIVE_HIGH   1
#define ACTIVE_LOW   2

//active high or low
#if PushB_MODE ==  ACTIVE_HIGH
#define PRESSED  1
#define RELEASED 0
#elif PushB_MODE ==  ACTIVE_LOW
#define PRESSED  0
#define RELEASED 1
#endif
/*********************_PROTOTYPES_***********************/
void H_PB_Void_PBInit(u8);
u8 H_PB_U8_PBRead(u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
