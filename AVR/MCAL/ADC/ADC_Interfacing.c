/*
 * ADC_Interfacing.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"

#include "ADC_Interfacing.h"
#include "ADC_Registers.h"
#include <avr/io.h>
#include "DIO.h"
#include "ADC_Config.h"
void ADC_StartConversion(void)
  {
	  SET_BIT(ADC_ADCSRA_REG,ADC_ADSC_BIT);

  }
void ADC_INIT(void)
{
	DIO_VoidSetPortDirection(DIO_u8PORT_A,DIO_u8INPUT);

/*Clear ADCSRA Reg*/
ADC_ADCSRA_REG = 0;

/*Choose ADC Prescaler*/
ADC_ADCSRA_REG = ADC_PRESCALER_VALUE ;

/*Enable ADC*/
SET_BIT(ADC_ADCSRA_REG,ADC_ADEN_BIT);


/*Choose V ref*/
ADC_ADMUX_REG = 0;
ADC_ADMUX_REG = (ADC_VREF<<6);
}
u16 ADC_READ(u8 PIN_NUM)
{
	 /*local variables*/
		  u16 DigitalVal = 0;
		  u32 AnalogVal  = 0;

		 /*Choose Channel*/
		 ADC_ADMUX_REG &= 0xf8;
		 ADC_ADMUX_REG |= PIN_NUM;

		 /*start conversion*/
		 ADC_StartConversion();

		 /*wait until conversion is complete*/
		 while(GET_BIT(ADC_ADCSRA_REG,ADC_ADSC_BIT));


		 /*Calculate Analog value*/
		 AnalogVal   = (((u32) DigitalVal )* 5000)/1024;

		 /*return analog value*/
		 return AnalogVal;
}

