/*
 * PushButton_Prog.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Hanzada
 */

#include "PushButton_Interface.h"
#include <util/delay.h>


void H_PB_Void_PBInit(u8 Copy_U8_Button)
{
	switch (Copy_U8_Button)
	{
	case PushB0: M_DIO_Void_SetPinDirection(PushB0_PIN,INPUT);  break;
	case PushB1: M_DIO_Void_SetPinDirection(PushB1_PIN,INPUT);  break;
	case PushB2: M_DIO_Void_SetPinDirection(PushB1_PIN,INPUT);  break;
	default:                                                    break;
	}
}

u8 H_PB_U8_PBRead(u8 Copy_U8_Button)
{
	u8 Local_U8_Reading=RELEASED;
	/* switch (Copy_U8_Button)
	{
	case PushB0: Local_U8_Reading= M_DIO_U8_GetPinValue(PushB0_PIN);  break;
	case PushB1: Local_U8_Reading= M_DIO_U8_GetPinValue(PushB1_PIN);  break;
	case PushB2: Local_U8_Reading= M_DIO_U8_GetPinValue(PushB2_PIN);  break;
	default:                                                         break;
	}
	 */



	switch (Copy_U8_Button)
	{
	case PushB0:
		if (M_DIO_U8_GetPinValue(PushB0_PIN)==PRESSED)
		{
			_delay_ms(PB_DEBOUNCING_TIME);
			if (M_DIO_U8_GetPinValue(PushB0_PIN)==PRESSED)
			{
				while(M_DIO_U8_GetPinValue(PushB0_PIN)==PRESSED);
				//stuck
				Local_U8_Reading= PRESSED;
			}
		}
		break;
	case PushB1:
		if (M_DIO_U8_GetPinValue(PushB1_PIN)==PRESSED)
		{
			_delay_ms(PB_DEBOUNCING_TIME);
			if (M_DIO_U8_GetPinValue(PushB1_PIN)==PRESSED)
			{
				while(M_DIO_U8_GetPinValue(PushB1_PIN)==PRESSED);
				//stuck
				Local_U8_Reading= PRESSED;
			}
		}
		break;
	case PushB2:
		if (M_DIO_U8_GetPinValue(PushB2_PIN)==PRESSED)
		{
			_delay_ms(PB_DEBOUNCING_TIME);
			if (M_DIO_U8_GetPinValue(PushB2_PIN)==PRESSED)
			{
				while(M_DIO_U8_GetPinValue(PushB2_PIN)==PRESSED);
				//stuck
				Local_U8_Reading= PRESSED;
			}
		}
		break;
	default:
		break;
	}
	return Local_U8_Reading;
}
