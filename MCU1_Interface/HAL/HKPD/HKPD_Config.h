/*
 * HKPD_Config.h
 *
 *  Created on: Sep 9, 2023
 *      Author: weza
 */

#ifndef HAL_HKPD_HKPD_CONFIG_H_
#define HAL_HKPD_HKPD_CONFIG_H_

#define KPD_ROW1    PORTC5
#define KPD_ROW2    PORTC4
#define KPD_ROW3    PORTC3
#define KPD_ROW4    PORTC2
#define KPD_COL1    PORTD7
#define KPD_COL2    PORTD6
#define KPD_COL3    PORTD5
#define KPD_COL4    PORTD4
#define ROW_START   PORTC5
#define ROW_END     PORTC2
#define COL_START   PORTD7
#define COL_END     PORTD4
U8 ARR[4][4]={{7,8,9,10},{4,5,6,11},{1,2,3,12},{13,0,15,16}};

#endif /* HAL_HKPD_HKPD_CONFIG_H_ */
