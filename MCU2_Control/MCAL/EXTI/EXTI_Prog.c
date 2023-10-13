/*
 * EXTI_Prog.c
 * Created: 9/11/2023 11:48:24 AM
 * Author: ENG. Ahmed Osama
 */ 

/* Includes */

#include "EXTI_Int.h"
#include "EXTI_Priv.h"

/*  APIs */
void EXTI_voidEnable(EXTI_source_t INTSource , EXTI_Trigger_t Trigger)
{
	switch(INTSource)
	{
		case EXTI_INT0:
			MCUCR &= ~(0b11<<ISC00) ;
			MCUCR |= (Trigger<<ISC00) ;
			
			GICR  |= 1<<INT0 ;
		break;
		
		case EXTI_INT1:
			MCUCR &= ~(0b11<<ISC10) ;
			MCUCR |= (Trigger<<ISC10) ;
			
			
			GICR  |= 1<<INT1 ;
		break;		
		
		case EXTI_INT2:
			MCUCR &= ~(0b01<<ISC2) ;
			MCUCR |= ((Trigger&0b01)<<ISC2) ;
			
			
			GICR  |= 1<<INT2 ;
		break;
	}
}

void EXTI_voidDisable(EXTI_source_t INTSource)
{
	
		switch(INTSource)
		{
			case EXTI_INT0:
			GICR  &= ~(1<<INT0) ;
			break;
			
			case EXTI_INT1:
			GICR  &= ~(1<<INT1) ;
			break;
			
			case EXTI_INT2:
			GICR  &= ~(1<<INT2) ;
			break;
		}
}