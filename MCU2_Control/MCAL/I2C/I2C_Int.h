/*
 * I2C_Int.h
 * Created: 9/24/2023 1:48:09 PM
 * Author: Eng. Ahmed Osamaa
 */ 


#ifndef I2C_INT_H_
#define I2C_INT_H_


/* APIs */

/* Master APIs */
void I2C_voidInitMaster(uin8 Copy_u8Add);

void I2C_voidSendStartCondition(void);
void I2C_voidSendRepStartCondition(void);
void I2C_voidSendStopCondition(void);

void I2C_voidSendSlaveAddressWithWrite(uin8 Copy_u8SlaveAdd);
void I2C_voidSendSlaveAddressWithRead(uin8 Copy_u8SlaveAdd);

void I2C_voidSendMasterDataByte(uin8 Copy_u8TxData);
void I2C_voidReceiveMasterDataByte(in8* Copy_u8RxData);







#endif /* I2C_INT_H_ */