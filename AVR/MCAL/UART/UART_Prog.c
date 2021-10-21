/*
 * UART_Prog.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Mostafa Saftawy
 */

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "DIO.h"
#include "UART_Interfacing.h"
#include "UART_Registers.h"
#include "UART_Config.h"

void UART_VoidInit(void){
	u8 Local=0;

		/*Receive enable config*/
		SET_BIT(Local, UART_URSEL);
		/*Mode config (Asynchronous-Synchronous)*/
		CLR_BIT(Local, UART_UMSEL);
		/*Parity Mode config*/
		CLR_BIT(Local, UART_UPM1);
		CLR_BIT(Local, UART_UPM0);
		/*Stop Bits config*/
		CLR_BIT(Local, UART_USBS);
		/* 8 bits */
		SET_BIT(Local, UART_UCSZ0);
		SET_BIT(Local, UART_UCSZ1);
		CLR_BIT(UART_UCSRB, UART_UCSZ2);

		UART_UCSRC = Local ;

		SET_BIT(UART_UCSRB, UART_RXC);
		SET_BIT(UART_UCSRB, UART_TXC);
		UART_UBRRH = UART_BAUDRATE_9600 ;

}

void UART_VoidUARTSendData(u8 Copy_u8SendByte)
{
	 while ((GET_BIT(UART_UCSRA,UART_UDRE))==0);
	 UART_UDR = Copy_u8SendByte;
}

u8 UART_VoidUARTRecieveData(void){
	 while ((GET_BIT(UART_UCSRA,UART_RXC))==0);
return UART_UDR;
}



