/*
 * KeyPad.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "DIO.h"

#include "keyPad_Config.h"
#include "KeyPad_Interfacing.h"


void Keypad_voidInit(void)
{

	/*1- Set columns as output*/
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8COLUMN_0, DIO_u8OUTPUT);
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8COLUMN_1, DIO_u8OUTPUT);
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8COLUMN_2, DIO_u8OUTPUT);
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8COLUMN_3, DIO_u8OUTPUT);
	/* 2- Set Rows as input*/
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8ROW_0, DIO_u8INPUT);
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8ROW_1, DIO_u8INPUT);
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8ROW_2, DIO_u8INPUT);
	DIO_VoidSetPinDirection(KEYPAD_PORT, KEY_u8ROW_3, DIO_u8INPUT);
	/* 3- Set columns value to high*/
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8COLUMN_0, DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8COLUMN_1, DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8COLUMN_2, DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8COLUMN_3, DIO_u8HIGH);
	/* 4 - Enable pull up resistors in inputs*/
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8ROW_0, DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8ROW_1, DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8ROW_2, DIO_u8HIGH);
	DIO_VoidSetPinValue(KEYPAD_PORT, KEY_u8ROW_3, DIO_u8HIGH);

}


u8 KeyPad_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KEY_u8NOTPRESSED;
	u8 Local_u8ColIndx, Local_u8RowIndx, Local_u8PinState;
	u8 local_u8KeyPad_values[KEYPAD_u8ROWS_NUMBER][KEYPAD_u8COLUMNS_NUMBER] = KEYPAD_ARRAY_VALUES;

	u8 Local_u8ColsArray[KEYPAD_u8COLUMNS_NUMBER]={KEY_u8COLUMN_0, KEY_u8COLUMN_1, KEY_u8COLUMN_2, KEY_u8COLUMN_3};
	u8 Local_u8RowArray[KEYPAD_u8ROWS_NUMBER]={KEY_u8ROW_0, KEY_u8ROW_1, KEY_u8ROW_2, KEY_u8ROW_3};


	for (Local_u8ColIndx=0; Local_u8ColIndx<KEYPAD_u8COLUMNS_NUMBER; Local_u8ColIndx++) //columns
	{
		DIO_VoidSetPinValue(KEYPAD_PORT, Local_u8ColsArray[Local_u8ColIndx], DIO_u8LOW);
		for(Local_u8RowIndx=0; Local_u8RowIndx<KEYPAD_u8ROWS_NUMBER; Local_u8RowIndx++)
		{
			Local_u8PinState = DIO_u8GetPinValue(KEYPAD_PORT, Local_u8ColsArray[Local_u8RowIndx]);
			if(Local_u8PinState == DIO_u8LOW)
			{
				while(Local_u8PinState == DIO_u8LOW)
				{
					Local_u8PinState = DIO_u8GetPinValue(KEYPAD_PORT, Local_u8ColsArray[Local_u8RowIndx]);
				}
				Local_u8PressedKey = local_u8KeyPad_values[Local_u8RowIndx][Local_u8ColIndx];
				return Local_u8PressedKey;
			}
		}
		DIO_VoidSetPinValue(KEYPAD_PORT, Local_u8ColsArray[Local_u8ColIndx], DIO_u8HIGH);
	}
	return Local_u8PressedKey;
}
