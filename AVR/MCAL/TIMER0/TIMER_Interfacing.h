/*
 * TIMER_Interfacing.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef TIMER_INTERFACING_H_
#define TIMER_INTERFACING_H_

void TIMER0_VoidInit(u8 Copy_ModeSelection);
void TIMER0_CallBackFunction(void(* Copy_Ptr2Func)(void));
void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));

#endif /* TIMER_INTERFACING_H_ */
