/*
 * main.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Mostafa Saftawy
 */

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"

#include "DIO.h"
#include "EXTI_Interfacing.h"

int main(void)
{
	DIO_VoidSetPinDirection(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8OUTPUT);
	EXTI_VoidInit(EXTI_FALLING_EDGE);
	while(1)
	{

	}

}

void __vector_1(void)__attribute__((signal));

void __vector_1(void)
{
	DIO_VoidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_2,DIO_u8HIGH);

}
