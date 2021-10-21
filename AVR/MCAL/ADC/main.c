/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "ADC_Interfacing.h"
#include "DIO.h"

int main(void){
	 ADC_INIT();
	DIO_VoidSetPortDirection(DIO_u8PORT_C,DIO_u8OUTPUT);
	u16 ADC_Val=0;

	while(1){
		ADC_Val=ADC_READ(ADC0);
		if((u16)ADC_Val >1000){
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_0 ,  DIO_u8HIGH );
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_1 ,  DIO_u8LOW );
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_2 ,  DIO_u8LOW );

		}
		else if ((u16)ADC_Val >1000){
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_0 ,  DIO_u8LOW );
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_1 ,  DIO_u8HIGH );
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_2 ,  DIO_u8LOW );
		}
		else {
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_0 ,  DIO_u8LOW );
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_1 ,  DIO_u8LOW );
			DIO_VoidSetPinValue(  DIO_u8PORT_C ,  DIO_u8PIN_2 ,  DIO_u8HIGH);
		}
	}




}


