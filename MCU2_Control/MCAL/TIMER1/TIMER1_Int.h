/*
 * TIMER1_Int.h
 * Created: 9/18/2023 3:22:47 PM
 * Author: ENG. Ahmed Osama
 */



#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_


/* Macros */
/*@ref : TMR1_CLK_SELECT */

typedef enum {
	TMR1_STOP = 0,
	TMR1_Prescaler_1,
	TMR1_Prescaler_8,
	TMR1_Prescaler_64,
	TMR1_Prescaler_256,
	TMR1_Prescaler_1024,
	TMR1_CLK_FALLING,
	TMR1_CLK_RAISING
}TMR1_CLK_t;


/* APIs */

void TMR1_voidInit(void);
void TMR1_voidStart(void);
void TMR1_voidStop(void);
void TMR1_voidStart_with_clk(TMR1_CLK_t CLK);		/* to start with specific clk */
void TMR1_voidSetPreload(uin16 Preload);
void TMR1_voidSetOutputCompareMatchValueA(uin16 Copy_u16CompareValue);
void TMR1_voidSetOutputCompareMatchValueB(uin16 Copy_u16CompareValue);
void TMR1_voidSetCallBack(void (*ptr)(void));

void TMR1_voidSetPWM_DutyC(float DyC);
void TMR1_voidSetFreq(uin16 Fd);







#endif /* TIMER1_INT_H_ */