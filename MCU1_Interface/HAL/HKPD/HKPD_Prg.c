/*
 * HKPD_Prg.c
 *
 *  Created on: Sep 9, 2023
 *      Author: weza
 */

#include"DIO_int.h"
#include"HKPD_Config.h"
#include"HKPD_Int.h"
#include"util/delay.h"
void HKPD_VoidInit(void) {
	//ROWS config
	MCAL_SetPinMode(KPD_ROW1, OUTPUT_HIGH);
	MCAL_SetPinMode(KPD_ROW2, OUTPUT_HIGH);
	MCAL_SetPinMode(KPD_ROW3, OUTPUT_HIGH);
	MCAL_SetPinMode(KPD_ROW4, OUTPUT_HIGH);
	//COLS config
	MCAL_SetPinMode(KPD_COL1, INPUT_PULLUP);
	MCAL_SetPinMode(KPD_COL2, INPUT_PULLUP);
	MCAL_SetPinMode(KPD_COL3, INPUT_PULLUP);
	MCAL_SetPinMode(KPD_COL4, INPUT_PULLUP);
}

U8 HKPD_GetPressedKey(void) {
	U8 L_GetPressedKey = -50;
	U8 L_U8Return = 80;
	for (U8 ROW = ROW_START; ROW >= ROW_END; ROW--){
		MCAL_SetPinMode(ROW, OUTPUT_LOW);
		for (U8 COL = COL_START; COL >= COL_END; COL--){
			MCAL_DIOReadChannel(COL, &L_GetPressedKey);
			if (L_GetPressedKey == 0) {
				_delay_ms(15);
				MCAL_DIOReadChannel(COL, &L_GetPressedKey);
				if (L_GetPressedKey == 0) {

					L_U8Return = ARR[ROW_START-ROW][COL_START-COL];
					while(L_GetPressedKey == 0){MCAL_DIOReadChannel(COL, &L_GetPressedKey);}
				}
			}
		}
		MCAL_SetPinMode(ROW, OUTPUT_HIGH);
	}
	return L_U8Return;
}

