/*
 * TIMER2_Priv.h
 * Created: 9/17/2023 11:31:10 AM
 * Author: ENG . Ahmed Osama
 */ 


#ifndef TIMER2_PRIV_H_
#define TIMER2_PRIV_H_

/* Register base address*/

/*TCCR2 – Timer/Counter Control Register*/
#define TCCR2			(*(vuin8*)(0x45))

#define CS20			0
#define CS21			1
#define CS22			2
#define WGM21			3
#define COM20			4
#define COM21			5
#define WGM20			6
#define FOC2			7


/*TCNT0 – Timer/Counter Register*/

#define TCNT2			(*(vuin8*)(0x44))

/* OCR0 – Output Compare Register */

#define OCR2			(*(vuin8*)(0x43))


#define ASSR			(*(vuin8*)(0x42))

/* TIMSK – Timer/Counter Interrupt Mask Register */

#define TIMSK			(*(vuin8*)(0x59))

#define TOIE2				6
#define OCIE2				7


/* TIFR – Timer/Counter Interrupt Flag Register */
      
#define TIFR			(*(vuin8*)(0x58))

#define TOV2				6
#define OCF2				7

/* x*x*x*x*x*x*x */

       
 /* TMR0 Mode Define */

#define TMR2_NORMAL_MODE			1
#define TMR2_CTC_MODE				2
#define TMR2_FastPWM_MODE			3
#define TMR2_PhaseCorrect_PWM_Mode  4

#define TMR2_PWM_NONINVERTING		5
#define TMR2_PWM_INVERTING			6

#endif /* TIMER2_PRIV_H_ */