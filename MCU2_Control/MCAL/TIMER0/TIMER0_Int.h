/*
 * TIMER0_Int.h
 * Created: 9/17/2023 11:30:54 AM
 * Author: ENG .Ahmed Osama
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

/* APIs */

void TMR0_voidInit(void);
void TMR0_voidStart(void);
void TMR0_voidStop(void);
void TMR0_voidSetCallBack(void (*ptr)(void));
void TMR0_voidCompareMatchValue(uin8 Copy_u8CompareValue);
void TMR0_voidSetDelay_ms_usingCTC (uin16 Copy_u16Delay_ms);
void TMR0_voidSetPWM_DutyC(in16 Pres);
#endif /* TIMER0_INT_H_ */