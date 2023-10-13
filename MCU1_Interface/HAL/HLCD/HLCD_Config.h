/*
 * HLCD_Config.h
 *
 *  Created on: Sep 9, 2023
 *      Author: weza
 */

#ifndef HAL_HLCD_HLCD_CONFIG_H_
#define HAL_HLCD_HLCD_CONFIG_H_

#define RS PORTA3
#define EN PORTA2
#define DATA4  PORTB0
#define DATA5  PORTB1
#define DATA6  PORTB2
#define DATA7  PORTB3
U8 HLCD_DATA[]={DATA4,DATA5,DATA6,DATA7};

#endif /* HAL_HLCD_HLCD_CONFIG_H_ */
