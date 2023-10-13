/*
 * TIMER0_Prog.c
 * Created: 9/17/2023 11:31:54 AM
 * Author: ENG . Ahmed Osama
 */ 

/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "TIMER0_Int.h"
#include "TIMER0_Cfg.h"
#include "TIMER0_Priv.h"


/*GLOBAL CALL BACK FUNCTION */

static void (*PrivatePTR)(void) = NULL ;



/* APIs */

void TMR0_voidInit(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
	/* Normal Mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/* Set Preload in TCNT0 */
	TCNT0 = TMR0_PRELOAD_VALUE ; 
	/* Enable OVF Interrupt */
	SET_BIT(TIMSK, TOIE0);
#elif TMR0_MODE == TMR0_CTC_MODE
	/* TMR0_CTC_MODE */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* Enable OC Interrupt */
	SET_BIT(TIMSK, OCIE0);
#elif TMR0_MODE == TMR0_FastPWM_MODE
	/* Fast PWM Mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* Compare Output Mode, Fast PWM Mode(1) */
	#if TMR0_PWM_Action == TMR0_PWM_NONINVERTING
	CLR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#elif TMR0_PWM_Action == TMR0_PWM_INVERTING
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#endif
#elif TMR0_MODE == TMR0_PhaseCorrect_PWM_Mode
	/* PhaseCorrect_PWM_Mode */
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/* Compare Output Mode, Fast PWM Mode(1) */
	#if TMR0_PWM_Action == TMR0_PWM_NONINVERTING
	CLR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#elif TMR0_PWM_Action == TMR0_PWM_INVERTING
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#endif
#endif
}
void TMR0_voidStart(void)
{
	SET_MULTIBIT(TCCR0,THREE_BIT,CS00,0b011);			/* Set Prescaler */
}
void TMR0_voidStop(void)
{
	CLR_MULTIBIT(TCCR0,THREE_BIT,CS00);					/* Clear Prescaler to stop timer */
}
void TMR0_voidSetCallBack(void (*ptr)(void))
{
	if(ptr != NULL)
		PrivatePTR = ptr ;
}

void TMR0_voidCompareMatchValue(uin8 Copy_u8CompareValue)
{
	OCR0 = Copy_u8CompareValue ;
}

void TMR0_voidSetDelay_ms_usingCTC (uin16 Copy_u16Delay_ms)
{
	uin16 counter = 0 ;
	/* under condition tick time 4 us (F_CPU = 16MHz & Timer Prescaler = 64 ) */ 
	OCR0 = 249 ;
	/* Start TMR0 */
	TMR0_voidStart();
	/* Polling on Compare Match Flag */
	while(!(Copy_u16Delay_ms == counter))
	{
		while(!(GET_BIT(TIFR,OCF0)));
		SET_BIT(TIFR,OCF0);
		counter++ ;
	}
	counter = 0 ;
	/* Stop TMR0 */
	TMR0_voidStop();
}



void TMR0_voidSetPWM_DutyC(in16 Pres)
{
	uin8 tmpOCR = 0 ; 
	if(TMR0_PWM_Action == TMR0_PWM_INVERTING) {Pres = 100-Pres ;}
	if(Pres <= 100 && Pres != 0)
	{
#if TMR0_MODE == TMR0_FastPWM_MODE

		tmpOCR = ((((uin16)Pres*256)/100)-1) ;

#elif TMR0_MODE == TMR0_PhaseCorrect_PWM_Mode

		tmpOCR = ((((uin16)Pres*510)/100)/2) ;

#endif
	}
	OCR0 = tmpOCR ;
}
/* ISR TIMER0 */

/* OVERFLOW Interrupt TMR0 */

void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	/* Call Action */
	if(PrivatePTR != NULL)
	{
		PrivatePTR();
	}
}

/* Compare Match TMR0 ISR */

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	/* Call Action */
	if(PrivatePTR != NULL)
	{
		PrivatePTR();
	}
}
