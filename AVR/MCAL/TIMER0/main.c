/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Mostafa Saftawy
 */

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "TIMER_Config.h"
#include "TIMER_Interfacing.h"
#include "TIMER_Registers.h"
#include "DIO.h"
static u8 Flag=0;

void LED(void);

int main(void){
	DIO_VoidSetPinDirection(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8OUTPUT );
	DIO_VoidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8HIGH);
	TIMER0_CallBackFunction(LED);
	TIMER0_VoidInit(MTIMER0_FAST_PWM_MODE);
	while(1){

	}
}


void LED(void){
	if(Flag == 0){
		DIO_VoidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8LOW);
		Flag =1;
	}
	else {
		DIO_VoidSetPinValue(DIO_u8PORT_A,DIO_u8PIN_0,DIO_u8HIGH);
		Flag = 0;
	}

}
