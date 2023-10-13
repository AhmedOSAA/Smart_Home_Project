/*
 * ADC_int.h
 * Created: 9/16/2023 9:04:42 AM
 * Author: ENG. Ahmed Osama
 */ 


#include "STD_TYPES.h"
#include "ADC_Cfg.h"

#ifndef ADC_INT_H_
#define ADC_INT_H_


/* APIs */

void ADC_init();

void ADC_StartConversion(uin8 Channelx);

uin16 ADC_GetRead();


void ADC_ScanGroupRead(uin8* ScanGroupx , uin16* buffer );

void ADC_SetCALLBACKFunc(void(*ptr)());

#endif /* ADC_INT_H_ */