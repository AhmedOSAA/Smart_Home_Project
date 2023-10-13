/*
 * DIO_Prv.h
 * Created: 9/8/2023 11:27:10 AM
 * Author: ENG.Ahmed Osama
 */ 

#include "STD_TYPES.h"

#ifndef DIO_PRV_H_
#define DIO_PRV_H_

/*------------------------------------
 *	Base addresses for DIO Peripheral
 *------------------------------------
 */

#define DIOA_Base			0x39
#define DIOB_Base			0x36
#define DIOC_Base			0x33
#define DIOD_Base			0x30

/*•••••••• DIO Registers ••••••••*/

typedef struct
{
	vuin8 PIN ;
	vuin8 DDR ;
	vuin8 PORT;
	
}DIO_typedef;


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
** Peripheral Instants
**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#define DIOA	((DIO_typedef *)(DIOA_Base))
#define DIOB	((DIO_typedef *)(DIOB_Base))
#define DIOC	((DIO_typedef *)(DIOC_Base))
#define DIOD	((DIO_typedef *)(DIOD_Base))

#endif /* DIO_PRV_H_ */