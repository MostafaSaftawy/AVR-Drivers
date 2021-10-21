/*
 * LCD.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */
#define F_CPU 8000000
#include "util/delay.h"

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "DIO.h"
#include "LCD_config.h"
#include "LCD_interfacing.h"

 void LCD_VoidSendCommand(u8 Copy_u8Command)
{
		DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8LOW);
		DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
		DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
		DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
		_delay_ms(15);


		DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);


}

 void LCD_VoidInit(void)
{
	_delay_ms(30);
	LCD_VoidSendCommand(0b00111000);
	LCD_VoidSendCommand(0b000001100);
	LCD_VoidSendCommand(1);
}


 void LCD_VoidSendData(u8 Copy_u8Data)
{
	 	 	DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8HIGH);
			DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
			DIO_VoidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
			DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
			_delay_ms(15);
			DIO_VoidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}



void LCD_sendString(const char* Copy_String)
{
	u8 Local_u8Counter=0;
	while(Copy_String[Local_u8Counter]!='\0')
	{
		LCD_VoidSendData(Copy_String[Local_u8Counter]);

		Local_u8Counter++;
	}


}
void LCD_VoidGoToXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	u8 Local_u8Address;
	if (Copy_u8XPosition == 0)
	{
		Local_u8Address = Copy_u8YPosition + 128;
		LCD_voidSendCommand(Local_u8Address);
	}
	else if (Copy_u8XPosition == 1)
	{
		Local_u8Address = 0x40 + Copy_u8YPosition + 128;
		LCD_voidSendCommand(Local_u8Address);
	}
	else
	{

	}
}


