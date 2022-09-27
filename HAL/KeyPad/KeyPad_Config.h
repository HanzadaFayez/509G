/*
 * KeyPad_Config.h
 *
 *  Created on: Sep 9, 2022
 *      Author: Hanzada
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define  KEYPAD_R0_PIN  PC3_PIN
#define  KEYPAD_R1_PIN  PC4_PIN
#define  KEYPAD_R2_PIN  PC5_PIN
#define  KEYPAD_R3_PIN  PC6_PIN

#define  KEYPAD_C0_PIN  PB4_PIN
#define  KEYPAD_C1_PIN  PB5_PIN
#define  KEYPAD_C2_PIN  PB6_PIN
#define  KEYPAD_C3_PIN  PB7_PIN

/*
 * choose KEYPAD_DEBOUNCING_TIME in milli seconds
 */
#define  KEYPAD_DEBOUNCING_TIME   120

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
