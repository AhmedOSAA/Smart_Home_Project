/*
 * DIO_int.h
 * Created: 9/8/2023 11:26:47 AM
 * Author: ENG.Ahmed Osama
 */ 

#include "STD_TYPES.h"
#include "DIO_Prv.h"


#ifndef DIO_INT_H_
#define DIO_INT_H_

/* Macros configuration reference */

/*Macros Pins*/
/* DIOA */
#define PA0			0
#define PA1			1
#define PA2			2
#define PA3			3
#define PA4			4
#define PA5			5
#define PA6			6
#define PA7			7

/* DIOB */
#define PB0			8
#define PB1			9
#define PB2			10
#define PB3			11
#define PB4			12
#define PB5			13
#define PB6			14
#define PB7			15

/* DIOC */
#define PC0			16
#define PC1			17
#define PC2			18
#define PC3			19
#define PC4			20
#define PC5			21
#define PC6			22
#define PC7			23

/* DIOD */
#define PD0			24
#define PD1			25
#define PD2			26
#define PD3			27
#define PD4			28
#define PD5			29
#define PD6			30
#define PD7			31

/*Generic enum*/

typedef enum
{
	In,
	Out
}Dir_t;

typedef enum
{
	Low  = 0 ,
	High = 1
}Value_t;


/* •••••••• Pin configuration •••••••• */
/*@ref : PIN_Define */
#define PIN_Output_LoW			0x1
#define PIN_Output_High			0x3
#define PIN_Input				0x0
#define PIN_Input_PU			0x2


/* ******* Generic Function ******* */

DIO_typedef* whichDIO(uin8* PXx);

/* APIs */

void DIO_init();

void DIO_SetPinDir(uin8 PXx , Dir_t Direction);
void DIO_SetPinMode(uin8 PXx , uin8 Mode);
void DIO_WritePinVal(uin8 PXx , Value_t Val);
void DIO_WritePortVal(DIO_typedef * DIOx ,  uin8 Val);
void DIO_ReadPinVal(uin8 PXx , uin8* res);
void DIO_ReadPortVal(DIO_typedef * DIOx ,  uin8* Buffer);






#endif /* DIO_INT_H_ */