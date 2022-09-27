/*
 * LM35_Prog.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Hanzada
 */
#include "LM35_Interface.h"

void H_LM35_Void_LM35Init(void)
{
	M_ADC_Void_ADCInit();
}
u16 H_LM35_Void_LM35Read(void)
{
	u16 Local_U16_AdcValue= M_ADC_U16_ADCRead(LM35_PIN);
    // 10mv/Celsius
	/*mapping for temperature */
	u16 Temp  = ((u32)Local_U16_AdcValue *500)/1023;
	return Temp;
}
