/*
 * DIO.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */


#include "STD_TYPES.h"
#include "Registers.h"
#include "BIT_MATH.h"
#include "DIO.h"


void DIO_VoidSetPortDirection( u8 Copy_u8PortId, u8 Copy_u8PinDir )
{
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A: DDRA=Copy_u8PinDir; break;
			case DIO_u8PORT_B: DDRB=Copy_u8PinDir; break;
			case DIO_u8PORT_C: DDRC=Copy_u8PinDir; break;
			case DIO_u8PORT_D: DDRD=Copy_u8PinDir; break;
		}
}

void DIO_vidSetPortValue( u8 Copy_u8PortId, u8 Copy_u8PinVal  )
{
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A: PORTA=Copy_u8PinVal; break;
			case DIO_u8PORT_B: PORTB=Copy_u8PinVal; break;
			case DIO_u8PORT_C: PORTC=Copy_u8PinVal; break;
			case DIO_u8PORT_D: PORTD=Copy_u8PinVal; break;
		}
}

u8 DIO_u8GetPinValue(  u8 Copy_u8PortId , u8 Copy_u8PinId )
{
	u8 Local_u8ReadPinValue;
	switch( Copy_u8PortId )
	{
			case DIO_u8PORT_A: Local_u8ReadPinValue=GET_BIT(PINA,Copy_u8PinId); break;
			case DIO_u8PORT_B: Local_u8ReadPinValue=GET_BIT(PINB,Copy_u8PinId); break;
			case DIO_u8PORT_C: Local_u8ReadPinValue=GET_BIT(PINC,Copy_u8PinId); break;
			case DIO_u8PORT_D: Local_u8ReadPinValue=GET_BIT(PIND,Copy_u8PinId); break;
	}
	return Local_u8ReadPinValue;
}

void DIO_VoidSetPinDirection( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir )
{
	if(Copy_u8PinDir == DIO_u8OUTPUT){
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A: SET_BIT(DDRA,Copy_u8PinId); break;
			case DIO_u8PORT_B: SET_BIT(DDRB,Copy_u8PinId); break;
			case DIO_u8PORT_C: SET_BIT(DDRC,Copy_u8PinId); break;
			case DIO_u8PORT_D: SET_BIT(DDRD,Copy_u8PinId); break;
		}
	}
	else if(Copy_u8PinDir == DIO_u8INPUT)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A: CLR_BIT(DDRA,Copy_u8PinId); break;
			case DIO_u8PORT_B: CLR_BIT(DDRB,Copy_u8PinId); break;
			case DIO_u8PORT_C: CLR_BIT(DDRC,Copy_u8PinId); break;
			case DIO_u8PORT_D: CLR_BIT(DDRD,Copy_u8PinId); break;
		}
	}
	else
	{

	}
}

void DIO_VoidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal )
{
	if(Copy_u8PinVal == DIO_u8HIGH){
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A: SET_BIT(PORTA,Copy_u8PinId); break;
			case DIO_u8PORT_B: SET_BIT(PORTB,Copy_u8PinId); break;
			case DIO_u8PORT_C: SET_BIT(PORTC,Copy_u8PinId); break;
			case DIO_u8PORT_D: SET_BIT(PORTD,Copy_u8PinId); break;
		}
	}
	else if(Copy_u8PinVal == DIO_u8LOW)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A: CLR_BIT(PORTA,Copy_u8PinId); break;
			case DIO_u8PORT_B: CLR_BIT(PORTB,Copy_u8PinId); break;
			case DIO_u8PORT_C: CLR_BIT(PORTC,Copy_u8PinId); break;
			case DIO_u8PORT_D: CLR_BIT(PORTD,Copy_u8PinId); break;
		}
	}
	else
	{

	}
}
