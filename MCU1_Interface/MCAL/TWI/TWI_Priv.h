/*
 * TWI_Priv.h
 *
 *  Created on: Sep 24, 2023
 *      Author: weza
 */

#ifndef MCAL_TWI_TWI_PRIV_H_
#define MCAL_TWI_TWI_PRIV_H_


#define TWBR (*(volatile u8*)(0X20))
#define TWCR (*(volatile u8*)(0X56))
#define TWSR (*(volatile u8*)(0X21))
#define TWDR (*(volatile u8*)(0X23))
#define TWAR (*(volatile u8*)(0X22))

#define MSTR_RECIEVE_DATA_NACK           0x58
#define MSTR_RECIEVE_DATA_ACK            0x50
#define MSTR_SEND_DATA_ACK               0X28
#define TWI_START_CONDITION_ACK          0x08
#define TWI_REPEATED_START_CONDITION_ACK 0x10
#define TWI_SEND_SLV_ADD_WRITE_ACK       0x18
#define TWI_SEND_SLV_ADD_READ_ACK        0x40
#define TWI_STATUS_VALUE                 (TWSR&0XF8)
#define PASS 1
#define FAIL 0
enum TWBR_REG{
	TWIE,
	TWEN=2,
	TWWC,
	TWSTO,
	TWSTA,
	TWEA,
	TWINT
};
enum TWSR_REG{
	TWPS0,
	TWPS1
};
enum TWAR_REG{
	TWGCE
};
enum PRESCALLAR{
PRESC1,
PRESC4,
PRESC16,
PRESC64
};




#endif /* MCAL_TWI_TWI_PRIV_H_ */
