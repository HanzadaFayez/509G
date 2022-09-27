/*
 * KeyPad_Interface.h
 *
 *  Created on: Sep 9, 2022
 *      Author: Hanzada
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_


#include "DIO_Interface.h"
#include "KeyPad_Config.h"
#include <util/delay.h>

#define KEYPAD_PRESSED    0

void H_KeyPad_Void_KeyPadInit(void);
u8 H_KeyPad_Void_KeyPadRead(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
