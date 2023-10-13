/*
 * SPI_Priv.h
 * Created: 9/23/2023 11:58:47 AM
 * Author: ENG. Ahmed Osamaa
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_


//••••••••••••••••••••••••••••••••••••••••••••••
// Peripheral Registers Base Address : SPI 
//••••••••••••••••••••••••••••••••••••••••••••••


#define SPCR					(*(vuin8*)(0x2D))
#define SPSR					(*(vuin8*)(0x2E))
#define SPDR					(*(vuin8*)(0x2F))


#endif /* SPI_PRIV_H_ */