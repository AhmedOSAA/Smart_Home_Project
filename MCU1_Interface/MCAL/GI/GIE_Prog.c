/*
 * GIE_Prog.c
 *
 *  Created on: Sep 14, 2023
 *      Author: weza
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GIE_Priv.h"
#include"GIE_Int.h"
void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidDis(void)
{
	CLR_BIT(SREG,7);
}



