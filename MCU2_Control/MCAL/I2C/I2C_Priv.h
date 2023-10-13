/*
 * I2C_Priv.h
 * Created: 9/24/2023 1:47:55 PM
 * Author: Eng. Ahmed Osamaa
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_




/**/

#define I2C_STATUS_VALUE					(TWSR & 0xF8)

#define I2C_START_CONDITION_ACK					(0X08)
#define I2C_RepSTART_CONDITION_ACK				(0X10)
#define I2C_SLAVE_ADDRESS_WRITE_ACK				(0X18)
#define I2C_SLAVE_ADDRESS_READ_ACK				(0X40)
#define I2C_MASTER_DATA_TRANSMIT_ACK			(0X28)
#define I2C_MASTER_DATA_RECEIVE_ACK				(0x50)


/* Registers Base Address */

#define TWBR			(*(vuin8*)(0x20))

#define TWCR			(*(vuin8*)(0x56))

#define	TWIE	0
#define	TWEN	2
#define	TWWC	3
#define	TWSTO	4
#define	TWSTA	5
#define	TWEA	6
#define	TWINT	7

#define TWSR			(*(vuin8*)(0x21))

#define TWPS0	0
#define TWPS1	1
#define TWS3	3
	
#define TWDR			(*(vuin8*)(0x23))	
#define TWAR			(*(vuin8*)(0x22))


#endif /* I2C_PRIV_H_ */