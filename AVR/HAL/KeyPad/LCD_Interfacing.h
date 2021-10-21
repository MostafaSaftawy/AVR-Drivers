/*
 * LCD_Interfacing.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef LCD_INTERFACING_H_
#define LCD_INTERFACING_H_

#include "../LIB2/STD_TYPES.h"

void LCD_VoidInit(void);
void LCD_VoidSendCommand(u8 Copy_u8Command);
void LCD_VoidSendData(u8 Copy_u8Data);
void LCD_sendString(const char* Copy_String);
void LCD_VoidGoToXY(u8 copy_u8XPosition, u8 copy_u8YPosition);


#endif /* LCD_INTERFACING_H_ */
