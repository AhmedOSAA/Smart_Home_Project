/* SPI.c
 * Created: 7/10/2023 4:09:29 PM
 * Author : ENG.Ahmed Osamaa
 */ 

/* Includes */

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"

/* MCAL */
#include "SPI_Priv.h"
#include "SPI_Cfg.h"
#include "SPI_Priv.h"


/* Call Back function */

void(*Private_SPI_CALLBACK)(void)  =  NULL   ;


//=======================================
//***************  APIs  ****************
//=======================================

void SPI_Init (S_SPICfg_t* CONFIG)
{
	// IMPORTANT NOTE : we must collect all configuration bits of SPCR register in a variable and then equal SPCR with it 
	// We must configure Pins Before SPI , Before anything
	
	uin8 config = 0 ;
	
	// Clock Rate
	if( CONFIG->Clock_Rate == SPI_Clock_Divide_DS2 || CONFIG->Clock_Rate == SPI_Clock_Divide_DS8 || CONFIG->Clock_Rate == SPI_Clock_Divide_DS32 || CONFIG->Clock_Rate == SPI_Clock_Divide_DS64 )
	{
		SPSR |= (uin8)(1<<0) ;
		config |= (CONFIG->Clock_Rate - 4) ;
	}else
	{
		config |= CONFIG->Clock_Rate ;
	}
	// Enable SPI
	config |= CONFIG->SPI_EN ;
	// SPI Mode
	config |= CONFIG->MODE ;
	// Data Order
	config |= CONFIG->DataORD ;
	// Data Mode
	config |= CONFIG->Data_Mode ;
	// Interrupt Enable
	config |= CONFIG->Interrupt_EN ;

	if(CONFIG->Interrupt_EN == SPI_Interrupt_Enable)
	{
		if(CONFIG->SPI_CALLBACK)
		{
			Private_SPI_CALLBACK = CONFIG->SPI_CALLBACK ;
		}
	}
	// configure the SPCR register at one time

	SPCR = config ;	
	
}
void SPI_DeInit (void)
{
	SPCR = (uin8) 0 ;
	SPSR = (uin8) 0 ;	
}
uin8 SPI_SendData (uin8 Data)
{
	SPDR = Data ;
	while (!(SPSR & (1<<7)));
	return SPDR ;
}
uin8 SPI_ReveiveData (uin8 DataTOsend )
{
	SPDR = DataTOsend ;
	while (!(SPSR & (1<<7))) ;
	return SPDR ;
}

void __vector_12(void)__attribute__((signal));
void __vector_12(void)
{
	if(Private_SPI_CALLBACK)
	{
		Private_SPI_CALLBACK();
	}
}

