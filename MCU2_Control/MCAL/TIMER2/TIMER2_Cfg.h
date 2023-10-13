/*
 * TIMER2_Cfg.h
 * Created: 9/17/2023 11:31:37 AM
 * Author: ENG. Ahmed Osama
 */ 


#ifndef TIMER2_CFG_H_
#define TIMER2_CFG_H_

/*  Timer Modes @ref :
					1- TMR2_NORMAL_MODE			
					2- TMR2_CTC_MODE
					3- TMR2_FastPWM_MODE
					4- TMR2_PhaseCorrect_PWM_Mode	
*/
#define TMR2_MODE						TMR2_FastPWM_MODE

/*		1- TMR2_PWM_NONINVERTING
		2- TMR2_PWM_INVERTING			
*/

#define TMR2_PWM_Action					TMR2_PWM_NONINVERTING

#define TMR2_PRELOAD_VALUE				(uin8)(0)

#define TMR2_OVER_FLOW_COUNTER			488



#endif /* TIMER2_CFG_H_ */