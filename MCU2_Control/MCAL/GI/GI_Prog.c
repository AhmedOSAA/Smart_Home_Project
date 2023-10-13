/*
 * GI_Prog.c
 * Created: 9/11/2023 11:59:36 AM
 * Author: ENG. Ahmed Osama
 */ 


/* includes */
#include "GI_Int.h"
#include "GI_Priv.h"


/* APIs */

void GI_voidEnable(void)
{
	SRGE |= 1<<I ; 
}
void GI_voidDisable(void)
{
	SRGE &= ~(1<<I) ;
}

