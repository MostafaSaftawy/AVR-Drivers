/*
 * DIO.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef DIO_H_
#define DIO_H_

/* define my ports*/
#define DIO_u8PORT_A 0
#define DIO_u8PORT_B 1
#define DIO_u8PORT_C 2
#define DIO_u8PORT_D 3
/* define my pins */
#define DIO_u8PIN_0 0
#define DIO_u8PIN_1 1
#define DIO_u8PIN_2 2
#define DIO_u8PIN_3 3
#define DIO_u8PIN_4 4
#define DIO_u8PIN_5 5
#define DIO_u8PIN_6 6
#define DIO_u8PIN_7 7
/* Pin Value*/
#define DIO_u8HIGH 1
#define DIO_u8LOW  0
/* Pin Direction*/
#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

void DIO_VoidSetPinDirection( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir );
void DIO_VoidSetPinValue( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal );
u8 DIO_u8GetPinValue( u8 Copy_u8PortId , u8 Copy_u8PinId );
void DIO_VoidSetPortDirection(  u8 Copy_u8PortId, u8 Copy_u8PinDir );
void DIO_vidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PinVal );


#endif /* DIO_H_ */
