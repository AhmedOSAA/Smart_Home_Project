/*
 * TWI_Int.h
 *
 *  Created on: Sep 24, 2023
 *      Author: weza
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

#define ACK 1
#define NOT_ACK 0
#define I2C_WRITE 0
#define I2C_READ 1


void TWI_VoidNAKC();
void TWI_VoidAKC();
u8 MI2C_u8SendStartCondition(void);
u8 MI2C_u8SendRepeatedStartCondition(void);
u8 MI2C_U8SendSLVRW(u8 A_u8SLVADD, u8 A_u8WriteRead);
u8 MI2C_U8SendData(u8 A_U8Data);
u8 MI2C_U8RecieveByte(u8 A_U8ACK,u8 *A_U8RecievedData);
u8 MI2C_U8SendStopCondition(void);
u8 MI2C_U8GetStatus(void);
void TWI_VoidInitMstr(u8 copy_u8Add);
void TWI_VoidSendSlvAddressWithRead(u8 copy_u8SlvAdd);
void TWI_VoidSendSlvAddressWithWrite(u8 copy_u8SlvAdd);
void TWI_VoidRecieveMasterDataByte(in8 *Buffer_u8RecieveData);
void TWI_VoidSendMasterDataByte(u8 copy_u8Data);
void TWI_VoidSendRepeatedStartCondition(void);
void TWI_VoidSendStopCondition(void);
void TWI_VoidSendStartCondition(void);

u8 i2c_read(u8 ack);
void i2c_stop(void);
void i2c_write(u8 data);
void i2c_init(void);
void i2c_start(void);
#endif /* MCAL_TWI_TWI_INT_H_ */
