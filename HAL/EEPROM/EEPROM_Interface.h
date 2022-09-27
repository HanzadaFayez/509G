/*
 * EEPROM_Interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Hanzada
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

/*AT24C16A CHIP*/

#include "EEPROM_Config.h"
#include "I2C_Interface.h"
#include "DIO_Interface.h"
#include <util/delay.h>

void H_EEPROM_Void_EEPROMInit(void);
u8 H_EEPROM_Void_EEPROMRead(u8,u8);
void H_EEPROM_Void_EEPROMWrite(u8 ,u8 ,u8 );

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
