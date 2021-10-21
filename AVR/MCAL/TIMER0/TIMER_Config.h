/*
 * TIMER_Config.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define MTIMER0_NORMAL_MODE       0
#define MTIMER0_CTC_MODE          1
#define MTIMER0_FAST_PWM_MODE     2
#define MTIMER0_PRESCALER       	Prescaller_8
#define TIMER0_INTERRUPT_STATUS     TIMER0_INT_ENABLED
#define MTIMER0_OC0_MODE   			MTIMER0_DISCONNECT_OC0
#define MTIMER0_OCR0_VALUE 			250

#define NULL (void *) 0


#endif /* TIMER_CONFIG_H_ */
