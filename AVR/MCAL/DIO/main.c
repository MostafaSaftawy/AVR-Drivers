/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define FCPU 8000000
#include "util/delay.h"
#include "Registers.h"
#include "DIO.h"


int main( void )
{
	DIO_VoidSetPortDirection(DIO_u8PORT_A, 0);
	DIO_VoidSetPinDirection( DIO_u8PORT_A, 0, 1);

	while( 1 )
	{
		DIO_VoidSetPinValue( DIO_u8PORT_A, 0, 0);
		_delay_ms(1000);
		DIO_VoidSetPinValue( DIO_u8PORT_A, 0, 1);
		_delay_ms(1000);
	}
	return 0;
}


