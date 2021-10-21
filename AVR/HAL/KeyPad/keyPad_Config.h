/*
 * keyPad_Config.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_PORT 		DIO_u8PORT_A
#define KEY_u8COLUMN_0		DIO_u8PIN_0
#define KEY_u8COLUMN_1		DIO_u8PIN_1
#define KEY_u8COLUMN_2		DIO_u8PIN_2
#define KEY_u8COLUMN_3		DIO_u8PIN_3

#define KEY_u8ROW_0			DIO_u8PIN_4
#define KEY_u8ROW_1			DIO_u8PIN_5
#define KEY_u8ROW_2			DIO_u8PIN_6
#define KEY_u8ROW_3			DIO_u8PIN_7

#define KEY_u8NOTPRESSED 100

#define KEYPAD_u8COLUMNS_NUMBER		4
#define KEYPAD_u8ROWS_NUMBER		4

#define KEYPAD_ARRAY_VALUES {{0, 1, 2, 3},{4, 5, 6, 7},{8, 9, 10, 11},{12, 13, 14, 15}}

#endif /* KEYPAD_CONFIG_H_ */
