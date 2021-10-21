/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "UART_Interfacing.h"
#include "DIO.h"

int main (void){

	UART_VoidInit();
	DIO_VoidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_0,DIO_u8INPUT);
	DIO_VoidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORT_D,DIO_u8PIN_2,DIO_u8OUTPUT);

	 UART_VoidUARTSendData('1');

	while(1){
		if(UART_VoidUARTRecieveData()== 'a'){
			 DIO_VoidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_2,DIO_u8HIGH );
			 UART_VoidUARTSendData('1');
		}
		else {

			 DIO_VoidSetPinValue(DIO_u8PORT_D,DIO_u8PIN_2,DIO_u8LOW );
			 UART_VoidUARTSendData('0');
		}
	}



}

