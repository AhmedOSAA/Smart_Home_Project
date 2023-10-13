/*
 * DC_M.h
 * Created: 9/21/2023 5:46:12 PM
 * Author: ENG.Ahmd Osama
 */ 


#ifndef DC_M_H_
#define DC_M_H_

/* Configure pins */

#define DCM_PWM		PB3
#define DCM_DIR		PB5
#define DCM_EN		PB6



#define DCM_CLOCK_WISE                   1
#define DCM_COUNTER_CLOCK_WISE           2

/* APIs */

void DCM_voidInit();
void DCM_voidON(uin8 Copy_u8Direction);
void DCM_voidControlSpeed(uin8 Copy_u8Speed);
void DCM_voidOFF(void);



#endif /* DC_M_H_ */