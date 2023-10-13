
#ifndef LIGHTS_H_
#define LIGHTS_H_

#include "STD_TYPES.h"
#include "DIO_int.h"

#define LED_ON  1
#define LED_OFF 0

#define ROOMS_NUM  5

void LIGHTS_INIT(void);
void LIGHTS_ROOM_CONTROL(uin8 roomNum , uin8 roomStatues);
void LIGHTS_ROOM_CONTRAST(uin8 duty);
void LIGHTS_ROOM_CONTRAST_ON();
void LIGHTS_ROOM_CONTRAST_OFF();
void LIGHTS_ON(void);
void LIGHTS_CLOSE(void);
#endif /* LIGHTS_H_ */
