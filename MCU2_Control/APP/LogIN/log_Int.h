/*
 * log_Int.h
 *
 * Created: 10/1/2023 11:00:36 AM
 *  Author: midom
 */ 


#ifndef LOG_INT_H_
#define LOG_INT_H_

/* .h Log */

#define PassDigit			3

typedef enum
{
	Pass_False = 0 ,
	Pass_True = 1
	
}Pass_Statue_t;


void LogIN_Init(void);
void Delete_User();
void ADD_User();
Pass_Statue_t Compare_User();

/**/



#endif /* LOG_INT_H_ */