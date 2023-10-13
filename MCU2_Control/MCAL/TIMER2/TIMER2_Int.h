/*
 * TIMER2_Int.h
 * Created: 9/17/2023 11:30:54 AM
 * Author: ENG .Ahmed Osama
 */ 


#ifndef TIMER2_INT_H_
#define TIMER2_INT_H_

/* APIs */

void TMR2_voidInit(void);
void TMR2_voidStart(void);
void TMR2_voidStop(void);
void TMR2_voidSetCallBack(void (*ptr)(void));
void TMR2_voidCompareMatchValue(uin8 Copy_u8CompareValue);
void TMR2_voidSetDelay_ms_usingCTC (uin16 Copy_u16Delay_ms);
void TMR2_voidSetPWM_DutyC(uin16 Pres);
#endif /* TIMER2_INT_H_ */