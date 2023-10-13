/*
 * AC_sys.h
 *
 * Created: 10/4/2023 5:06:24 PM
 *  Author: midom
 */ 


#ifndef AC_SYS_H_
#define AC_SYS_H_


#define LED_ALARM	PC4
#define MOTOR_PUMP	PC5
#define Buzzer		PC6
#define AC_PIN		PC7


/*API*/

void AC_Tmp_init();

uin8 LM35_ADC_Get_Temp ();

void LM35_Motor_Buzzer_Control(uin8 tmp);

void AirC_ON();
void AirC_OFF();

void Buzzer_ON();
void Buzzer_OFF();



#endif /* AC_SYS_H_ */