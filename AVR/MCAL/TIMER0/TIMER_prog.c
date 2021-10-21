/*
 * TIMER_prog.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "TIMER_Config.h"
#include "TIMER_Registers.h"
#include "TIMER_Interfacing.h"
#include "DIO.h"
void (*TIMER_PtrFunc)(void)=NULL;

u8   MTIMER0_u8TCCR0Value   = 0;
static u16 COUNTER=0;

void TIMER0_VoidInit(u8 Copy_ModeSelection){
#if (MTIMER0_MODE==MTIMER0_NORMAL_MODE)

		//Choose normal mode
		CLR_BIT(MTIMER0_u8TCCR0Value,TCCR0_WGM00);
		CLR_BIT(MTIMER0_u8TCCR0Value,TCCR0_WGM01);


		CLR_BIT(TCCR0,TCCR0_CS500);
		SET_BIT(TCCR0,TCCR0_CS501);    //Pre-Scaler 8
		CLR_BIT(TCCR0,TCCR0_CS502);

		#if (MTIMER0_INTERRUPT_STATUS == MTIMER0_INT_ENABLED)
		//enable Global interrupt
		SET_BIT(SREG,MTIMER0_SREG_I);
		//enable Timer0 Overflow interrupt
		SET_BIT(TIMSK,MTIMER0_TOIE0);
		#endif


	#elif (MTIMER0_MODE==MTIMER0_CTC_MODE)

		/*Choose CTC mode*/
		CLR_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);

		/*Set OC0 initial value*/
		MTIMER0_OCR0 = MTIMER0_OCR0_VALUE;


		CLR_BIT(TCCR0,TCCR0_CS500);
		SET_BIT(TCCR0,TCCR0_CS501);    //Pre-Scaler 8
		CLR_BIT(TCCR0,TCCR0_CS502);

		#if (MTIMER0_INTERRUPT_STATUS == MTIMER0_INT_ENABLED)
		//enable Global interrupt
		SET_BIT(MTIMER0_SREG,MTIMER0_SREG_I);
		//enable Timer0 Overflow interrupt
		SET_BIT(MTIMER0_TIMSK,MTIMER0_OCIE0);
		#endif

	#elif (MTIMER0_MODE==MTIMER0_FAST_PWM_MODE)

		/*Choose Fast PWM mode*/
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM00);
		SET_BIT(MTIMER0_u8TCCR0Value,MTIMER0_WGM01);

		CLR_BIT(TCCR0,TCCR0_CS500);
		SET_BIT(TCCR0,TCCR0_CS501);    //Pre-Scaler 8
		CLR_BIT(TCCR0,TCCR0_CS502);

	#else
		#error "Wrong Choose"
	#endif


}
void TIMER0_CallBackFunction(void(* Copy_Ptr2Func)(void)){

	if (Copy_Ptr2Func != NULL){
		TIMER_PtrFunc = Copy_Ptr2Func;
	}
}

void __vector_11(void){


	if(COUNTER == 3906){
		TIMER_PtrFunc();
		COUNTER=0;
	}
	else {
		COUNTER++;
	}
}

void __vector_10(void){
static u16 COUNTER=0;

	if(COUNTER == 4000){
		TIMER_PtrFunc();
		COUNTER=0;
	}
	else {
		COUNTER++;
	}
}
