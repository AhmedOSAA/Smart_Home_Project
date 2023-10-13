/*•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 •                                                                      •
 •••••••••••••••••••••••••  Date    : 9/13/2023       •••••••••••••••••••
 •••••••••••••••••••••••••  Name    : Ahmed Osama     •••••••••••••••••••
 •••••••••••••••••••••••••  Version : 1.0             •••••••••••••••••••
 •••••••••••••••••••••••••  SWC     : BIT_MATH        •••••••••••••••••••
 •                                                                      •
 •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* COMMON Control in one bit */
#define  SET_BIT(REG,BIT_NUM)			(REG)|=(1<<(BIT_NUM))
#define  CLR_BIT(REG,BIT_NUM)			(REG)&=(~(1<<(BIT_NUM)))
#define  TOG_BIT(REG,BIT_NUM)			(REG)^=(1<<(BIT_NUM))
#define  GET_BIT(REG,BIT_NUM)			((REG)>>BIT_NUM)&0X01

/* ADVANCED Control in MUltiBit  */

#define  SET_MULTIBIT(REG,NUM_BITS,START_BIT_NUM,VAL)			(REG)= ( ( (REG) & ~((NUM_BITS)<<(START_BIT_NUM)) ) | ((VAL)<<(START_BIT_NUM)) )
#define  CLR_MULTIBIT(REG,NUM_BITS,START_BIT_NUM)				(REG)&= ~((NUM_BITS)<<(START_BIT_NUM))
#define  TOG_MULTIBIT(REG,NUM_BITS,START_BIT_NUM)				(REG)^=((NUM_BITS)<<(START_BIT_NUM))
#define  GET_MULTIBIT(REG,NUM_BITS,START_BIT_NUM)				(((REG)>>START_BIT_NUM) & NUM_BITS)

/*@ref : Num Bits */

#define ONE_BIT				0b1
#define TWO_BIT				0b11
#define THREE_BIT			0b111
#define FOUR_BIT			0b1111
#define FIVE_BIT			0b11111

#endif /* BIT_MATH_H_ */