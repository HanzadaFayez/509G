/*
 * LCD_Private.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Hanzada
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define LCD_8_BIT_MODE                   0x38  //activate 8 bit mode
#define LCD_4_BIT_MODE_1                 0x33
#define LCD_4_BIT_MODE_2                 0x32
#define LCD_4_BIT_MODE_3                 0x28
#define LCD_DISPLAY_ON_CURSOR_OFF        0x0C
#define LCD_CLEAR                        0x01
#define LCD_RETURN_HOME                  0x02
#define _4_BIT_MODE                      4
#define _8_BIT_MODE                      8

static void H_LCD_Void_SetLCDPins(u8);

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
