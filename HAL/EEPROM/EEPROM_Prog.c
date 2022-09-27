/*
 * EEPROM_Prog.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Hanzada
 */
#include "EEPROM_Private.h"
#include "EEPROM_Interface.h"

void H_EEPROM_Void_EEPROMInit(void)
{
	M_I2C_Void_I2CInit();
	_delay_ms(1000);
}
void H_EEPROM_Void_EEPROMWrite(u8 Copy_U8_Page,u8 Copy_U8_Byte,u8 Copy_U8_Data)
{
	M_I2C_Void_I2CStartCondition();
	M_I2C_Void_I2CSendSlaveAdressWrite(0x50 | Copy_U8_Page);
	M_I2C_Void_I2CSendByte(Copy_U8_Byte);
	M_I2C_Void_I2CSendByte(Copy_U8_Data);
	M_I2C_Void_I2CStopCondition();
}
u8   H_EEPROM_Void_EEPROMRead(u8 Copy_U8_Page,u8 Copy_U8_Byte)
{
	u8 Local_U8_Reading = 0;
	M_I2C_Void_I2CStartCondition();
	M_I2C_Void_I2CSendSlaveAdressWrite(0x50 | Copy_U8_Page);
	// el mafrod ab3tlo 3nwan el byte el ana 3yzaha 3shan y3rf yb3t eh
	M_I2C_Void_I2CSendByte(Copy_U8_Byte);
	// then aghyr el operation akhaleha read
	M_I2C_Void_I2CRepeatedStart();
	M_I2C_Void_I2CSendSlaveAdressRead(0x50 | Copy_U8_Page);
	Local_U8_Reading = M_I2C_Void_I2CReadByte();
	M_I2C_Void_I2CStopCondition();
	return Local_U8_Reading;
}
