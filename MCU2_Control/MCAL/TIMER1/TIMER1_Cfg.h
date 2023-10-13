/*
 * TIMER1_Cfg.h
 *
 * Created: 9/18/2023 3:23:36 PM
 * Author: ENG.Ahmed Osama
 */ 


#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

			/* Configurations */
		/*@ref : TMR1_MODE_SELECT */
#define TMR1_MODE_SELECT						TMR1_MODE14_Fast_PWM_ICR1_TOP
/* @ref : TMR1_COMPARE_OUTPUT_MODE Ch-A & Ch-B */
#define TMR1_COMPARE_OUTPUT_MODE_ChA			TMR1_NONINVERTING_MODE
#define TMR1_COMPARE_OUTPUT_MODE_ChB			TMR1_NORMAL_COMPARE
/*@ref : TMR1_CLK_SELECT  "I put the default with Prescaler 64 " */
#define TMR1_CLK_SELECT							(TMR1_CLK_t)(TMR1_Prescaler_64)
		/* Set Preload value at normal mode */
#define TMR0_PRELOAD_VALUE						(uin16)(0)
		/* Set TOP value at mode 14 & 15 */
#define TMR1_TOP_Define							(uin32)(65535)


			/* Reference configuration parameter */
			
/*@ref : TMR1_MODE_SELECT */
/*
	•	0- TMR1_MODE0_Normal
		1- TMR1_MODE1_PWM_PhaseC_8BIT
		2- TMR1_MODE2_PWM_PhaseC_9BIT
		3- TMR1_MODE3_PWM_PhaseC_10BIT
	•	4- TMR1_MODE4_CTC_OCR1A_TOP
	•	5- TMR1_MODE5_FastPWM_8BIT
	•	6- TMR1_MODE6_FastPWM_9BIT
	•	7- TMR1_MODE7_FastPWM_10BIT
		8- TMR1_MODE8_PWM_Phase_Freq_Correct_ICR1_TOP
		9- TMR1_MODE9_PWM_Phase_Freq_Correct_OCR1A_TOP
		10- TMR1_MODE10_PWM_PhaseC_ICR1_TOP
		11- TMR1_MODE11_PWM_PhaseC_OCR1A_TOP
	•	12- TMR1_MODE12_CTC_ICR1_TOP
	•	14- TMR1_MODE14_Fast_PWM_ICR1_TOP
		15- TMR1_MODE15_Fast_PWM_OCR1A_TOP				
*/

/* @ref : TMR1_COMPARE_OUTPUT_MODE */
/*
	•	1- TMR1_NORMAL_COMPARE
	•	2- TMR1_TOG_ON_COMPARE
		3- TMR1_NONINVERTING_MODE
		4- TMR1_INVERTING_MODE
*/

/*@ref : TMR1_CLK_SELECT */
/*
		1-TMR1_STOP						
		2-TMR1_Prescaler_1				
		3-TMR1_Prescaler_8				
		4-TMR1_Prescaler_64				
		5-TMR1_Prescaler_256				
		6-TMR1_Prescaler_1024			
		7-TMR1_CLK_FALLING				
		8-TMR1_CLK_RAISING				
*/

#endif /* TIMER1_CFG_H_ */