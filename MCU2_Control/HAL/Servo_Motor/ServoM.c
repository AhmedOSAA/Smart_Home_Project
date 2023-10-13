/*
 * ServoM.c
 * Created: 9/21/2023 4:27:25 PM
 * Author: ENG.Ahmed Osama
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "DIO_int.h"
#include "TIMER1_Int.h"
/* HAL */
#include "ServoM.h"


/* APIs */

void SRVM_voidInit()
{
	DIO_SetPinMode(PD5 , PIN_Output_LoW);
	/* TMR1 init at PWM mode 14 */
	TMR1_voidInit();
	/* Set PWM Freq. = 50 */
	TMR1_voidSetFreq(50);
}

void SRVM_voidON(in8 Copy_u8Angle)
{
	float ANG = 0 ;
	Copy_u8Angle = Copy_u8Angle + 90 ; 
	/* Set PWM duty cycle between 5 : 10
	 depend on desired angle[-90 : 90]
	 Based on calculation DutyC_Desired = ((5/180)*(Angle_Desired + 90)) + 5 */
	ANG = (((500.0/180.0)*((float)Copy_u8Angle))/100.0)+5 ;
	TMR1_voidSetPWM_DutyC(ANG);
	/* TMR1 start */
	TMR1_voidStart();
}
void SRVM_voidOFF(void)
{
	/* TMR1 stop */
	TMR1_voidStop();
}
