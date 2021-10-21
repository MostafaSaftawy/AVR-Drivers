/*
 * ADC_Registers.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#define ADC_SFIOR_REG     (*(volatile u8 *)(0x50))
#define ADC_ADMUX_REG     (*(volatile u8 *)(0x27))
#define ADC_ADCSRA_REG    (*(volatile u8 *)(0x26))
#define ADC_ADCH_REG      (*(volatile u8 *)(0x25))
#define ADC_ADCL_REG      (*(volatile u8 *)(0x24))

/*ADMUX Reg*/
#define ADC_MUX0_BIT        0
#define ADC_MUX1_BIT        1
#define ADC_MUX2_BIT		2
#define ADC_MUX3_BIT		3
#define ADC_MUX4_BIT		4
#define ADC_ADLAR_BIT		5
#define ADC_REFS0_BIT		6
#define ADC_REFS1_BIT		7

/*ADCSRA Reg*/
#define ADC_ADPS0_BIT       0
#define ADC_ADPS1_BIT       1
#define ADC_ADPS2_BIT		2
#define ADC_ADIE_BIT		3
#define ADC_ADIF_BIT		4
#define ADC_ADATE_BIT		5
#define ADC_ADSC_BIT		6
#define ADC_ADEN_BIT		7

/*SFIOR Reg*/
#define ADC_ADTS0_BIT		5
#define ADC_ADTS1_BIT		6
#define ADC_ADTS2_BIT		7

/*VREF Select*/
#define ADC_AREF		            0
#define ADC_AVCC					1
#define ADC_INTERNAL_VREF			3

/*ADC Input CLK Pre-scaler*/
#define ADC_PRESCALER_2			1
#define ADC_PRESCALER_4			2
#define ADC_PRESCALER_8			3
#define ADC_PRESCALER_16			4
#define ADC_PRESCALER_32			5
#define ADC_PRESCALER_64			6
#define ADC_PRESCALER_128			7

#endif /* ADC_REGISTERS_H_ */
