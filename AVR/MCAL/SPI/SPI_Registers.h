/*
 * SPI_Registers.h
 *
 *  Created on: Aug 29, 2021
 *      Author: Mostafa Saftawy
 */

#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

#define SPDR (*(volatile u8 *)(0x2F))  //SPDR Reg
#define SPSR (*(volatile u8 *)(0x2E))  //SPSR Reg
#define SPCR (*(volatile u8 *)(0x2D))  //SPCR Reg

/* SPCR reg bits */

#define SPIE_BIT 7
#define SPE_BIT  6
#define DORD_BIT 5
#define MSTR_BIT 4
#define CPOL_BIT 3
#define CPHA_BIT 2
#define SPR1_BIT 1
#define SPR2_BIT 0

/* SPSR reg bits */

#define SPIF_BIT  7
#define WCOL_BIT  6
#define SPI2x_BIT 0



#endif /* SPI_REGISTERS_H_ */
