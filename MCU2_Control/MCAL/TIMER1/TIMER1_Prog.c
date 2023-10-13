/*
 * TIMER1_Prog.c
 * Created: 9/18/2023 3:23:50 PM
 * Author: ENG. Ahmed Osamaa
 */ 


/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "TIMER1_Priv.h"
#include "TIMER1_Cfg.h"
#include "TIMER1_Int.h"

/*GLOBAL CALL BACK FUNCTION */

static void (*TMR1_CALLBACK)(void) = NULL ;

/* Global Variable */

uin32 TOP = TMR1_TOP_Define ;

/* APIs */

void TMR1_voidInit(void)
{
			/*@ref : TMR1_MODE_SELECT */
	
#if TMR1_MODE_SELECT == TMR1_MODE0_Normal		
// Select Mode = Normal Mode (0)
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
// Set Over flow interrupt
	SET_BIT(TIMSK , TOIE1);
	TCNT1_u16 = TMR0_PRELOAD_VALUE ;

#elif TMR1_MODE_SELECT == TMR1_MODE1_PWM_PhaseC_8BIT
// Select Mode = PWM_PhaseC_8BIT Mode (1)
	SET_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE2_PWM_PhaseC_9BIT
// Select Mode = PWM_PhaseC_9BIT Mode (2)
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE3_PWM_PhaseC_10BIT
// Select Mode = PWM_PhaseC_10BIT Mode (3)
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE4_CTC_OCR1A_TOP
// Select Mode = CTC_OCR1A_TOP Mode (4)
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
	// Set Compare Match Ch-A interrupt
	SET_BIT(TIMSK , OCIE1A);
	
#elif TMR1_MODE_SELECT == TMR1_MODE5_FastPWM_8BIT
// Select Mode = TMR1_MODE5_FastPWM_8BIT Mode (5)
	SET_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
	
#elif TMR1_MODE_SELECT == TMR1_MODE6_FastPWM_9BIT
// Select Mode = FastPWM_9BIT Mode (6)
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
	
#elif TMR1_MODE_SELECT == TMR1_MODE7_FastPWM_10BIT
// Select Mode = FastPWM_10BIT Mode (7)
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE8_PWM_Phase_Freq_Correct_ICR1_TOP
// Select Mode = PWM_Phase_Freq_Correct_ICR1_TOP Mode (8)
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
	
#elif TMR1_MODE_SELECT == TMR1_MODE9_PWM_Phase_Freq_Correct_OCR1A_TOP
// Select Mode = PWM_Phase_Freq_Correct_OCR1A_TOP Mode (9)
	SET_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE10_PWM_PhaseC_ICR1_TOP
// Select Mode = PWM_PhaseC_ICR1_TOP Mode (10)
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE11_PWM_PhaseC_OCR1A_TOP
// Select Mode = PWM_PhaseC_OCR1A_TOP Mode (11)
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE12_CTC_ICR1_TOP
// Select Mode = CTC_ICR1_TOP Mode (12)
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
	// Set Compare Match Ch-B interrupt on ICU
	SET_BIT(TIMSK , TICIE1);

#elif TMR1_MODE_SELECT == TMR1_MODE14_Fast_PWM_ICR1_TOP
// Select Mode = Fast_PWM_ICR1_TOP Mode (14)
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);

#elif TMR1_MODE_SELECT == TMR1_MODE15_Fast_PWM_OCR1A_TOP
// Select Mode = Fast_PWM_OCR1A_TOP Mode (15)
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
	
#endif

				/*@ref : TMR1_MODE_SELECT */
/*Compare Output Mode for Channel A*/
TCCR1A |= (TMR1_COMPARE_OUTPUT_MODE_ChA<<COM1A0);
/*Compare Output Mode for Channel B*/
TCCR1A |= (TMR1_COMPARE_OUTPUT_MODE_ChB<<COM1B0);

				
}

void TMR1_voidStart(void)
{
	TMR1_voidStart_with_clk((TMR1_CLK_t)TMR1_CLK_SELECT);
}


