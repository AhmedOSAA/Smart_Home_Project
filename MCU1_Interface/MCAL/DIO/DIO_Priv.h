/*
 * DIO_Priv.h
 *
 *  Created on: Sep 8, 2023
 *      Author: weza
 */

#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_

#define MCAL_PORTA (*(volatile U8*)(0x3B))
#define MCAL_PORTB (*(volatile U8*)(0x38))
#define MCAL_PORTC (*(volatile U8*)(0x35))
#define MCAL_PORTD (*(volatile U8*)(0x32))
#define MCAL_PINA  (*(volatile U8*)(0x39))
#define MCAL_PINB  (*(volatile U8*)(0x36))
#define MCAL_PINC  (*(volatile U8*)(0x33))
#define MCAL_PIND  (*(volatile U8*)(0x30))
#define MCAL_DDRA  (*(volatile U8*)(0x3A))
#define MCAL_DDRB  (*(volatile U8*)(0x37))
#define MCAL_DDRC  (*(volatile U8*)(0x34))
#define MCAL_DDRD  (*(volatile U8*)(0x31))
#define MCAL_SFIOR (*(volatile U8*)(0x50))



#endif /* MCAL_DIO_DIO_PRIV_H_ */
