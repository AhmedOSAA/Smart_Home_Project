/*
 * USART_Prog.c
 * Created: 9/22/2023 3:00:01 PM
 * Author: Eng. Ahmed Osama
 */ 

/* Includes */

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*#include "AVR_delay_Handling.h"*/
/* MCAL */
#include "USART_Priv.h"
#include "USART_Cfg.h"
#include "USART_Int.h"

/* Call Back function */
void(*Private_RXC_CALLBACK)(void)  =  NULL   ;
void(*Private_UDRE_CALLBACK)(void) =  NULL   ;
void(*Private_TXC_CALLBACK)(void)  =  NULL   ;

/* Global Variables */
S_USARTCfg_t Global_USART_CFG ;


/* APIs */

void USART_Init(S_USARTCfg_t* USART_CFG)
{
	Global_USART_CFG = *USART_CFG ;
	vuin8 tmpReg_UCSRC = 0 ;
	vuin8 tmpReg_UCSRB = 0 ;
	vuin16 tmpReg_UBRRL= 0 ;
	vuin8 tmpReg_UBRRH = 0 ;
	
	
	/* Set Configuration for UCSRB Reg. */
	tmpReg_UCSRB |= (USART_CFG->USART_Role << TXEN);  /* Set USART Role */
	
	UCSRB = tmpReg_UCSRB ;
	
	/* Set Configuration UCSRC Reg. */
	SET_BIT(UCSRC,URSEL);
	tmpReg_UCSRC |= (USART_CFG->MODE << UMSEL) ;    /* Set Mode */
	tmpReg_UCSRC |= (USART_CFG->Parity << UPM0 );  /* Set Parity bit */
	tmpReg_UCSRC |= (USART_CFG->Stop_BIT << USBS ); /*  Set Stop bit */
	tmpReg_UCSRC |= (((USART_CFG->Data_Size) & 0b011) << UCSZ0 ); /*  Set Data Size */
	if(USART_CFG->Data_Size == USART_Data_9BIT)	 /* if data 9bit set UCSZ2 bit in UCSRB Reg  */
	{UCSRB |= (1<<UCSZ2);}
	if( (USART_CFG->CLK_Polarity == USART_Polarity_TX_Falling_RX_Rising) || (USART_CFG->CLK_Polarity == USART_Polarity_TX_Rising_RX_Fallinng) )
	{tmpReg_UCSRC |= (USART_CFG->CLK_Polarity << UCPOL );} /*  Set Polarity if using SYNC mode */
	
	UCSRC |= tmpReg_UCSRC ;
	
	/* Set Baud Rate */
	
	/* Calculate Value of UBRRL Reg */
	if(USART_CFG->MODE == USART_MODE_SYNC )
	{
		tmpReg_UBRRL = (F_CPU/(2*USART_CFG->Baud_Rate))-1 ;
	}else
	{
		if(USART_CFG->Speed == USART_Speed_Double)
		{
			tmpReg_UBRRL = (F_CPU/(8*USART_CFG->Baud_Rate))-1 ;
		}else
		{
			tmpReg_UBRRL = (F_CPU/(16*USART_CFG->Baud_Rate))-1 ;
		}
	}
	/* Check if Value of UBRRL Reg is greater than 2byte */
	if(tmpReg_UBRRL > 255)
	{
		tmpReg_UBRRH = (uin8)((tmpReg_UBRRL & 0x0F00)>>8) ;
		tmpReg_UBRRL = tmpReg_UBRRL & 0x00FF ;
		
		UBRRL = (uin8)tmpReg_UBRRL;
		
		CLR_BIT(UCSRC , URSEL);
		UBRRH |= tmpReg_UBRRH ;
		SET_BIT(UCSRC , URSEL);
	}else
	{
		tmpReg_UBRRL = tmpReg_UBRRL & 0x00FF ;
		UBRRL = (uin8)tmpReg_UBRRL	;
	}
	
	/* CallBack Function & Enable Interrupt */ /* Set USART Trigger data with Interrupt or polling */
	if(USART_CFG->USART_Interrupt != USART_Polling)
	{
		if(USART_CFG->RXC_CALLBACK)
		{
			Private_RXC_CALLBACK = USART_CFG->RXC_CALLBACK ;
			SET_BIT(UCSRB,RXCIE);		
		}
		if(USART_CFG->UDRE_CALLBACK)
		{
			Private_UDRE_CALLBACK = USART_CFG->UDRE_CALLBACK ;
			SET_BIT(UCSRB,UDRIE);
		}
		if(USART_CFG->TXC_CALLBACK)
		{
			Private_TXC_CALLBACK = USART_CFG->TXC_CALLBACK ;
			SET_BIT(UCSRB,TXCIE);
		}
	}	
}

void USART_Transmitter(uin16 DataTx)
{
	if((Global_USART_CFG.USART_Interrupt != USART_Interrupt_Tx) && (Global_USART_CFG.USART_Interrupt != USART_Interrupt_Tx_Rx))
	{
		while(!(GET_BIT(UCSRA,UDRE)));
	}
	if(Global_USART_CFG.Data_Size == USART_Data_9BIT)
	{
		SET_MULTIBIT(UCSRB,ONE_BIT,TXB8, GET_BIT(DataTx , 8));
	}
	UDR = (uin8)(DataTx & 0x0FF);
}

void USART_Recevier(in16* DataRx)
{
	*DataRx = 0 ;
	uin16 ninth = 0  ;
	uin16 Data = 0 ;
	if((Global_USART_CFG.USART_Interrupt != USART_Interrupt_Rx) && (Global_USART_CFG.USART_Interrupt != USART_Interrupt_Tx_Rx))
	{
		while(!(GET_BIT(UCSRA,RXC)));
	}
	if(Global_USART_CFG.Data_Size == USART_Data_9BIT)
	{
		//SET_MULTIBIT(*DataRx,ONE_BIT,8,GET_BIT(UCSRB,RXB8));
		ninth = GET_BIT(UCSRB,RXB8) ;
		Data = UDR ;
		*DataRx = ((ninth<<8) | Data) ;
	}else
	{
		Data = UDR ;
		*DataRx = Data ;
	}
	//*DataRx |= (UDR & 0xFF) ;
}


void USART_TransmitterString(in8* DataTx)
{
	while(*DataTx)
	{
		USART_Transmitter(*DataTx++);
	}
}

void USART_RecevierString(in8* DataRx)
{
	in8* orgine_add = DataRx ;
	in8 Trigger_Stop = 0 ;
	while(Trigger_Stop != Enter)
	{
		USART_Recevier((in16*)DataRx);
		Trigger_Stop = *DataRx ;
		if(Trigger_Stop == Enter) {*DataRx = 0 ;}
		else if(Trigger_Stop == Backspace && DataRx != orgine_add ) {DataRx--;}
		else if(Trigger_Stop == Backspace && DataRx == orgine_add ) { /* Do Nothing */}
		else{DataRx++;}
	}
}


/* ISR functions */

void __vector_13(void)__attribute__((signal));
void __vector_13(void)
{
	if(Private_RXC_CALLBACK)
	{
		Private_RXC_CALLBACK();
	}
}

void __vector_14(void)__attribute__((signal));
void __vector_14(void)
{
	if(Private_UDRE_CALLBACK)
	{
		Private_UDRE_CALLBACK();
	}
}

void __vector_15(void)__attribute__((signal));
void __vector_15(void)
{
	if(Private_TXC_CALLBACK)
	{
		Private_TXC_CALLBACK();
	}
}
