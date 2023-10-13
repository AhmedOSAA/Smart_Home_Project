/*
 * ADC_Priv.h
 * Created: 9/16/2023 9:05:04 AM
 * Author: ENG. Ahmed Osama
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/* ADC Register Address base */

#define ADMUX			(*(vuin8 *)(0x27))

#define MUX0			0
#define MUX1			1
#define MUX2			2
#define MUX3			3
#define MUX4			4
#define ADLAR			5
#define REFS0			6
#define REFS1			7

#define ADCSRA			(*(vuin8 *)(0x26))

#define ADPS0			0
#define ADPS1			1
#define ADPS2			2
#define ADIE			3
#define ADIF			4
#define ADATE			5
#define ADSC			6
#define ADEN			7
     
#define ADCL			(*(vuin16 *)(0x24))
#define ADCH			(*(vuin8 *)(0x25))
#define ADC_Data_REG	ADCL


#define SFIOR			(*(vuin8 *)(0x50))

#define ADTS0			5
#define ADTS1			6
#define ADTS2			7

/* Instant Macros */
#define ADC_Enable()				ADCSRA |= (1<<ADEN)
#define ADC_Disable()				ADCSRA &= ~(1<<ADEN)

#define INT_Enable()				ADCSRA |= (1<<ADIE)
#define INT_Disable()				ADCSRA &= ~(1<<ADIE)

#define ADC_Start_Con()				ADCSRA |= (1<<ADSC)

#define Polling_ON_Flag()			while(!(GET_BIT(ADCSRA , ADIF)))
#define CLR_intFLAG()				SET_BIT(ADCSRA , ADIF)



#endif /* ADC_PRIV_H_ */