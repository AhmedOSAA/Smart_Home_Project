/*
 * EEPROM_Prog.c
 * Created: 9/25/2023 10:38:48 AM
 * Author: Eng. Ahmed Osamaa
 */ 

/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"

/* MCAL */
#include "I2C_Int.h"

/* HAL */
#include "EEPROM_Priv.h"
#include "EEPROM_Int.h"


/*APIs*/


void EEPROM_voidInit(void)
{
	/* Init I2C as a Master */
	I2C_voidInitMaster(0xFF);
}
void EEPROM_voidWriteByte(uin16 Copy_u16WordAddress, uin8 Copy_u8TxData)
{
	uin8 Address = 0 ;
	Address = ( ( Copy_u16WordAddress>>8 ) | 0x50 );  // Address EEPROM : 1010 AAA r/w we send 0b01010AAA 
														// then I2C send address function which handling r/w bit 
	/* Send start condition */
	I2C_voidSendStartCondition();
	/* Send Address of EEPROM Device */
	I2C_voidSendSlaveAddressWithWrite(Address);
	/* Send Byte Address to write on it*/
	I2C_voidSendMasterDataByte((uin8)Copy_u16WordAddress);
	/* Send Byte Data to be written */
	I2C_voidSendMasterDataByte(Copy_u8TxData);
	/* Send stop condition */
	I2C_voidSendStopCondition();
	/* Self time delay*/
	_delay_ms(5);

}

void EEPROM_voidReadByte(uin16 Copy_u16WordAddress, uin8* Copy_u8RxData)
{
	if(Copy_u8RxData)
	{
		uin8 Address = 0 ;
		Address = ( ( Copy_u16WordAddress>>8 ) | 0x50 );  // Address EEPROM : 1010 AAA r/w we send 0b01010AAA
		// then I2C send address function which handling r/w bit
		/* Send start condition */
		I2C_voidSendStartCondition();
		/* Send Address of EEPROM Device with Write condition*/
		I2C_voidSendSlaveAddressWithWrite(Address);
		/* Send Byte Address to write on it*/
		I2C_voidSendMasterDataByte((uin8)Copy_u16WordAddress);
		/* Send Rep. start condition */
		I2C_voidSendRepStartCondition();
		/* Send Address of EEPROM Device with Read condition */
		I2C_voidSendSlaveAddressWithRead(Address);
		/* Receive Byte Data form EEPROM */
		I2C_voidReceiveMasterDataByte(Copy_u8RxData);
		/* Send stop condition */
		I2C_voidSendStopCondition();
		/* Self time delay*/
		_delay_ms(5);
	}
}

void EEPROM_voidWritePage(uin16 Copy_u16WordAddress, in8* Copy_u8TxData , uin8 Copy_u8SizePadgeUPTO16)
{
	uin8 Address = 0 , i , size = 0 ;
	Address = ( ( Copy_u16WordAddress>>8 ) | 0x50 );  // Address EEPROM : 1010 AAA r/w we send 0b01010AAA
	// then I2C send address function which handling r/w bit
	/* Send start condition */
	I2C_voidSendStartCondition();
	/* Send Address of EEPROM Device */
	I2C_voidSendSlaveAddressWithWrite(Address);
	/* Send Byte Address to write on it*/
	I2C_voidSendMasterDataByte((uin8)Copy_u16WordAddress);
	/* Send Byte Data to be written */
	size = Copy_u8SizePadgeUPTO16 >= 16 ? 16 : Copy_u8SizePadgeUPTO16 ;
	for(i=0 ; i<size ; i++ )
	{
		I2C_voidSendMasterDataByte(*Copy_u8TxData);
		Copy_u8TxData++;
	}
	/* Send stop condition */
	I2C_voidSendStopCondition();
	/* Self time delay*/
	_delay_ms(5);
}

void EEPROM_voidReadPage(uin16 Copy_u16WordAddress, in8* Copy_u8RxData , uin8 Copy_u8SizePadgeUPTO16)
{
	if(Copy_u8RxData)
	{
		uin8 Address = 0 , i , size = 0;
		Address = ( ( Copy_u16WordAddress>>8 ) | 0x50 );  // Address EEPROM : 1010 AAA r/w we send 0b01010AAA
		// then I2C send address function which handling r/w bit
		/* Send start condition */
		I2C_voidSendStartCondition();
		/* Send Address of EEPROM Device with Write condition*/
		I2C_voidSendSlaveAddressWithWrite(Address);
		/* Send Byte Address to write on it*/
		I2C_voidSendMasterDataByte((uin8)Copy_u16WordAddress);
		/* Send Rep. start condition */
		I2C_voidSendRepStartCondition();
		/* Send Address of EEPROM Device with Read condition */
		I2C_voidSendSlaveAddressWithRead(Address);
		/* Receive Byte Data form EEPROM */
		size = Copy_u8SizePadgeUPTO16 >= 16 ? 16 : Copy_u8SizePadgeUPTO16 ;
		for(i=0 ; i<size ; i++ )
		{
			I2C_voidReceiveMasterDataByte(Copy_u8RxData);
			Copy_u8RxData++;
		}
		/* Send stop condition */
		I2C_voidSendStopCondition();
		/* Self time delay*/
		_delay_ms(5);
	}
}