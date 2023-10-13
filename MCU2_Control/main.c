/*
 * ATmega32A_Drivers.c
 * Created: 9/17/2023 10:11:01 AM
 * Author: ENG.Ahmed Osama
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"


#include "SPI_Int.h"
#include "DIO_int.h"
#include "DIO_Prv.h"
#include "ADC_int.h"
#include "GI_Int.h"


#include "LCD_Int.h"
#include "ServoM.h"

#include "lights.h"
#include "AC_sys.h"
#include "Door.h"

/** Operation_NUMs **/

#define DoorON			 1
#define DoorOFF			 2
#define AC_ON			 3
#define AC_OFF			 4
#define ALL_Lights_ON	 6
#define ALL_Lights_OFF	 7
#define Light_Contrast	 8
#define R1_ON			 10
#define R1_OFF			 11
#define R2_ON			 12
#define R2_OFF			 13
#define R3_ON			 14
#define R3_OFF			 15

uin8  Operation_NUM ;
uin8  AirC_Lock = 0 ;
/**/

void SPI_R();
//void Temp_Control(void);


int main(void)
{
	uin8 t = 0  ;
	uin16 tmp = 0;
	LCD_init();
	LIGHTS_INIT();
	SRVM_voidInit();
	AC_Tmp_init();
	GI_voidEnable();


	/* SPI  */
	
	DIO_SetPinMode(SCK,PIN_Input);
	DIO_SetPinMode(SS,PIN_Input);
	DIO_SetPinMode(MISO,PIN_Output_LoW);
	DIO_SetPinMode(MOSI,PIN_Input);
	
	S_SPICfg_t SPI_Cfg ;
	
	SPI_Cfg.SPI_EN = SPI_Enable ;
	SPI_Cfg.MODE = SPI_Mode_Slave ;
	SPI_Cfg.DataORD = SPI_DataORD_LSB ;
	SPI_Cfg.Data_Mode = SPI_DataMode_Leading_RisingSample ;
	SPI_Cfg.Clock_Rate = SPI_Clock_Divide_4 ;
	SPI_Cfg.Interrupt_EN = SPI_Interrupt_Enable ;
	SPI_Cfg.SPI_CALLBACK = SPI_R ;
	
	SPI_Init(&SPI_Cfg);
	/**/

	while (1)
	{
		// Get Operation by SPI
				LCD_GOTO_YX(2,0);
				LCD_Send_NUM(Operation_NUM);

		// Switch on operation
		switch(Operation_NUM)
		{
			case 0 :
				ADC_StartConversion(ADC0);
				tmp = ADC_GetRead();
				LM35_Motor_Buzzer_Control(((uin32)tmp * 100) /1024);
							LCD_GOTO_YX(3,0);
							LCD_Send_NUM(tmp);
				break;
				
			case DoorON :
				U8OPEN_DOOR();
				Operation_NUM = 0 ;
				break;
				
			case DoorOFF :
				U8CLOSE_DOOR();
				Operation_NUM = 0 ;
				break;
				
			case AC_ON :
				AirC_ON();
				AirC_Lock = 1 ;
				Operation_NUM = 0 ;
				break;
				
			case AC_OFF :
				AirC_OFF();
				AirC_Lock = 0 ;
				Operation_NUM = 0 ;
				break;
				
			case ALL_Lights_ON :
				LIGHTS_ON();
				Operation_NUM = 0 ;				
				break;
				
			case ALL_Lights_OFF :
				LIGHTS_CLOSE();
				Operation_NUM = 0 ;				
				break;
				
			case Light_Contrast :
				if(t == 0)
				{
					GI_voidEnable();
					LIGHTS_ROOM_CONTRAST_ON();
					TOG_BIT(t,0);
				}else
				{
					GI_voidDisable();
					LIGHTS_ROOM_CONTRAST_OFF();
					TOG_BIT(t,0);
				}
				Operation_NUM = 0 ;
				break;
				
			case R1_ON :
				LIGHTS_ROOM_CONTROL(1,LED_ON);
				Operation_NUM = 0 ;
				break;
				
			case R1_OFF :
				LIGHTS_ROOM_CONTROL(1,LED_OFF);
				Operation_NUM = 0 ;
				break;
				
			case R2_ON :
				LIGHTS_ROOM_CONTROL(2,LED_ON);
				Operation_NUM = 0 ;
				break;
				
			case R2_OFF :
				LIGHTS_ROOM_CONTROL(2,LED_OFF);
				Operation_NUM = 0 ;
				break;
				
			case R3_ON :
				LIGHTS_ROOM_CONTROL(3,LED_ON);
				LIGHTS_ROOM_CONTROL(4,LED_ON);
				Operation_NUM = 0 ;
				break;
				
			case R3_OFF :
				LIGHTS_ROOM_CONTROL(3,LED_OFF);
				LIGHTS_ROOM_CONTROL(4,LED_OFF);
				Operation_NUM = 0 ;
				break;	
		}	
	}
}

/* SPI Interrupt Receive */

void SPI_R()
{
	Operation_NUM = SPI_ReveiveData ('d');
}

/**/


















/* ADC Contrast LED */
// void Temp_Control(void)
// {
// 	uin16 Digital_data;
// 	Digital_data = ADC_GetRead();
// 	LM35_Motor_Buzzer_Control((uin32)(Digital_data * 100) /1024);
// 	LCD_GOTO_YX(3,0);
// 	LCD_Send_NUM(Digital_data);
// 	_delay_ms(500);
// }


























