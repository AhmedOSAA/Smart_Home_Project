/*
 * EEPROM_Int.h
 *
 *  Created on: Sep 25, 2023
 *      Author: weza
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

void EXTEEPROM_VoidWriteByte(u16 copy_u8WordAddress, u8 copy_u8Data);
void EXTEEPROM_VoidInit(void);
void EXTEEPROM_VoidReadByte(u16 copy_u16WordAddress, in8 *Buffer_u8Data);
void EXTEEPROM_VoidWritePage(u16 copy_u16WordAddress, in8* copy_u8Data, u8 Size);
void EXTEEPROM_VoidReadPage(u16 copy_u16WordAddress, in8 *Buffer_u8Data ,u8 size);




#endif /* HAL_EEPROM_EEPROM_INT_H_ */
