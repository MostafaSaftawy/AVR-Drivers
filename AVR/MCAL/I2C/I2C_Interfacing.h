/*
 * I2C_Interfacing.h
 *
 *  Created on: Aug 29, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef I2C_INTERFACING_H_
#define I2C_INTERFACING_H_

//I2C Expected status
#define START_SENT                   0x08
#define REPEATED_START_SENT          0x10
#define SLA_W_SENT_WITH_ACK          0x18
#define SLA_W_SENT_WITHOT_ACK        0x20
#define DATA_SENT_WITH_ACK           0x28
#define DATA_SENT_WITHOUT_ACK        0x30
#define ARBITRATION_LOST             0x38
#define SLA_R_RECEIVED_WITH_ACK      0x40
#define SLA_R_RECEIVED_WITHOT_ACK    0x48
#define DATA_RECEIVED_WITH_ACK       0x50
#define DATA_RECEIVED_WITHOUT_ACK    0x58

#define MI2C_WRITE_OP  0
#define MI2C_READ_OP   1

void I2C_voidInit(void);
void I2C_voidSendStartCondition(void);
void I2C_voidSendStopCondition(void);
u8   I2C_u8CheckStatus(u8 Copy_u8ExpectedStatus);
void I2C_voidSendSlaveAddress(u8 Copy_u8SlaveAdd);
void I2C_voidSendByte(u8 Copy_u8Data);
u8   I2C_u8ReceiveDataWithNoAck(void);


#endif /* I2C_INTERFACING_H_ */
