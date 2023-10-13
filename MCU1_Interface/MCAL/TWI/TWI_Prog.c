/*
 * TWI_Prog.c
 *
 *  Created on: Sep 24, 2023
 *      Author: weza
 */
//#define F_CPU 16000000
//#include"util/delay.h"
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"TWI_Priv.h"
#include"TWI_Int.h"
#include"DIO_int.h"
//MOHTMYYN bl master 3shan ataba2ha m3 el eeprom w khalas
//fel init slv lazm adelo adress ka argument, lw mstr msh lazm (OPTIONAL)
void i2c_start(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}
void i2c_init(void){
	TWSR=0;
	TWBR=0X48;
	TWCR=0X04;
}
void i2c_write(u8 data){
		TWDR=data;
		TWCR = (1<<TWINT)|(1<<TWEN);
		while (!(TWCR & (1<<TWINT)));
}
u8 i2c_read(u8 ack){
	TWCR = (1<<TWINT)|(ack<<TWEA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}
void i2c_stop(void){
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	for(int i=0;i<100;i++);
}
void TWI_VoidInitMstr(u8 copy_u8Add){
	if(copy_u8Add<128){
		TWAR=copy_u8Add<<1;
	}
	TWBR=12;
	CLR_BIT(TWSR,TWPS0); //CLK=400KHZ
	CLR_BIT(TWSR,TWPS1);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
}
void TWI_VoidSendSlvAddressWithWrite(u8 copy_u8SlvAdd){
	//U8 ReturnErrorState=PASS; // ERROR VALIDATION UNIT TESTING EL MFROD A3MLHA RETURN BAS FAKS
	if(copy_u8SlvAdd<128){
		TWDR=copy_u8SlvAdd<<1; //3YZA ATALA3 EL SLV ADDRESS 3LA EL SDA , LAKN ANA LW SLAVE LAZM A7OT FEL TWAR EL SLV ADDRESS 3SHAN A2OLO EN HOWA DAH EL SLV ADRESS BTA3 EL DEVICE DAH
	    CLR_BIT(TWDR,0) ; //WRITE OPERATION
	    CLR_BIT(TWCR,TWSTA);
	    SET_BIT(TWCR,TWINT);
		while (!(TWCR & (1<<TWINT)));
		while(TWI_STATUS_VALUE!=TWI_SEND_SLV_ADD_WRITE_ACK);

	}
	else{/*ReturnErrorState=FAIL;*/}

}

void TWI_VoidSendSlvAddressWithRead(u8 copy_u8SlvAdd){
	// U8 ReturnErrorState=PASS; // ERROR VALIDATION UNIT TESTING EL MFROD A3MLHA RETURN BAS FAKS
	if(copy_u8SlvAdd<128){
		TWDR=copy_u8SlvAdd<<1; //3YZA ATALA3 EL SLV ADDRESS 3LA EL SDA , LAKN ANA LW SLAVE LAZM A7OT FEL TWAR EL SLV ADDRESS 3SHAN A2OLO EN HOWA DAH EL SLV ADRESS BTA3 EL DEVICE DAH
	    SET_BIT(TWDR,0) ; //READ OPERATION
	    CLR_BIT(TWCR,TWSTA);
	    SET_BIT(TWCR,TWINT);
		while (!(TWCR & (1<<TWINT)));
		while(TWI_STATUS_VALUE!=TWI_SEND_SLV_ADD_READ_ACK);

	}
	else{/*ReturnErrorState=FAIL;*/}
}

void TWI_VoidSendStartCondition(void){
	TWCR |= (1<<TWSTA); //hla2y f kol function b clear el flag (TWINT) awl haga
	TWCR |= (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	while(TWI_STATUS_VALUE!=TWI_START_CONDITION_ACK);
}
void TWI_VoidSendRepeatedStartCondition(void){
    //hla2y f kol function b clear el flag (TWINT) awl haga
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	while (!(TWCR & (1<<TWINT)));
	while(TWI_STATUS_VALUE!=TWI_REPEATED_START_CONDITION_ACK);
}
void TWI_VoidSendStopCondition(void){
SET_BIT(TWCR,TWSTO);
SET_BIT(TWCR,TWINT);
_delay_ms(1);
}

void TWI_VoidSendMasterDataByte(u8 copy_u8Data){
	TWDR=copy_u8Data;
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
	while(TWI_STATUS_VALUE!=MSTR_SEND_DATA_ACK);
	//MCAL_SetPinMode(PORTA0,OUTPUT_HIGH);
}

void TWI_VoidRecieveMasterDataByte(in8 *Buffer_u8RecieveData){
	if(Buffer_u8RecieveData!= (void*)0)
	{ //to prevent wild pointer error
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
	//while(TWI_STATUS_VALUE!=MSTR_RECIEVE_DATA_ACK || TWI_STATUS_VALUE!=MSTR_RECIEVE_DATA_NACK);
	*Buffer_u8RecieveData=TWDR;
	}
}

void TWI_VoidAKC()
{
	SET_BIT(TWCR,TWEA);
}

void TWI_VoidNAKC()
{
	CLR_BIT(TWCR,TWEA);
}

/*
u8 MI2C_u8SendStartCondition(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); //hla2y f kol function b clear el flag (TWINT) awl haga
	while (!(TWCR & (1<<TWINT)));
	TWBR=10; // fe nti hatenha b 12, BT3TMD 3LA EL PRESCALLAR VALUES 3n tre2 eqn
	return (TWSR & 0xF8);
}
u8 MI2C_u8SendRepeatedStartCondition(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
		while (!(TWCR & (1<<TWINT)));
		TWBR=10;
		return (TWSR & 0xF8); //MSB 5BITS
}
u8 MI2C_U8SendSLVRW(u8 A_u8SLVADD, u8 A_u8WriteRead){
	TWDR = (A_u8SLVADD<<1)|(A_u8WriteRead);
	TWCR = (1<<TWINT) | (1<<TWEN);
	CLR_BIT(TWCR,TWINT);
	while (!(TWCR & (1<<TWINT)));
	return (TWSR & 0xF8) ;
}
u8 MI2C_U8SendData(u8 A_U8Data){
	TWDR = A_U8Data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	CLR_BIT(TWCR,TWINT);
	while (!(TWCR & (1<<TWINT)));
	return (TWSR & 0xF8) ;
}
u8 MI2C_U8RecieveByte(u8 A_U8ACK,u8 *A_U8RecievedData){
	switch(A_U8ACK){
	case NOT_ACK:TWCR = (1<<TWINT) | (1<<TWEN); CLR_BIT(TWCR,TWEA); break;
	case ACK: TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); break;
	}
	while (!(TWCR & (1<<TWINT)));
	*A_U8RecievedData=TWDR;
	return (TWSR & 0xF8) ;
}
u8 MI2C_u8SendAck(u8 A_U8ACK){
	switch(A_U8ACK){
		case NOT_ACK:TWCR = (1<<TWINT) | (1<<TWEN); CLR_BIT(TWCR,TWEA); break;
		case ACK: TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); break;
		}
	return (TWSR & 0xF8) ;
}
u8 MI2C_U8SendStopCondition(void){
TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
return (TWSR & 0xF8) ;
}
*/
/*init mstr
 * presc
 mstr/slv
 enable i2c

 */
