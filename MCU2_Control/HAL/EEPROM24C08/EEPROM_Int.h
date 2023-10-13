/*
 * EEPROM_Int.h
 * Created: 9/25/2023 10:38:05 AM
 * Author: Eng. Ahmed Osamaa
 */ 

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_


/* APIs */

void EEPROM_voidInit(void);
void EEPROM_voidWriteByte(uin16 Copy_u16WordAddress, uin8 Copy_u8TxData);
void EEPROM_voidReadByte(uin16 Copy_u16WordAddress, uin8* Copy_u8RxData);
void EEPROM_voidWritePage(uin16 Copy_u16WordAddress, in8* Copy_u8TxData , uin8 Copy_u8SizePadgeUPTO16);
void EEPROM_voidReadPage(uin16 Copy_u16WordAddress, in8* Copy_u8RxData , uin8 Copy_u8SizePadgeUPTO16);


#endif /* EEPROM_INT_H_ */