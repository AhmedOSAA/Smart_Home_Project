/*
 * I2C_Prog.c
 * Created: 9/24/2023 1:49:30 PM
 * Author: Eng. Ahmed Osamaa
 */ 

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"

/* MCAL */
#include "I2C_Priv.h"
#include "I2C_Int.h"





/* APIs */


/* Master APIs */
void I2C_voidInitMaster(uin8 Copy_u8Add)
{
	/* Set Address for Master if act as Slave */
	if(Copy_u8Add<128)
	{
		TWAR = Copy_u8Add<<1 ;
	}
	/* Set SCLK by 400kHz */
	TWBR = 12 ;
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);	
	/* Enable ACK */
	SET_BIT(TWCR , TWEA);
	/* Enable I2C Peripheral */
	SET_BIT(TWCR , TWEN);
}

void I2C_voidSendStartCondition(void)
{
	/* Request Start Condition */
	SET_BIT(TWCR,TWSTA);
	/* Clear Flag to start Job */
	SET_BIT(TWCR,TWINT);
	/* wait for the flag set to be sent */
	while(!(GET_BIT(TWCR, TWINT)));
	/* Check on status code (ACK)*/
	while(I2C_STATUS_VALUE != I2C_START_CONDITION_ACK);
}
void I2C_voidSendRepStartCondition(void)
{
	/* Request Repeated Start Condition */
	SET_BIT(TWCR,TWSTA);
	/* Clear Flag to start Job */
	SET_BIT(TWCR,TWINT);
	/* wait for the flag set to be sent */
	while(!(GET_BIT(TWCR, TWINT)));
	/* Check on status code (ACK)*/
	while(I2C_STATUS_VALUE != I2C_RepSTART_CONDITION_ACK);
}
void I2C_voidSendStopCondition(void)
{
	/* Request Repeated Start Condition */
	SET_BIT(TWCR,TWSTO);
	/* Clear Flag to start Job */
	SET_BIT(TWCR,TWINT);
}

void I2C_voidSendSlaveAddressWithWrite(uin8 Copy_u8SlaveAdd)
{
	/* Check the Add is existing */
	if(Copy_u8SlaveAdd<128)
	{
		TWDR = Copy_u8SlaveAdd<<1 ;
		// Select write operation
		CLR_BIT(TWDR , 0);
		// Clear Start bit
		CLR_BIT(TWCR,TWSTA);
		
		/* Clear Flag to start Job */
		SET_BIT(TWCR,TWINT);
		/* wait for the flag set to be sent */
		while(!(GET_BIT(TWCR, TWINT)));
		/* Check on status code (ACK)*/
		while(I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_WRITE_ACK);
	}else
	{
		/* Do Nothing */
	}	
	
	
}
void I2C_voidSendSlaveAddressWithRead(uin8 Copy_u8SlaveAdd)
{
	/* Check the Add is existing */
	if(Copy_u8SlaveAdd<128)
	{
		// Select Slave Address
		TWDR = Copy_u8SlaveAdd<<1 ;
		// Select Read operation
		SET_BIT(TWDR , 0);
		// Clear Start bit
		CLR_BIT(TWCR,TWSTA);
		
		/* Clear Flag to start Job */
		SET_BIT(TWCR,TWINT);
		/* wait for the flag set to be sent */
		while(!(GET_BIT(TWCR, TWINT)));
		/* Check on status code (ACK)*/
		while(I2C_STATUS_VALUE != I2C_SLAVE_ADDRESS_READ_ACK);
	}else
	{
		/* Do Nothing */
	}
}

void I2C_voidSendMasterDataByte(uin8 Copy_u8TxData)
{
	// Write data into data register
	TWDR = Copy_u8TxData ;
	/* Clear Flag to start Job */
	SET_BIT(TWCR,TWINT);
	/* wait for the flag set to be sent */
	while(!(GET_BIT(TWCR, TWINT)));
	/* Check on status code (ACK)*/
	while(I2C_STATUS_VALUE != I2C_MASTER_DATA_TRANSMIT_ACK);
}
void I2C_voidReceiveMasterDataByte(in8* Copy_u8RxData)
{
	if(Copy_u8RxData)
	{
		/* Clear Flag to start Job */
		SET_BIT(TWCR,TWINT);
		/* wait for the flag set to be sent */
		while(!(GET_BIT(TWCR, TWINT)));
		/* Check on status code (ACK)*/
		while(I2C_STATUS_VALUE != I2C_MASTER_DATA_RECEIVE_ACK);
		/* Read data from TWDR Register */
		*Copy_u8RxData = TWDR ;
	}
}





