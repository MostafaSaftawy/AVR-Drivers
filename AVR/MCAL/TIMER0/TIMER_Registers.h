/*
 * TIMER_Registers.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

#define TCCR0 *((volatile u8* const) 0x53)
#define TCNT0 *((volatile u8* const) 0x52)
#define OCR0 *((volatile u8* const) 0x5C)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)
#define SREG *((volatile u8*)0x5F)

#define TCCR0_CS500 0
#define TCCR0_CS501 1
#define TCCR0_CS502 2
#define TCCR0_WGM01 3
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_WGM00 6
#define TCCR0_FOC0  7

#define MTIMER0_TOIE0             0
#define MTIMER0_OCIE0             1
#define MTIMER0_SREG_I            7

#define MTIMER0_PWM_NONINVERTED_OC0 2
#define MTIMER0_PWM_INVERTED_OC0    3

#endif /* TIMER_REGISTERS_H_ */
