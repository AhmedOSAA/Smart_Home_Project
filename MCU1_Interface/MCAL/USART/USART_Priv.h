/*
 * USART_Priv.h
 * Created: 9/22/2023 2:59:42 PM
 * Author: Eng. Ahmed Osama
 */ 


#ifndef USART_PRIV_H_
#define USART_PRIV_H_

/* Private Configuration Reference */


/* @ref : USART_Role */
#define USART_Role_Tx					1
#define USART_Role_Rx					2
#define USART_Role_Tx_Rx				3

/* @ref : USART_Interrupt */
#define USART_Polling					0
#define USART_Interrupt_Tx				1
#define USART_Interrupt_Rx				2
#define USART_Interrupt_Tx_Rx			3

/*@ref : MODE :*/
#define USART_MODE_ASYNC				0
#define USART_MODE_SYNC					1

/*@ref : Parity :*/
#define USART_Parity_DISABLE			0
#define USART_Parity_EVEN				2
#define USART_Parity_ODD				3

/*@ref : Stop_BIT*/
#define USART_STOP_1BIT					0
#define USART_STOP_2BIT					1

/*@ref: Data_Size*/

#define USART_Data_5BIT					0
#define USART_Data_6BIT					1
#define USART_Data_7BIT					2
#define USART_Data_8BIT					3
#define USART_Data_9BIT					7

/*@ref : CLK_Polarity*/

#define USART_polarity_DISABLE						0
#define USART_Polarity_TX_Rising_RX_Fallinng		0
#define USART_Polarity_TX_Falling_RX_Rising			1


/*@ref : Baud_Rate */

#define USART_BaudRate_2400						2400
#define USART_BaudRate_4800						4800
#define USART_BaudRate_9600						9600
#define USART_BaudRate_14400					14400
#define USART_BaudRate_19200					19200
#define USART_BaudRate_28800					28800
#define USART_BaudRate_38400					38400
#define USART_BaudRate_57600					57600
#define USART_BaudRate_76800					76800
#define USART_BaudRate_115200					115200
#define USART_BaudRate_230400					230400
#define USART_BaudRate_250000					250000
#define USART_BaudRate_500000					500000
#define USART_BaudRate_1M						1000000

/* @ref : Speed */
#define USART_Speed_Normal							1
#define USART_Speed_Double							2

/* Register base address */

#define UDR					(*(vuin8*)(0x2C))

#define UCSRA				(*(vuin8*)(0x2B))

#define MPCM						0
#define U2X							1
#define PE							2
#define DOR							3
#define FE							4
#define UDRE						5
#define TXC							6
#define RXC  						7

#define UCSRB				(*(vuin8*)(0x2A))

#define TXB8							0
#define RXB8							1
#define UCSZ2							2
#define TXEN							3
#define RXEN							4
#define UDRIE							5
#define TXCIE							6
#define RXCIE       					7

#define UCSRC				(*(vuin8*)(0x40))

#define UCPOL					0
#define UCSZ0					1
#define UCSZ1					2
#define USBS					3
#define UPM0					4
#define UPM1					5
#define UMSEL					6
#define URSEL   				7

#define UBRRL				(*(vuin8*)(0x29))

#define UBRRH				(*(vuin8*)(0x40))

#endif /* USART_PRIV_H_ */