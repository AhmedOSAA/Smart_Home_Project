/*
 * TIMER1_Priv.h
 * Created: 9/18/2023 3:23:21 PM
 * Author: ENG.Ahmed Osamaa
 */ 


#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_

		   /* TIMER1 reference configuration parameters */

/* @ref : TMR1_MODE_SELECT */

#define TMR1_MODE0_Normal										(0x0)
#define TMR1_MODE1_PWM_PhaseC_8BIT								(0x1)
#define TMR1_MODE2_PWM_PhaseC_9BIT								(0x2)
#define TMR1_MODE3_PWM_PhaseC_10BIT								(0x3)
#define TMR1_MODE4_CTC_OCR1A_TOP								(0x4)
#define TMR1_MODE5_FastPWM_8BIT									(0x5)
#define TMR1_MODE6_FastPWM_9BIT									(0x6)
#define TMR1_MODE7_FastPWM_10BIT								(0x7)
#define TMR1_MODE8_PWM_Phase_Freq_Correct_ICR1_TOP				(0x8)
#define TMR1_MODE9_PWM_Phase_Freq_Correct_OCR1A_TOP				(0x9)
#define TMR1_MODE10_PWM_PhaseC_ICR1_TOP							(0xA)
#define TMR1_MODE11_PWM_PhaseC_OCR1A_TOP						(0xB)
#define TMR1_MODE12_CTC_ICR1_TOP								(0xC)
#define TMR1_MODE14_Fast_PWM_ICR1_TOP							(0xE)
#define TMR1_MODE15_Fast_PWM_OCR1A_TOP							(0xF)

/* @ref : TMR1_COMPARE_OUTPUT_MODE */

#define TMR1_NORMAL_COMPARE						(0b00)
#define TMR1_TOG_ON_COMPARE						(0b01)
#define TMR1_NONINVERTING_MODE					(0b10)
#define TMR1_INVERTING_MODE						(0b11)

/*@ref : TMR1_CLK_SELECT */

		
// #define TMR1_STOP							(0)
// #define TMR1_Prescaler_1						(1)
// #define TMR1_Prescaler_8						(2)
// #define TMR1_Prescaler_64					(3)
// #define TMR1_Prescaler_256					(4)
// #define TMR1_Prescaler_1024					(5)
// #define TMR1_CLK_FALLING						(6)
// #define TMR1_CLK_RAISING						(7)


                       /* TIMER1 REGISTERS*/

// Timer/Counter1 Control Register A
#define TCCR1A             (*(vuin8*)0x4F)

#define WGM10              0
#define WGM11              1
#define FOC1B              2
#define FOC1A              3
#define COM1B0             4
#define COM1B1             5
#define COM1A0             6
#define COM1A1             7

// Timer/Counter1 Control Register B
#define TCCR1B             (*(vuin8*)0x4E)

#define CS10               0
#define CS11               1
#define CS12               2
#define WGM12              3
#define WGM13              4
#define ICES1              6
#define ICNC1              7

// Timer/Counter1
#define TCNT1_u16          (*(vuin16*)0x4C)

// Output Compare Register 1 A
#define OCR1A_u16          (*(vuin16*)0x4A)

// Output Compare Register 1 B
#define OCR1B_u16          (*(vuin16*)0x48)

// Input Capture Register 1
#define ICR1_u16           (*(vuin16*)0x46)

// Timer/Counter Interrupt Mask Register
#define TIMSK              (*(vuin8*)0x59)

#define TOIE1              2
#define OCIE1B             3
#define OCIE1A             4
#define TICIE1             5

// Timer/Counter Interrupt Flag Register
#define TIFR              (*(vuin8*)0x58)

#define TOV1				2
#define OCF1B				3
#define OCF1A				4
#define ICF1				5   

#endif /* TIMER1_PRIV_H_ */