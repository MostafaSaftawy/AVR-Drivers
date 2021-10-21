/*
 * EXTI_Interfacing.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"

#include "DIO.h"
#include "Registers.h"
#include "EXTI_Registers.h"
#include "EXTI_Interfacing.h"

void EXTI_VoidInit(u8 Copy_u8SenseLevel)
{
	// Set Direction Pin to Input
	DIO_VoidSetPinDirection(EXTI_INT0_PORT,EXTI_INT0_PIN,DIO_u8INPUT);

	// Enable Pull-up resistor
	DIO_VoidSetPinValue(EXTI_INT0_PORT,EXTI_INT0_PIN,DIO_u8HIGH);

	//Enable PIE of INT0
	SET_BIT(GICR,GICR_INT0);

	// Enable GIE
	SET_BIT(SREG,SREG_I);

	//Chose Sense level

	switch(Copy_u8SenseLevel)
	{
		case EXIT_LOWL_EVEL:CLR_BIT(MCUCR,MCUCR_ISC00);
							CLR_BIT(MCUCR,MCUCR_ISC01);
							break;
		case EXIT_RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC00);
							SET_BIT(MCUCR,MCUCR_ISC01);
							break;
		case EXTI_FALLING_EDGE : CLR_BIT(MCUCR,MCUCR_ISC00);
								SET_BIT(MCUCR,MCUCR_ISC01);
								break;
		case EXIT_ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC00);
							CLR_BIT(MCUCR,MCUCR_ISC01);
							break;
		default:break;

	}
}

