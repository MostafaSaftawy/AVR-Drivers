/*
 * EXTI_Interfacing.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef EXTI_INTERFACING_H_
#define EXTI_INTERFACING_H_

#define EXTI_INT0_PORT DIO_u8PORT_D
#define EXTI_INT0_PIN DIO_u8PIN_2


#define EXIT_LOWL_EVEL 0
#define EXIT_RISING_EDGE 1
#define EXTI_FALLING_EDGE 2
#define EXIT_ON_CHANGE 3

void EXTI_VoidInit(u8 Copy_u8SenseLevel);


#endif /* EXTI_INTERFACING_H_ */
