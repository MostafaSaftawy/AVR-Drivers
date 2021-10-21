/*
 * DC.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Mostafa Saftawy
 */
#include "Registers.h"
#include "DIO.h"
#include "DC_Config.h"
#include "DC_Interfacing.h"

void DC_Init(void)
{
	DIO_VoidSetPortDirection( DIO_u8PORT_A,  DIO_u8OUTPUT );

}
void DC_Stop(void)
{
	DIO_VoidSetPinValue(DC_PORT,DIO_u8PIN_0,DIO_u8LOW);
}
void DC_Move(void)
{
	DIO_VoidSetPinValue(DC_PORT,DIO_u8PIN_0,DIO_u8HIGH);

}
