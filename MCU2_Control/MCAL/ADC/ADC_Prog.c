/*
 * ADC_Prog.c
 * Created: 9/16/2023 9:05:28 AM
 * Author: ENG. Ahmed Osama
 */ 


/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"


/* MCAL */
#include "ADC_Priv.h"
#include "ADC_Cfg.h"
#include "ADC_int.h"

/* Call Back Function */
static void (*ADC_PrivatePTR)(void) = NULL ;

/* Generic Array */
uin8 SG0[4] = {SG0Channel1,SG0Channel2,SG0Channel3,SG0Channel4};

uin8 SG1[4] = {SG1Channel1,SG1Channel2,SG1Channel3,SG1Channel4};

/* APIs */

void ADC_init()
{	
	#if ADC_MODE_SELECTION != ADC_Single_Conversion
	SET_BIT(ADCSRA,ADATE);
	SET_MULTIBIT(SFIOR ,THREE_BIT,ADTS0,ADC_MODE_SELECTION);
	//SET_BIT(ADCSRA,ADSC);
	#endif
	/* Set ADC_Prescaler */
	SET_MULTIBIT(ADCSRA,THREE_BIT,ADPS0,ADC_Prescaler);
	/* Set Reference_Selection */
	SET_MULTIBIT(ADMUX,TWO_BIT,REFS0,Reference_Selection);
	/* Set Left_Adjust_Result */
	ADMUX  |= (Left_Adjust_Result<<ADLAR)  ;
	/* Set Interrupt */
	ADCSRA |= (ADC_Interrupt<<ADIE)  ;
	/* Enable ADC */
	ADCSRA |= (1<<ADEN) ;
	
}

void ADC_StartConversion(uin8 Channelx)
{
	/* Set Channel select */
	SET_MULTIBIT((ADMUX),FIVE_BIT,MUX0,Channelx);
	/* Start Conversion */
	//#if ADC_MODE_SELECTION == ADC_Single_Conversion
	ADC_Start_Con();
	//#endif
}

uin16 ADC_GetRead()
{
	#if ADC_MODE_SELECTION != ADC_Single_Conversion
	return (uin16)ADC_Data_REG ;
	#elif ADC_MODE_SELECTION == ADC_Single_Conversion
	Polling_ON_Flag();					/* while(!(GET_BIT(ADCSRA , ADIF))); */
	CLR_intFLAG();						/* Clear flag bit (ADIF) by set it with one */
	return (uin16)ADC_Data_REG ;
	#endif
}

void ADC_ScanGroupRead(uin8* ScanGroupx , uin16* buffer)
{
	uin8 i ;
	for(i=0;i<4;i++)
	{
		buffer[i] = ScanGroupx[i];	
	}
	
}

void ADC_SetCALLBACKFunc(void(*ptr)(void))
{
	if(ptr != NULL)
	{
		ADC_PrivatePTR = ptr ;
	}	
}

/* Interrupt Functions (ISR) */

void __vector_16()__attribute__((signal));
void __vector_16()
{
	if(ADC_PrivatePTR != NULL)
	{
		ADC_PrivatePTR();
	}
}