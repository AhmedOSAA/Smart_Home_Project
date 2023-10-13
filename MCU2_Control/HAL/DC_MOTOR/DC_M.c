/*
 * DC_M.c
 * Created: 9/21/2023 5:46:21 PM
 * Author: ENG.Ahmd Osama
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "DIO_int.h"
#include "TIMER0_Int.h"
/* HAL */
#include "DC_M.h"

/* APIs */
void DCM_voidInit()
{
	/* Pin Configuration */
	DIO_SetPinMode(DCM_PWM , PIN_Output_LoW);
	DIO_SetPinMode(DCM_DIR , PIN_Output_LoW);
	DIO_SetPinMode(DCM_EN  , PIN_Output_High);
	
	TMR0_voidInit();
}
void DCM_voidON(uin8 Copy_u8Direction) //you have to specify speed before on
{

	
	/* Turn DC motor on using H-Bridge
	 By Setting PWM, Dir and Enable pins with high
	 or Dir Low depend on Copy_u8Direction*/
	/* DIR */
	if(Copy_u8Direction == DCM_CLOCK_WISE)
	{
		DIO_WritePinVal(DCM_DIR , High);
	}else
	{
		DIO_WritePinVal(DCM_DIR , Low);
	}
	TMR0_voidStart();
}

void DCM_voidControlSpeed(uin8 Copy_u8Speed)
{
	/*Init TMR0*/
	TMR0_voidInit();
	/*Put speed*/
	TMR0_voidSetPWM_DutyC(Copy_u8Speed);
}

void DCM_voidOFF(void)
{
	TMR0_voidStop();
}
