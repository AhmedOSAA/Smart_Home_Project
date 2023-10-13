/*
 * TIMER0_Cfg.h
 *
 * Created: 9/17/2023 11:31:37 AM
 * Author: ENG. Ahmed Osama
 */ 


#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

/*  Timer Modes @ref :
					1- TMR0_NORMAL_MODE			
					2- TMR0_CTC_MODE
					3- TMR0_FastPWM_MODE
					4- TMR0_PhaseCorrect_PWM_Mode	
*/
#define TMR0_MODE						TMR0_FastPWM_MODE

/*		1- TMR0_PWM_NONINVERTING
		2- TMR0_PWM_INVERTING			
*/

#define TMR0_PWM_Action					TMR0_PWM_INVERTING

#define TMR0_PRELOAD_VALUE				(uin8)(0)

#define TMR0_OVER_FLOW_COUNTER			488



#endif /* TIMER0_CFG_H_ */