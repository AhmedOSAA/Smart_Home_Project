/*
 * DIO_Prog.c
 * Created: 9/8/2023 11:28:07 AM
 * Author: ENG.Ahmed Osama
 */ 

#include "DIO_int.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"


/* ******* Generic Function ******* */


DIO_typedef* whichDIO(uin8* PXx)
{
	DIO_typedef *DIOx ;
	if(*PXx >= 0 && *PXx < 8)
	{
		DIOx = DIOA ;
	}
	
	if(*PXx >= 8 && *PXx < 16)
	{
		DIOx = DIOB ;
		*PXx -= 8 ; 	
	}
		
	if(*PXx >= 16 && *PXx < 24)
	{
		DIOx = DIOC ;
		*PXx -= 16 ;	
	}
	
	if(*PXx >= 24 && *PXx < 32)
	{
		DIOx = DIOD ;
		*PXx -= 24 ;	
	}
	return DIOx ;
}


/* ******* APIs Defination ******* */


void DIO_init()
{
	uin8 i ;
	for(i=0 ; i<8 ; i++){
		if(PA_arr[i] == PIN_Input_PU){
			DIOA->PORT |= 1<<i ; 
		}	
		else if(PA_arr[i] == PIN_Input){
			/* By Default Input */
		}
		else
		{
			/* PIN_Output_Low */
			DIOA->DDR |= 1<<i ;
			if(PA_arr[i] == PIN_Output_High)
			{
				DIOA->PORT |= 1<<i ;
			}	
		}
	}
	for(i=0 ; i<8 ; i++){
		if(PB_arr[i] == PIN_Input_PU){
			DIOB->PORT |= 1<<i ;
		}
		else if(PB_arr[i] == PIN_Input){
			/* By Default Input */
		}
		else
		{
			/* PIN_Output_Low */
			DIOB->DDR |= 1<<i ;
			if(PB_arr[i] == PIN_Output_High)
			{
				DIOB->PORT |= 1<<i ;
			}
		}
	}
	for(i=0 ; i<8 ; i++){
		if(PC_arr[i] == PIN_Input_PU){
			DIOC->PORT |= 1<<i ;
		}
		else if(PC_arr[i] == PIN_Input){
			/* By Default Input */
		}
		else
		{
			/* PIN_Output_Low */
			DIOC->DDR |= 1<<i ;
			if(PC_arr[i] == PIN_Output_High)
			{
				DIOC->PORT |= 1<<i ;
			}
		}
	}
	for(i=0 ; i<8 ; i++){
		if(PD_arr[i] == PIN_Input_PU){
			DIOD->PORT |= 1<<i ;
		}
		else if(PD_arr[i] == PIN_Input){
			/* By Default Input */
		}
		else
		{
			/* PIN_Output_Low */
			DIOD->DDR |= 1<<i ;
			if(PD_arr[i] == PIN_Output_High)
			{
				DIOD->PORT |= 1<<i ;
			}
		}
	}
}



void DIO_SetPinDir(uin8 PXx , Dir_t Direction)
{
	/*Specify DIOx*/
	DIO_typedef * DIOx ;
	DIOx = whichDIO(&PXx);
	
	if(Direction == In)
	{
		DIOx->DDR &= ~(1<<PXx); 
	}else if(Direction ==Out)
	{
		DIOx->DDR |=  (1<<PXx);	
	}
}

/* Mode Based on @ref :  PIN_Output_LoW			
						 PIN_Output_High			
						 PIN_Input				
						 PIN_Input_PU		*/
void DIO_SetPinMode(uin8 PXx , uin8 Mode)
{
	/*Specify DIOx*/
	DIO_typedef * DIOx ;
	DIOx = whichDIO(&PXx);
	
	if(Mode == PIN_Input_PU)
	{
		DIOx->DDR &= ~(1<<PXx) ;
		DIOx->PORT |=  (1<<PXx) ;
	}
	else if(Mode == PIN_Input)
	{
		DIOx->DDR &= ~(1<<PXx) ;
		DIOx->PORT &= ~(1<<PXx) ;
	}
	else
	{
		/* PIN_Output_Low */
		DIOx->DDR |= 1<<PXx ;
		if(Mode == PIN_Output_High)
		{
			DIOx->PORT |= 1<<PXx ;
		}
	}	
}

void DIO_WritePinVal(uin8 PXx , Value_t Val)
{
	/*Specify DIOx*/
	DIO_typedef * DIOx ;
	DIOx = whichDIO(&PXx);
	
	if(Val == Low)
	{
		DIOx->PORT &= ~(1<<PXx);
	}else if(Val == High)
	{
		DIOx->PORT |=  (1<<PXx);
	}
}


void DIO_WritePortVal(DIO_typedef * DIOx ,  uin8 Val)
{
	DIOx->PORT = Val ;
}

void DIO_ReadPinVal(uin8 PXx , uin8* res)
{
	/*Specify DIOx*/
	DIO_typedef * DIOx ;
	DIOx = whichDIO(&PXx);
	
	*res = ((DIOx->PIN & (1<<PXx)) >>PXx) ; 
}


void DIO_ReadPortVal(DIO_typedef * DIOx ,  uin8* Buffer)
{
	*Buffer = DIOx->PIN ;
}
