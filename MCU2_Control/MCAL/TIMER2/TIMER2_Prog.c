/*
 * TIMER2_Prog.c
 * Created: 9/17/2023 11:31:54 AM
 * Author: ENG . Ahmed Osama
 */ 

/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "TIMER2_Int.h"
#include "TIMER2_Cfg.h"
#include "TIMER2_Priv.h"


/*GLOBAL CALL BACK FUNCTION */

static void (*PrivatePTR)(void) = NULL ;



/* APIs */

void TMR2_voidInit(void)
{
#if TMR2_MODE == TMR2_NORMAL_MODE
	/* Normal Mode */
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	/* Set Preload in TCNT2 */
	TCNT2 = TMR2_PRELOAD_VALUE ; 
	/* Enable OVF Interrupt */
	SET_BIT(TIMSK, TOIE2);
#elif TMR2_MODE == TMR2_CTC_MODE
	/* TMR2_CTC_MODE */
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/* Enable OC Interrupt */
	SET_BIT(TIMSK, OCIE2);
#elif TMR2_MODE == TMR2_FastPWM_MODE
	/* Fast PWM Mode */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/* Compare Output Mode, Fast PWM Mode(1) */
	#if TMR2_PWM_Action == TMR2_PWM_NONINVERTING
	CLR_BIT(TCCR2 , COM20);
	SET_BIT(TCCR2 , COM21);
	#elif TMR2_PWM_Action == TMR2_PWM_INVERTING
	SET_BIT(TCCR2 , COM20);
	SET_BIT(TCCR2 , COM21);
	#endif
#elif TMR2_MODE == TMR2_PhaseCorrect_PWM_Mode
	/* PhaseCorrect_PWM_Mode */
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	/* Compare Output Mode, Fast PWM Mode(1) */
	#if TMR2_PWM_Action == TMR2_PWM_NONINVERTING
	CLR_BIT(TCCR2 , COM20);
	SET_BIT(TCCR2 , COM21);
	#elif TMR2_PWM_Action == TMR2_PWM_INVERTING
	SET_BIT(TCCR2 , COM20);
	SET_BIT(TCCR2 , COM21);
	#endif
#endif
}
void TMR2_voidStart(void)
{
	SET_MULTIBIT(TCCR2,THREE_BIT,CS20,0b011);			/* Set Prescaler */
}
void TMR2_voidStop(void)
{
	CLR_MULTIBIT(TCCR2,THREE_BIT,CS20);					/* Clear Prescaler to stop timer */
}
void TMR2_voidSetCallBack(void (*ptr)(void))
{
	if(ptr != NULL)
		PrivatePTR = ptr ;
}

void TMR2_voidCompareMatchValue(uin8 Copy_u8CompareValue)
{
	OCR2 = Copy_u8CompareValue ;
}

void TMR2_voidSetDelay_ms_usingCTC (uin16 Copy_u16Delay_ms)
{
	uin16 counter = 0 ;
	/* under condition tick time 4 us (F_CPU = 16MHz & Timer Prescaler = 64 ) */ 
	OCR2 = 249 ;
	/* Start TMR2 */
	TMR2_voidStart();
	/* Polling on Compare Match Flag */
	while(!(Copy_u16Delay_ms == counter))
	{
		while(!(GET_BIT(TIFR,OCF2)));
		SET_BIT(TIFR,OCF2);
		counter++ ;
	}
	counter = 0 ;
	/* Stop TMR2 */
	TMR2_voidStop();
}



void TMR2_voidSetPWM_DutyC(uin16 Pres)
{
	uin8 tmpOCR = 0 ; 
	if(TMR2_PWM_Action == TMR2_PWM_INVERTING) {Pres = 100-Pres ;}
	if(Pres <= 100 && Pres != 0)
	{
#if TMR2_MODE == TMR2_FastPWM_MODE

		tmpOCR = ((((uin16)Pres*256)/100)-1) ;

#elif TMR2_MODE == TMR2_PhaseCorrect_PWM_Mode

		tmpOCR = ((((uin16)Pres*510)/100)/2) ;

#endif
	}
	OCR2 = tmpOCR ;
}
/* ISR TIMER2 */

/* Compare Match TMR2 ISR */

void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	/* Call Action */
	if(PrivatePTR != NULL)
	{
		PrivatePTR();
	}
}

/* OVF TMR2 ISR */

void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	/* Call Action */
	if(PrivatePTR != NULL)
	{
		PrivatePTR();
	}
}
