#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Cnf.h"

void MCAL_SetPinMode(U8 A_U8PIN, U8 A_U8MODE);
void MCAL_DIOWritePort(U8 A_U8Port,U8 A_U8Value);
void MCAL_DIOReadPort(U8 A_U8Port,U8 *A_U8PtrBuffer);
void MCAL_DIOReadChannel(U8 A_U8Port,U8 *A_U8PtrBuffer);
void MCAL_DIOWriteChannel(U8 A_U8Port,U8 A_U8Value);
void MCAL_DIOVoidChannelMode(U8 A_U8Port,U8 A_U8Direction);
void MCAL_DIOInit(void);
void MCAL_DIOToggelChannel(U8 A_U8Port);
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define DIO_HIGH 1
#define DIO_LOW 0
#define INPUT 0
#define OUTPUT 1
enum PORTS{
 PORTA0 ,
 PORTA1 ,
 PORTA2 ,
 PORTA3 ,
 PORTA4 ,
 PORTA5 ,
 PORTA6 ,
 PORTA7 ,
 PORTB0 ,
 PORTB1 ,
 PORTB2 ,
 PORTB3 ,
 PORTB4 ,
 PORTB5 ,
 PORTB6 ,
 PORTB7 ,
 PORTC0 ,
 PORTC1 ,
 PORTC2 ,
 PORTC3 ,
 PORTC4 ,
 PORTC5 ,
 PORTC6 ,
 PORTC7 ,
 PORTD0 ,
 PORTD1 ,
 PORTD2 ,
 PORTD3 ,
 PORTD4 ,
 PORTD5 ,
 PORTD6 ,
 PORTD7
};

#endif /* MCAL_DIO_DIO_INT_H_ */
