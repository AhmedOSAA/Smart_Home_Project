#ifndef _BIT_MATH_H
#define _BIT_MATH_H

/**/
/* Eng. Ahmed Osamaa */

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
/******/
/**/

/*
 * WRT_BIT is to assign 1 or 0 to  a specific bit in a register
 * while maintaining all the bits' value as it is.
 * Steps:
 * 		1- Clear the specific bit you want to write on
 * 		2- Insert the new value you want to write
 */
#define WRT_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )

/*
 * SET_BIT is used to assign 1 to a specific bit in a register
 * while maintaining all other bits' value as it is.
 */
#define SET_BIT(REG, BIT)  ( (REG) |=  (1<<(BIT)) )

/*
 * CLR_BIT is used to assign 0 to a specific bit in a register
 * while maintaining all other bits' value as it is.
 */
#define CLR_BIT(REG, BIT)  ( (REG) &= (~(1<<(BIT))) )

/*
 * TOG_BIT is used to flip a specific bit in a register from 0 to 1 or from 1 to 0
 * while maintaining all other bits' value as it is.
 */
#define TOG_BIT(REG, BIT)  ( (REG) ^=  (1<<(BIT)) )

/*
 * GET_BIT is used to read the value of a specific bit in a register
 * while maintaining all the bits' value as it is.
 */
#define GET_BIT(REG, BIT)  ( ( (REG) >> (BIT) ) & 1 )

#define WRT_PORT(PORT,VALUE) PORT=VALUE
#define GET_PORT(PORT)       PORT
#endif /* _BIT_MATH_H */
