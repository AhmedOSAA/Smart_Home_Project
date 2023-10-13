/*
 * EEPROM_Prg.c
 *
 *  Created on: Sep 25, 2023
 *      Author: weza
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TWI_Int.h"
#include"DIO_int.h"
#include"EEPROM_Priv.h"
#include"EEPROM_Int.h"

#include "HLCD_Int.h"

#include"util/delay.h"
//write sequence, generic with all the EEPROM sizes

void EXTEEPROM_VoidWriteByte(u16 copy_u16WordAddress, u8 copy_u8Data){

	//bit 7 in 01010000 don't care l2n el i2c kieda kieda hy3mlha shift w kemytha htruh
	u8 Local_Address=(copy_u16WordAddress>>8)|(EEPROM_FIXED_SLV_ADD);

	TWI_VoidSendStartCondition();

	TWI_VoidSendSlvAddressWithWrite(Local_Address);

	TWI_VoidSendMasterDataByte((u8)copy_u16WordAddress); //Estakhdmt el send data msh slv addres l2n frame el twi de blnsbalo data

	TWI_VoidSendMasterDataByte(copy_u8Data);

	TWI_VoidSendStopCondition();

	_delay_ms(5);
}

void EXTEEPROM_VoidWritePage(u16 copy_u16WordAddress, in8* copy_u8Data, u8 Size){

	//bit 7 in 01010000 don't care l2n el i2c kieda kieda hy3mlha shift w kemytha htruh
	u8 Local_Address=(copy_u16WordAddress>>8)|(EEPROM_FIXED_SLV_ADD);

	u8 counter=0;

	//Size=sizeof(copy_u8Data)/sizeof(copy_u8Data[0]);

	TWI_VoidSendStartCondition();

	TWI_VoidSendSlvAddressWithWrite(Local_Address);

	TWI_VoidSendMasterDataByte((u8)copy_u16WordAddress); //Estakhdmt el send data msh slv addres l2n frame el twi de blnsbalo data

	for(counter=0;counter<Size;counter++)
	{
		TWI_VoidSendMasterDataByte(*copy_u8Data);
		copy_u8Data++;
	}
	TWI_VoidSendStopCondition();
	_delay_ms(5);
}


void EXTEEPROM_VoidReadByte(u16 copy_u16WordAddress, in8 *Buffer_u8Data){

	//bit 7 in 01010000 don't care l2n el i2c kieda kieda hy3mlha shift w kemytha htruh
	u8 Local_Address=(copy_u16WordAddress>>8)|(EEPROM_FIXED_SLV_ADD);

	TWI_VoidSendStartCondition();

	TWI_VoidSendSlvAddressWithWrite(Local_Address);

	TWI_VoidSendMasterDataByte((u8)copy_u16WordAddress);

	TWI_VoidSendRepeatedStartCondition();

	TWI_VoidSendSlvAddressWithRead(Local_Address);

	TWI_VoidRecieveMasterDataByte(Buffer_u8Data);

	TWI_VoidSendStopCondition();
	_delay_ms(5);
}


void EXTEEPROM_VoidReadPage(u16 copy_u16WordAddress, in8 *Buffer_u8Data ,u8 size){

	//bit 7 in 01010000 don't care l2n el i2c kieda kieda hy3mlha shift w kemytha htruh
	u8 Local_Address=(copy_u16WordAddress>>8)|(EEPROM_FIXED_SLV_ADD);

	u8 counter=0;

	TWI_VoidSendStartCondition();

	TWI_VoidSendSlvAddressWithWrite(Local_Address);

	TWI_VoidSendMasterDataByte((u8)copy_u16WordAddress);

	TWI_VoidSendRepeatedStartCondition();

	TWI_VoidSendSlvAddressWithRead(Local_Address);

	for(counter=0;counter<size;counter++){
		if(counter == (size-1)) // Very Important to send Not ACK at last Byte for EEPROM
			{TWI_VoidNAKC();}
		TWI_VoidRecieveMasterDataByte(Buffer_u8Data);
		Buffer_u8Data++ ;
	}
	_delay_ms(10);

	TWI_VoidSendStopCondition();
	_delay_ms(5);
	// Enable ACK Again for any Next Operation
	TWI_VoidAKC();
}
void EXTEEPROM_VoidInit(void){
	TWI_VoidInitMstr(255);
}