/*@ref : CLK = TMR1_CLK_SELECT */
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
void TMR1_voidStart_with_clk(TMR1_CLK_t CLK)
{
	SET_MULTIBIT(TCCR1B,THREE_BIT,CS10,CLK);
}

void TMR1_voidStop(void)
{
	TMR1_voidStart_with_clk(TMR1_STOP);	
}

void TMR1_voidSetPreload(uin16 Preload)
{
	TCNT1_u16 = Preload ;
}


void TMR1_voidSetOutputCompareMatchValueA(uin16 Copy_u16CompareValue)
{
	#if TMR1_MODE_SELECT == TMR1_MODE4_CTC_OCR1A_TOP
	OCR1A_u16 = Copy_u16CompareValue ;
	#elif TMR1_MODE_SELECT == TMR1_MODE12_CTC_ICR1_TOP
	ICR1_u16 =  Copy_u16CompareValue ;
	#endif
}

void TMR1_voidSetOutputCompareMatchValueB(uin16 Copy_u16CompareValue)
{
	OCR1B_u16 = Copy_u16CompareValue ;
}

void TMR1_voidSetPWM_DutyC(float DyC)
{
	uin16 tmpOCR = 0 ;
	if(TMR1_COMPARE_OUTPUT_MODE_ChA == TMR1_INVERTING_MODE || TMR1_COMPARE_OUTPUT_MODE_ChB == TMR1_INVERTING_MODE) {DyC = 100-DyC ;}
	if(DyC <= 100 && DyC != 0)
	{
		/* Fast PWM Mode 5,6,7,14,15 */
		#if TMR1_MODE_SELECT == TMR1_MODE5_FastPWM_8BIT

		tmpOCR = ((((uin16)DyC*256)/100)-1) ;
		
		#elif TMR1_MODE_SELECT == TMR1_MODE6_FastPWM_9BIT

		tmpOCR = ((((uin16)DyC*512)/100)-1) ;

		#elif TMR1_MODE_SELECT == TMR1_MODE7_FastPWM_10BIT

		tmpOCR = ((((uin32)DyC*1024)/100)-1) ;
		
		#elif (TMR1_MODE_SELECT == TMR1_MODE14_Fast_PWM_ICR1_TOP || TMR1_MODE_SELECT == TMR1_MODE15_Fast_PWM_OCR1A_TOP )
		if(TMR1_MODE_SELECT == TMR1_MODE14_Fast_PWM_ICR1_TOP)
		{
			ICR1_u16 = TOP ;
		}
		else if (TMR1_MODE_SELECT == TMR1_MODE15_Fast_PWM_OCR1A_TOP)
		{
			OCR1A_u16 = TOP ;
		}
		
		tmpOCR = (uin16)((((float)DyC*(TOP+1))/100)-1) ;
		
		/* Fast PWM & PhaseC Mode 5,6,7,14,15 */
		#elif TMR0_MODE == TMR0_PhaseCorrect_PWM_Mode

		tmpOCR = ((((uin16)DyC*510)/100)/2) ;

		#endif
	}
	OCR1A_u16 = tmpOCR ;
}

void TMR1_voidSetFreq(uin16 Fd)
{
	TOP = (250000/Fd)-1 ;
}


void TMR1_voidSetCallBack(void (*ptr)(void))
{
	if(ptr)
	{
		TMR1_CALLBACK = ptr ;
	}
}







/* ISR Functions */

/* TMR1 OVI */
void __vector_9(void)__attribute__((signal));
void __vector_9(void)
{
	if(TMR1_CALLBACK)
	{
		TMR1_CALLBACK();
	}
}

void __vector_7(void)__attribute__((signal));
void __vector_7(void)
{
	if(TMR1_CALLBACK)
	{
		TMR1_CALLBACK();
	}
}

void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	if(TMR1_CALLBACK)
	{
		TMR1_CALLBACK();
	}
}