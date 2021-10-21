/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Mostafa Saftawy
 */

 */

#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "Registers.h"
#include "DIO.h"
#include "DC_Config.h"
#include "DC_Interfacing.h"
#include <avr/delay.h>

int main(void)
{
	 DC_Init();

	 while(1)
	 {
		 DC_Move();
		_delay_ms(1000);
		DC_Stop();
		_delay_ms(1000);
	 }
}
