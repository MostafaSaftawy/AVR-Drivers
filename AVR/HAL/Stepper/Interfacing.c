/*
 * Interfacing.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Mostafa Saftawy
 */

#include "../LIB2/STD_TYPES.h"
#include "Registers.h"
#include "DIO.h"
#include "Stepper_Config.h"
#include "Stepper_Interfacing.h"
#include <avr/delay.h>


void Stepper_Init(void)
{
	DIO_VoidSetPortDirection( DIO_u8PORT_A,  DIO_u8OUTPUT );
}
void Stepper_Stop(void)
{
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
}

void Stepper_FullStep_Right()
{
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8HIGH); //activate coil 1
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
	_delay_ms(5);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8HIGH);//activate coil 2
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
	_delay_ms(5);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8HIGH); //activate coil 3
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
	_delay_ms(5);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8HIGH); //activate coil 4
	_delay_ms(5);
}
void Stepper_FullStep_Left()
{

	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8HIGH); //activate coil 4
	_delay_ms(5);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8HIGH); //activate coil 3
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
	_delay_ms(5);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8HIGH);//activate coil 2
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
	_delay_ms(5);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_0,DIO_u8HIGH); //activate coil 1
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_1,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_2,DIO_u8LOW);
	DIO_VoidSetPinValue(Stepper_Port,DIO_u8PIN_3,DIO_u8LOW);
	_delay_ms(5);
}

