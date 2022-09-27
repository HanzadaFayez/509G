/*
 * LCD_Prog.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Hanzada
 */
#include "LCD_Interface.h"
#include "LCD_Private.h"

void H_LCD_Void_LCDInit(void)
{
#if LCD_MODE  == _8_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);        //always write

	H_LCD_Void_LCDWriteCommand(LCD_8_BIT_MODE);    //to tell M.C in LCD (8-bit mode)
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_CURSOR_OFF);

#elif LCD_MODE   == _4_BIT_MODE

	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);        //always write

	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_1);    //to tell M.C in LCD (4-bit mode)
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_2);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_3);

	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_CURSOR_OFF);


#endif
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);
}
void H_LCD_Void_LCDWriteCharacter(u8 Copy_U8_Character)    //0100 0010
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,HIGH);              //data

#if LCD_MODE  == _8_BIT_MODE
	//PORTA_REG= Copy_U8_Character;
	H_LCD_Void_SetLCDPins( Copy_U8_Character);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

#elif LCD_MODE   == _4_BIT_MODE
	//send half of data,enable on,enable off,send other half
	H_LCD_Void_SetLCDPins(Copy_U8_Character >> 4);         // 1010 1100 -> 1010 el awl
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);
	//send second half
	H_LCD_Void_SetLCDPins(Copy_U8_Character);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

#endif
	_delay_ms(1);  //3shan lw b3t haga waraha
}
void H_LCD_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,LOW);   //command
	//PORTA_REG= Copy_U8_Command;
#if LCD_MODE  == _8_BIT_MODE
	H_LCD_Void_SetLCDPins( Copy_U8_Command);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

#elif LCD_MODE  == _4_BIT_MODE
	H_LCD_Void_SetLCDPins(Copy_U8_Command >> 4);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);
	//send second half
	H_LCD_Void_SetLCDPins(Copy_U8_Command);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#endif
	_delay_ms(1);
}
void H_LCD_Void_LCDWriteString(u8* Copy_U8_P)
{
	u8 Local_U8_Counter = 0;
	while(Copy_U8_P[Local_U8_Counter] != '\0')
	{
		H_LCD_Void_LCDWriteCharacter(Copy_U8_P[Local_U8_Counter]);
		Local_U8_Counter ++;
	}
}
void H_LCD_Void_LCDWriteStrRun(u8* Copy_U8_P)
{
	u8 i=0 ,k;
	u8 Local_U8_Counter = 0;
	while(Copy_U8_P[Local_U8_Counter] != '\0')
		Local_U8_Counter ++;

	for(;i<16;i++)
	{
		H_LCD_Void_LCDWriteString(Copy_U8_P);
		_delay_ms(300);
		H_LCD_Void_LCDClear();

		for(k=0;k<i;k++)
		{
			H_LCD_Void_LCDWriteCharacter(' ');
		}
	}
}
//void H_LCD_Void_LCDWriteNumber(s32 Copy_S32_Number)
//{
//	u8 Local_U8_Arr[16];          //el LCD 2x16
//	s8 Local_S8_Counter = -1;
//
//	if (Copy_S32_Number < 0)
//	{
//		Copy_S32_Number=Copy_S32_Number * -1;
//		H_LCD_Void_LCDWriteCharacter('-');
//	}
//	do             //3shan lw el rkm zero yetebe3
//	{
//		Local_S8_Counter++;             //3shan mykonsh zeyada wahed
//		Local_U8_Arr[Local_S8_Counter] = Copy_S32_Number % 10;
//		Copy_S32_Number= Copy_S32_Number / 10;
//	}
//	while(Copy_S32_Number !=0);       //128->8 2 1
//
//	while(Local_S8_Counter >=0)
//	{
//		H_LCD_Void_LCDWriteCharacter(Local_U8_Arr[Local_S8_Counter] + 48);  //asci of zero is 48
//		Local_S8_Counter --;
//	}
//}

void H_LCD_Void_LCDWriteNumber(f32 Copy_F32_Num)
{
	s8 Local_S8_Counter = -1;
	u8 Local_U8_Arr[16];
	if(Copy_F32_Num < 0)
	{
		Copy_F32_Num = Copy_F32_Num * -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}



	u32 Local_U32_Whole = Copy_F32_Num;
	f32 Local_F32_Dec = Copy_F32_Num - Local_U32_Whole;
	do
		{
			Local_S8_Counter++;
			Local_U8_Arr[Local_S8_Counter]  =  Local_U32_Whole % 10;
			Local_U32_Whole = Local_U32_Whole / 10;
		}while(Local_U32_Whole != 0);

		while(Local_S8_Counter >= 0)
		{
			H_LCD_Void_LCDWriteCharacter(Local_U8_Arr[Local_S8_Counter] + 48);
			Local_S8_Counter--;
		}

		s8 Local_S8_ForCounter = 0;
		Local_S8_Counter = -1;
		//Local_U8_Arr={0};
	if(Local_F32_Dec != 0)
	{
		Local_F32_Dec*=1000000;
		H_LCD_Void_LCDWriteCharacter('.');

		//H_LCD_Void_LCDWriteNumber((s32)Local_F32_Dec);
		for(Local_S8_ForCounter = 0;Local_S8_ForCounter<6;Local_S8_ForCounter++)
		{
			Local_S8_Counter++;
			Local_U8_Arr[Local_S8_Counter]  = (u32) Local_F32_Dec % 10;
			Local_F32_Dec = Local_F32_Dec / 10;
		}
		for(Local_S8_ForCounter = 0;Local_S8_ForCounter<6;Local_S8_ForCounter++)
		{
			if(Local_U8_Arr[Local_S8_ForCounter] != 0)
				break;
		}
		while(Local_S8_Counter >= Local_S8_ForCounter)
		{
			H_LCD_Void_LCDWriteCharacter(Local_U8_Arr[Local_S8_Counter] + 48);
			Local_S8_Counter--;
		}
	}
}

void H_LCD_Void_LCDClear(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
}

static void H_LCD_Void_SetLCDPins(u8 Copy_U8_Pins)
{
#if LCD_MODE  == _8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D0_PIN,Copy_U8_Pins >>0 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D1_PIN,Copy_U8_Pins >>1 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D2_PIN,Copy_U8_Pins >>2 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D3_PIN,Copy_U8_Pins >>3 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D4_PIN,Copy_U8_Pins >>4 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D5_PIN,Copy_U8_Pins >>5 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D6_PIN,Copy_U8_Pins >>6 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D7_PIN,Copy_U8_Pins >>7 & 0x01);

#elif LCD_MODE   == _4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D4_PIN,Copy_U8_Pins >>0 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D5_PIN,Copy_U8_Pins >>1 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D6_PIN,Copy_U8_Pins >>2 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D7_PIN,Copy_U8_Pins >>3 & 0x01);

#endif
}
void H_LCD_Void_LCDGoTo(u8 Copy_U8_Row ,u8 Copy_U8_Col)
{
	u8 Local_U8_Arr[2]={0x80,0xC0};
	H_LCD_Void_LCDWriteCommand(Local_U8_Arr[Copy_U8_Row] + Copy_U8_Col);

}
