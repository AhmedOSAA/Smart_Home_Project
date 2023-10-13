/*
 * Door.c
 *
 * Created: 10/8/2023 6:50:57 PM
 *  Author: midom
 */ 

/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"

#include "ServoM.h"
#include "Door.h"


void U8OPEN_DOOR(void)
{
	SRVM_voidON(90);
}

void U8CLOSE_DOOR(void)
{
	SRVM_voidON(-90);
}
