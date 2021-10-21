/*
 * ADC_Interfacing.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef ADC_INTERFACING_H_
#define ADC_INTERFACING_H_

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"

#define ADC0	00000
#define ADC1	00001
#define ADC2	00010
#define ADC3	00011
#define ADC4	00100
#define ADC5	00101
#define ADC6	00110
#define ADC7	00111

void ADC_StartConversion(void);
void ADC_INIT(void);
u16 ADC_READ(u8 PIN_NUM);

#endif /* ADC_INTERFACING_H_ */
