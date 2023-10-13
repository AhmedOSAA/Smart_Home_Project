/*
 * USART_Cfg.h
 * Created: 9/22/2023 2:59:29 PM
 * Author: Eng. Ahmed Osama
 */ 


#ifndef USART_CFG_H_
#define USART_CFG_H_



typedef struct
{
	uin8 USART_Role ;		/* Specify the USART act as Tx or Rx or both */
	
	uin8 USART_Interrupt ;	/* Specify the USART trigger the data with Interrupt or polling */ 
	
	uin8 MODE ;				/* This bit selects between Asynchronous and Synchronous mode of operation. */
	
	uin8 Parity ;			/* Bits 5:4 – UPMn: Parity Mode [n = 1:0] */
	
	uin8 Stop_BIT ;			/* Bit 3 – USBS: Stop Bit Select This bit selects the number of stop bits */ 
	
	uin8 Data_Size ;		/* sets the number of data bits */
	
	uin8 CLK_Polarity ;		/* This bit is used for Synchronous mode only. Write this bit to zero when Asynchronous mode is used */
	
	uin32 Baud_Rate  ;		/* the most commonly used baud rates for asynchronous */
	
	uin8 Speed ;			/* Bit 1 – U2X: Double the USART Transmission Speed */
							/* will reduce the divisor of the baud rate divider from 16 to 8 effectively doubling the
							transfer rate */
	/* Call Back Function , the unused pointer must set with NULL &
	   NOTE : the used pointer to function will cause enable its interrupt */						
	void(*RXC_CALLBACK)(void);
	void(*UDRE_CALLBACK)(void);
	void(*TXC_CALLBACK)(void);
							
}S_USARTCfg_t;

/*  Configuration Reference */


 /*
  @ref : USART_Role
   
		1- USART_Role_Tx
		2- USART_Role_Rx
		3- USART_Role_Tx_Rx		
 
 */

/*
 @ref : USART_Interrupt 
	1- USART_Polling				
	2- USART_Interrupt_Tx			
	3- USART_Interrupt_Rx			
	4- USART_Interrupt_Tx_Rx		

*/

 
 /* @ref : MODE :
		1- USART_MODE_ASYNC
		2- USART_MODE_SYNC		
*/
 
 /*@ref : Parity :

		 1- USART_DISABLE						
		 2- USART_EVEN_PARITY					
		 3- USART_ODD_PARITY				
 
 */
 
 /*
 //@ref : Stop_BIT
		1- USART_STOP_1BIT	
		2- USART_STOP_2BIT					
 */
 
 /*
 //@ref: Data_Size

		1- USART_Data_5BIT
		2- USART_Data_6BIT
		3- USART_Data_7BIT
		4- USART_Data_8BIT
		5- USART_Data_9BIT	
 */
 
 /*
 //@ref : CLK_Polarity

		1- USART_polarity_DISABLE
		2- USART_Polarity_TX_Rising_RX_Fallinng
		3- USART_Polarity_TX_Falling_RX_Rising			
 */
 
 /*
	@ref : Baud_Rate

1-  USART_BaudRate_2400
2-  USART_BaudRate_4800
3-  USART_BaudRate_9600
4-  USART_BaudRate_14400
5-  USART_BaudRate_19200
6-  USART_BaudRate_28800
7-  USART_BaudRate_38400
8-  USART_BaudRate_57600		
9-  USART_BaudRate_76800		
10- USART_BaudRate_115200		
11- USART_BaudRate_230400		
12- USART_BaudRate_250000		
13- USART_BaudRate_500000		
14- USART_BaudRate_1M			

 */

#endif /* USART_CFG_H_ */