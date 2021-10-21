/*
 * I2C_Prog.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Mostafa Saftawy
 */
#include "../LIB2/STD_TYPES.h"
#include "../LIB2/BIT_MATH.h"
#include "I2C_Registers.h"
#include "I2C_Interfacing.h"
#include "I2C_Config.h"

void I2C_voidInit(void)
{
	SET_BIT(TWCR,TWEN_BIT);     //Enable TWI
	TWBR = TWBR_VALUE;          //Set TWBR = 8
	//Prepare TWSR for masking TWPS0,TWPS1
	SET_BIT(TWSR,TWPS0_BIT);
	SET_BIT(TWSR,TWPS1_BIT);
	//Put MI2C TWPS Value in Reg TWSR
	TWSR &= ((TWPS_VALUE)|(TWSR_REG_MASK)) ;
	// Set My slave address
	TWAR = (SLAVE_ADDRESS<<1);
	//general call
	if (GENERAL_CALL_MODE == ENABLE_GENERAL_CALL)
	{
		SET_BIT(TWAR,TWGCE_BIT);
	}
}
void I2C_voidSendStartCondition(void)
{
	TWCR = (1<<TWINT_BIT)|(1<<TWSTA_BIT)|(1<<TWEN_BIT);  //Send Start condition + clear TWINT flag to start TWI operation
	while(GET_BIT(TWCR,TWINT_BIT)==0);                             //wait until start is transmitted
	TWCR = (1<<TWEN_BIT);                                          //clear start bit and all bits except enable
}
void I2C_voidSendStopCondition(void)
{
	TWCR = (1<<TWINT_BIT)|(1<<TWSTO_BIT)|(1<<TWEN_BIT);  //Send Stop condition + clear TWINT flag to start TWI operation
	while(GET_BIT(TWCR,TWINT_BIT)==0);                             //wait until stop is transmitted
}
u8   I2C_u8CheckStatus(u8 Copy_u8ExpectedStatus)
{
	if ((TWSR & TWSR_REG_MASK) == Copy_u8ExpectedStatus)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void I2C_voidSendSlaveAddress(u8 Copy_u8SlaveAdd)
{
	TWDR = (Copy_u8SlaveAdd<<1);  //Put address and operation in TWDR Reg
	TWCR = (1<<TWINT_BIT)|(1<<TWEN_BIT);   // reset flag Start sending address and operation
	while((GET_BIT(TWCR,TWINT_BIT))==0);        //wait until operation complete
}
void I2C_voidSendByte(u8 Copy_u8Data)
{
	TWDR = Copy_u8Data;
	TWCR = (1<<TWINT_BIT)|(1<<TWEN_BIT);   // reset flag Start sending Data
	while((GET_BIT(TWCR,TWINT_BIT))==0);        //wait until operation complete
}
u8   I2C_u8ReceiveDataWithNoAck(void)
{
	TWCR = (1<<TWINT_BIT)|(1<<TWEN_BIT);   // reset flag Start Receiving data
	while((GET_BIT(TWCR,TWINT_BIT))==0);        //wait until operation complete
	return 	TWDR;
}
