/*
 * I2C_Registers.h
 *
 *  Created on: Aug 29, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef I2C_REGISTERS_H_
#define I2C_REGISTERS_H_

#define TWCR   (*(volatile u8 *)(0x56))
#define TWDR   (*(volatile u8 *)(0x23))
#define TWAR   (*(volatile u8 *)(0x22))
#define TWSR   (*(volatile u8 *)(0x21))
#define TWBR   (*(volatile u8 *)(0x20))

//TWCR REG
#define TWIE_BIT     0
#define TWEN_BIT     2
#define TWWC_BIT     3
#define TWSTO_BIT    4
#define TWSTA_BIT    5
#define TWEA_BIT     6
#define TWINT_BIT    7

#define TWPS0_BIT    0
#define TWPS1_BIT    1

#define TWGCE_BIT    0

//TWPS Values
#define TWPS_1   0
#define TWPS_4   1
#define TWPS_16  2
#define TWPS_64  3

#define DISABLE_GENERAL_CALL 0
#define ENABLE_GENERAL_CALL  1

#define TWSR_REG_MASK 0xF8

#endif /* I2C_REGISTERS_H_ */
