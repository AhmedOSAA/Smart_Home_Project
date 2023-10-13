/*
 * EXTI_Int.h
 * Created: 9/11/2023 11:46:31 AM
 * Author: ENG. Ahmed Osama
 */ 

#include "STD_TYPES.h"


#ifndef EXTI_INT_H_
#define EXTI_INT_H_

typedef enum
{
	EXTI_INT0,			// PORT_D PIN_2
	EXTI_INT1,			// PORT_D PIN_3
	EXTI_INT2			// PORT_B PIN_2
}EXTI_source_t;


typedef enum
{
	EXTI_RISING_EDGE  = 0b11,
	EXTI_FALLING_EDGE = 0b10,
	EXTI_LOW_LEVEL = 0b00,	
	EXTI_ANY_LOGICAL_CHANGE = 0b01
}EXTI_Trigger_t;


/*  APIs */
void EXTI_voidEnable(EXTI_source_t INTSource , EXTI_Trigger_t Trigger);
void EXTI_voidDisable(EXTI_source_t INTSource);


#endif /* EXTI_INT_H_ */