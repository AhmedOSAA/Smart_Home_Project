/*
 * ADC_Cfg.h
 * Created: 9/16/2023 9:04:26 AM
 * Author: ENG. Ahmed Osama
 */ 

#include "STD_TYPES.h"

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/* Init Configuration */

/*@ref : Reference Selection @ ADMUX : REFS0 */
#define Reference_Selection					ADC_Ref_AVCC
/*@ref : ADC Prescaler @ADCSRA : ADPS0*/
#define ADC_Prescaler						ADC_Division_128
/*@ref : Mode of Trigger Source Selections */
#define ADC_MODE_SELECTION					ADC_Single_Conversion
/*@ref : Enable/Disable */
#define ADC_Interrupt						Disable
/*@ref : Enable/Disable */
#define Left_Adjust_Result					Disable



/*ADC Channels*/

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7


#define  SG0Channel1		ADC2
#define  SG0Channel2		ADC1
#define  SG0Channel3		ADC3
#define  SG0Channel4		ADC4

#define  SG1Channel1		ADC5
#define  SG1Channel2		ADC6
#define  SG1Channel3		ADC7
#define  SG1Channel4		ADC0


#define ScanGroup0			SG0
#define ScanGroup1			SG1
		
		
			
/* Enable/Disable Macro */
#define Enable					1
#define Disable					0

				
/* Reference Selection */

#define ADC_Ref_AREF			0
#define ADC_Ref_AVCC			1
#define ADC_Ref_Internal256		3

/* ADC Prescaler */

#define ADC_Division_2			0b001
#define ADC_Division_4			0b020
#define ADC_Division_8			0b011
#define ADC_Division_16			0b100
#define ADC_Division_32			0b101
#define ADC_Division_64			0b110
#define ADC_Division_128		0b111

/*Mode of Trigger Source Selections*/

#define ADC_Free_Running_mode						0b000
#define ADC_Analog_Comparator						0b001
#define ADC_External_Interrupt_Request_0			0b010
#define ADC_Timer_Counter0_Compare_Match			0b011
#define ADC_Time_Counter0_Overflow					0b100
#define ADC_Timer_Counter1_Compare_MatchB			0b101
#define ADC_Timer_Counter1_Overflow					0b110
#define ADC_Timer_Counter1_Capture_Event			0b111
#define ADC_Single_Conversion						8

#endif /* ADC_CFG_H_ */