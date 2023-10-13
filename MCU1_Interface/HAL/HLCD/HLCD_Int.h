/*
 * HLCD_Int.h
 *
 *  Created on: Sep 9, 2023
 *      Author: weza
 */

#ifndef HAL_HLCD_HLCD_INT_H_
#define HAL_HLCD_HLCD_INT_H_

void LCD_voidInit(void);
void LCD_voidSendCmnd(u8 copy_u8Cmnd);
void LCD_voidSendChar(u8 copy_u8Data);
void LCD_voidWriteString(in8* copy_pu8String);
void LCD_voidWriteNumber(u32 copy_u32Number);
void LCD_voidClear(void);
void LCD_voidShift(u8 copy_u8ShifttingDirection);
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position);
void HLCD_U8SendMSB(U8 A_U8Bits);
void HLCD_U8SendLSB(U8 A_U8Bits);
void HLCD_vDispCustom(u8 A_u8Index);
void HLCD_vSaveCustom(u8 A_u8Index,u8 A_u8Data[]);
void LCD_VoidShiftRL(void);
void LCD_voidWriteCharArray(u8* copy_pu8String, u8 copy_u8no_ofbytes) ;


#endif /* HAL_HLCD_HLCD_INT_H_ */
