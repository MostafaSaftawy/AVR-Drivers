/*
 * SPI_Prog.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Mostafa Saftawy
 */



#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "SPI_Registers.h"
#include "SPI_Interfacing.h"
#include "DIO.h"


void MSPI_voidMasterInit(void)
{
	SET_BIT(SPCR,6); //Enable SPI Module
	CLEAR_BIT(SPCR,5); // Send MSB First
	SET_BIT(SPCR,4); //Set MSTR to Master Mode
	SET_BIT(SPCR,3); //Set CPOL to hight State
	SET_BIT(SPCR,2); //Set CPHA to Setup First
	CLEAR_BIT(SPSR,0); // Clear SPI2X
	SET_BIT(SPCR,1); //Set Bit rate to Fosc/128
	SET_BIT(SPCR,0); //Set Bit rate to Fosc/128

}

void MSPI_voidSlaeInit(void)
{
	SET_BIT(SPCR,6); //Enable SPI Module
	CLEAR_BIT(SPCR,5); // Send MSB First
	CLEAR_BIT(SPCR,4); //Set MSTR to Slave Mode
	SET_BIT(SPCR,3); //Set CPOL to hight State
	SET_BIT(SPCR,2); //Set CPOL to CPHA to Setup First
	CLEAR_BIT(SPSR,0); // Clear SPI2X
	SET_BIT(SPCR,1); //Set Bit rate to Fosc/128
	SET_BIT(SPCR,0); //Set Bit rate to Fosc/128

}
u8 SPI_u8Transfer(u8 Copy_Byte)
{
	SPDR= Copy_Byte;

	while((GET_BIT(SPSR,7))==0); //wit transfer completion
	return SPDR ;
}
