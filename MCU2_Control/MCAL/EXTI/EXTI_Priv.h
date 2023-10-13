/*
 * EXTI_Priv.h
 * Created: 9/11/2023 11:47:12 AM
 * Author: ENG. Ahmed Osama
 */ 



#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

/* EXTI Register base address */


/*For External Interrupts */


#define  GICR				*((vuin8*) 0x5B)

#define INT0		6
#define INT1		7
#define INT2		5

#define  MCUCR				*((vuin8*) 0x55)


#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3

#define  MCUCSR				*((vuin8*) 0x54)

#define ISC2		6

#define  GIFR				*((vuin8*) 0x5A)



#endif /* EXTI_PRIV_H_ */