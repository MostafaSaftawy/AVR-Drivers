/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "DIO.h"
#include <avr/delay.h>

#include "Stepper_Config.h"
#include "Stepper_Interfacing.h"




int main(void)
{
	void Stepper_Init(void);

	while(1)
	{
		Stepper_FullStep_Right();
		_delay_ms(2000);
		Stepper_FullStep_Left();
		_delay_ms(2000);
		void Stepper_Stop(void);
		_delay_ms(2000);

	}

}
