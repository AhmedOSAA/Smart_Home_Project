#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "lights.h"
#include "TIMER0_Cfg.h"
#include "TIMER0_Int.h"
#include "TIMER0_Priv.h"
#include "DIO_int.h"


uin8 rooms[ROOMS_NUM] = {PC0,PC1,PC2,PC3,PC4};

void LIGHTS_INIT(void)
{
	uin8 i;
	for(i=0 ; i<ROOMS_NUM-1;i++)
	{
		DIO_SetPinMode(rooms[i],PIN_Output_LoW);
	}
	DIO_SetPinMode(rooms[4],PIN_Input);
	TMR0_voidInit();
}
void LIGHTS_ROOM_CONTROL(uin8 roomNum , uin8 roomStatues)
{

	switch(roomNum){
	case 1:
		if(roomStatues == LED_ON )
		{
			DIO_WritePinVal(rooms[roomNum -1],High);
		}
		else
		{
			DIO_WritePinVal(rooms[roomNum -1],Low);
		}
		break;
	case 2:
		if(roomStatues == LED_ON )
		{
			DIO_WritePinVal(rooms[roomNum -1],High);
		}
		else
		{
			DIO_WritePinVal(rooms[roomNum -1],Low);
		}
		break;
	case 3:
		if(roomStatues == LED_ON )
		{
			DIO_WritePinVal(rooms[roomNum -1],High);
		}
		else
		{
			DIO_WritePinVal(rooms[roomNum -1],Low);
		}
		break;
	case 4:
		if(roomStatues == LED_ON )
		{
			DIO_WritePinVal(rooms[roomNum -1],High);
		}
		else
		{
			DIO_WritePinVal(rooms[roomNum -1],Low);
		}
		break;
	case 5:
		if(roomStatues == LED_ON )
		{
			DIO_WritePinVal(rooms[roomNum -1],High);
		}
		else
		{
			DIO_WritePinVal(rooms[roomNum -1],Low);
		}
		break;
	}



}
void LIGHTS_CLOSE(void)
{
	uin8 i;
	for(i=0 ; i<ROOMS_NUM;i++)
	{
		DIO_WritePinVal(rooms[i],Low);
	}
}
void LIGHTS_ON(void)
{
	uin8 i;
	for(i=0 ; i<ROOMS_NUM;i++)
	{
		DIO_WritePinVal(rooms[i],High);
	}
}
void  LIGHTS_ROOM_CONTRAST(uin8 duty)
{
	TMR0_voidSetPWM_DutyC(duty);
}

void LIGHTS_ROOM_CONTRAST_ON()
{
	TMR0_voidStart();
}

void LIGHTS_ROOM_CONTRAST_OFF()
{
	TMR0_voidStop();
}
