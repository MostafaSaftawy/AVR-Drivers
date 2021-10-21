/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */



#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "KeyPad_Interfacing.h"
#include "LCD_Interfacing.h"
#include <avr/delay.h>

int main(void)
{
	u8 PressedValue;
		LCD_VoidInit();
		Keypad_voidInit();

		while(1)
		{
			LCD_VoidGoToXY(0,0);
			PressedValue = KeyPad_u8GetPressedKey();
			if (PressedValue != 0xff)
			{

				LCD_VoidSendData(PressedValue + '0');
				_delay_ms(200);
			}
		}

		return 0;
}
