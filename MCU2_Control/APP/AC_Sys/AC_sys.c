/*
 * AC_sys.c
 *
 * Created: 10/4/2023 5:06:48 PM
 *  Author: midom
 */ 


/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"

/* MCAL */
#include "DIO_int.h"
#include "ADC_int.h"

/* HAL */
#include "AC_sys.h"


/* Extern Variable */

extern uin8 AirC_Lock ;

void AC_Tmp_init()
{
	DIO_SetPinMode(LED_ALARM,PIN_Output_LoW);
	DIO_SetPinMode(MOTOR_PUMP,PIN_Output_LoW);
	DIO_SetPinMode(Buzzer,PIN_Output_LoW);
	DIO_SetPinMode(AC_PIN,PIN_Output_LoW);
	
 	DIO_SetPinMode(PA0,PIN_Input);
 	ADC_init();
 	ADC_StartConversion(ADC0);

}

uin8 LM35_ADC_Get_Temp ()
{
	 uin16 Digital_data;
	 uin8 temp;

	 Digital_data = ADC_GetRead();

	 temp = (uin32)(Digital_data * 100) /1024;

	 return temp;
}

void Buzzer_ON()
{
	DIO_WritePinVal(Buzzer ,High); // buzzer
}
void Buzzer_OFF()
{
	DIO_WritePinVal(Buzzer ,Low); // buzzer
}

void AirC_ON()
{
	DIO_WritePinVal(AC_PIN, High); // for AC ON
}
void AirC_OFF()
{
	DIO_WritePinVal(AC_PIN, Low); // for AC ON
}


void LM35_Motor_Buzzer_Control(uin8 tmp)
{
	if(AirC_Lock == 0)
	{
		if (tmp >= 25)
		{
			DIO_WritePinVal(AC_PIN, High); // for AC ON
		}
		else if(tmp < 18)
		{
			DIO_WritePinVal(AC_PIN, Low);  // for AC OFF
		}
	}

		/* Fire System */
	if(tmp > 50)
	{
		Buzzer_ON();
		DIO_WritePinVal(LED_ALARM,High);
		DIO_WritePinVal(MOTOR_PUMP,High);
	}else if (tmp < 35)
	{
		Buzzer_OFF();
		DIO_WritePinVal(LED_ALARM,Low);
		DIO_WritePinVal(MOTOR_PUMP,Low);
	}
}