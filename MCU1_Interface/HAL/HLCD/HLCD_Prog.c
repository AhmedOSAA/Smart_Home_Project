/*
 * HLCD_Prog.c
 * Created on: Sep 9, 2023
 * Author: weza
 */
#include "DIO_int.h"
#include "SPI_Int.h"
#include "HLCD_Config.h"
#include "HLCD_Priv.h"
#include "HLCD_Int.h"
#include "util/delay.h"
 void HLCD_U8SendMSB(U8 A_U8Bits){
	 U8 GET_BITS=0;
	 GET_BITS=A_U8Bits>>4;
	 for(U8 COUNTER=0;COUNTER<4;COUNTER++){
		 MCAL_DIOWriteChannel(HLCD_DATA[COUNTER],(GET_BITS>>COUNTER)&1);
		 /* (void)MSPI_VoidTranceive(A_U8Bits);
	 MSPI_VoidTransmitByte(A_U8Bits);
	     MCAL_SetPinMode(PORTA0,OUTPUT_HIGH);
	     _delay_us(1);
		 MCAL_SetPinMode(PORTA0,OUTPUT_LOW);
		 _delay_us(1);*/
	 }
 }
 void HLCD_U8SendLSB(U8 A_U8Bits){
	 for(U8 COUNTER=0;COUNTER<4;COUNTER++){
		MCAL_DIOWriteChannel(HLCD_DATA[COUNTER],(A_U8Bits>>COUNTER)&1);
	 //MSPI_VoidTransmitByte(A_U8Bits);
     //MCAL_SetPinMode(PORTA0,OUTPUT_HIGH);
     //_delay_us(1);
	 //MCAL_SetPinMode(PORTA0,OUTPUT_LOW);
	// _delay_us(1);
	 }
 }

 void LCD_voidInit(void){
	 MCAL_SetPinMode(RS,OUTPUT_LOW);
	 MCAL_SetPinMode(EN,OUTPUT_LOW);
	 MCAL_SetPinMode(DATA4,OUTPUT_LOW);
	 MCAL_SetPinMode(DATA5,OUTPUT_LOW);
	 MCAL_SetPinMode(DATA6,OUTPUT_LOW);
	 MCAL_SetPinMode(DATA7,OUTPUT_LOW);
	 //COMMANDS
	 _delay_ms(35);
	 LCD_voidSendCmnd(0b00000010);
	 LCD_voidSendCmnd(0b00101000);
	 _delay_ms(1);
	 LCD_voidSendCmnd(0b00001100);
	 _delay_ms(1);
	 LCD_voidSendCmnd(0b00000001);
	 _delay_ms(2);
	 LCD_voidSendCmnd(0b00000110);
	 _delay_ms(1);
 }

 void LCD_voidSendChar(u8 copy_u8Data){
	     MCAL_DIOWriteChannel(RS,DIO_HIGH);
		 HLCD_U8SendMSB(copy_u8Data);
		 MCAL_DIOWriteChannel(EN,DIO_HIGH);
		 _delay_us(10);
		 MCAL_DIOWriteChannel(EN,DIO_LOW);
		 HLCD_U8SendLSB(copy_u8Data);
		 MCAL_DIOWriteChannel(EN,DIO_HIGH);
		 _delay_us(10);
		 MCAL_DIOWriteChannel(EN,DIO_LOW); }

 void LCD_voidSendCmnd(u8 copy_u8Cmnd){
	 MCAL_DIOWriteChannel(RS,DIO_LOW);
	 HLCD_U8SendMSB(copy_u8Cmnd);
	 MCAL_DIOWriteChannel(EN,DIO_HIGH);
	 _delay_us(10);
	 MCAL_DIOWriteChannel(EN,DIO_LOW);
	 HLCD_U8SendLSB(copy_u8Cmnd);
	 MCAL_DIOWriteChannel(EN,DIO_HIGH);
	 _delay_us(10);
	 MCAL_DIOWriteChannel(EN,DIO_LOW);
 }

 void LCD_voidClear(void){
	 LCD_voidSendCmnd(CLEAR_DISPLAY);
 }
void LCD_VoidShiftRL(void){
	 LCD_voidSendCmnd(CURSOR_SHIFT);
}
 void LCD_voidWriteString(in8* copy_pu8String) {
 	u8 L_CounterR=0;

 	while(copy_pu8String[L_CounterR]!='\0')
 	{
 		LCD_voidSendChar(copy_pu8String[L_CounterR]);
 		L_CounterR++;
 	}

 }

 void LCD_voidWriteCharArray(u8* copy_pu8String, u8 copy_u8no_ofbytes) {
  	for(int i=0;i<copy_u8no_ofbytes;i++)
  	{
  		LCD_voidSendChar(copy_pu8String[i]);
  	}

  }
 void LCD_voidWriteNumber(u32 copy_u32Number)
 {
 	if(copy_u32Number!=0)
 	{
 		LCD_voidWriteNumber(copy_u32Number/10);
 		LCD_voidSendChar((copy_u32Number%10)+'0');
 	}
 }
 void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position){
		u8 L_u8Address=0;
		switch(copy_u8LineNumber) {
		case 0:
			L_u8Address = copy_u8Position + 0x00;
			LCD_voidSendCmnd(L_u8Address | 0b10000000);
			break;
		case 1:
			L_u8Address = copy_u8Position + 0x40;
			LCD_voidSendCmnd(L_u8Address | 0b10000000);
			break;
		case 2:
			LCD_voidSendCmnd(0x94);
			break;
		case 3:
			LCD_voidSendCmnd(0xD4);
			break;
		}
	 /*u8 L_u8Address=0;
 	switch(copy_u8LineNumber) {
 	case 0:
 		L_u8Address = copy_u8Position + 0x00;
 		break;
 	case 1:
 		L_u8Address = copy_u8Position + 0x40;
 		break;
 	}

 	LCD_voidSendCmnd(L_u8Address | 0b10000000);*/
 }
 void HLCD_vDispCustom(u8 A_u8Index)
 {
 	if(A_u8Index<8)
 	{
 		LCD_voidSendChar(A_u8Index);
 	}
 }

 void HLCD_vSaveCustom(u8 A_u8Index,u8 A_u8Data[])
 {
 	// 1-set CGRAM Address
	 LCD_voidSendCmnd(0x40+A_u8Index*8);
 	// 2-send data
 	for(int i=0;i<=7;i++)
 	{
 		LCD_voidSendChar(A_u8Data[i]);
 	}
 	// 3-set ddram address (return home)
 	LCD_voidSendCmnd(0x80);
 }

