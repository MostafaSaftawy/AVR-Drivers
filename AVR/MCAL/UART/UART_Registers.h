/*
 * UART_Registers.h
 *
 *  Created on: Aug 26, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

/*  UART Registers */

#define UART_UBRRL  (*(volatile u8 *)(0x29))
#define UART_UCSRB  (*(volatile u8 *)(0x2A))
#define UART_UCSRA  (*(volatile u8 *)(0x2B))
#define UART_UDR    (*(volatile u8 *)(0x2C))
#define UART_UCSRC  (*(volatile u8 *)(0x40))
#define UART_UBRRH  (*(volatile u8 *)(0x40))

/*UCSRA Register*/
#define UART_RXC                 7
#define UART_TXC                 6
#define UART_UDRE                5
#define UART_FE                  4
#define UART_DOR                 3
#define UART_PE                  2
#define UART_U2X                 1
#define UART_MPCM                0

/*UCSRB Register*/
#define UART_RXCIE               7
#define UART_TXCIE               6
#define UART_UDRIE               5
#define UART_RXEN                4
#define UART_TXEN                3
#define UART_UCSZ2               2
#define UART_RXB8                1
#define UART_TXB8                0

/*UCSRC Register*/
#define UART_URSEL               7
#define UART_UMSEL               6
#define UART_UPM1                5
#define UART_UPM0                4
#define UART_USBS                3
#define UART_UCSZ1               2
#define UART_UCSZ0               1
#define UART_UCPOL               0

/* Enable & Disable */
#define UART_DISABLED            0
#define UART_ENABLED             1

 /* UMSEL Bit Settings */
#define UART_ASYNCHRONOUS        0
#define UART_SYNCHRONOUS         1

/* Parity Mode */
#define UART_EVEN_PARITY         2
#define UART_ODD_PARITY          3

/* USBS Bit Settings */
#define UART_1_STOP_BIT          0
#define UART_2_STOP_BIT          1

/* UCSZ Bits Settings */
#define UART_5_BITS              0
#define UART_6_BITS              1
#define UART_7_BITS              2
#define UART_8_BITS              3
#define UART_9_BITS              7

/* UCPOL Bit Settings */

#define UART_FALLING_EDGE 		0
#define UART_RISING_EDGE  		1

/* Baud Rate */

#define UART_BAUDRATE_9600       51


#endif /* UART_REGISTERS_H_ */
