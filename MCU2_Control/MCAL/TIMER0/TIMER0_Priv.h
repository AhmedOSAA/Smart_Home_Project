/*
 * TIMER0_Priv.h
 * Created: 9/17/2023 11:31:10 AM
 * Author: ENG . Ahmed Osama
 */ 


#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

/* Register base address*/

/*TCCR0 – Timer/Counter Control Register*/
#define TCCR0			(*(vuin8*)(0x53))

#define CS00			0
#define CS01			1
#define CS02			2
#define WGM01			3
#define COM00			4
#define COM01			5
#define WGM00			6
#define FOC0			7


/*TCNT0 – Timer/Counter Register*/

#define TCNT0			(*(vuin8*)(0x52))

/* OCR0 – Output Compare Register */

#define OCR0			(*(vuin8*)(0x5C))

/* TIMSK – Timer/Counter Interrupt Mask Register */

#define TIMSK			(*(vuin8*)(0x59))

#define TOIE0				0
#define OCIE0				1


/* TIFR – Timer/Counter Interrupt Flag Register */
      
#define TIFR			(*(vuin8*)(0x58))

#define TOV0				0
#define OCF0				1

/* x*x*x*x*x*x*x */

       
 /* TMR0 Mode Define */

#define TMR0_NORMAL_MODE			1
#define TMR0_CTC_MODE				2
#define TMR0_FastPWM_MODE			3
#define TMR0_PhaseCorrect_PWM_Mode  4

#define TMR0_PWM_NONINVERTING		5
#define TMR0_PWM_INVERTING			6

#endif /* TIMER0_PRIV_H_ */