/*
 * PushButton_Config.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Hanzada
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_CONFIG_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_CONFIG_H_

/* SELECT PUSH BUTTON MODE : ACTIVE_HIGH , ACTIVE_LOW */


#define PushB_MODE  ACTIVE_HIGH

/* SELECT PUSH BUTTON PIN */
#define PushB0_PIN    PB0_PIN
#define PushB1_PIN    PD6_PIN
#define PushB2_PIN    PD2_PIN

/* SELECT PB_DEBOUNCING TIME */
#define PB_DEBOUNCING_TIME     130


#endif /* HAL_PUSHBUTTON_PUSHBUTTON_CONFIG_H_ */
