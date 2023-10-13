/*
 * LogIN.c
 *
 * Created: 10/1/2023 1:18:15 PM
 *  Author: midom
 */ 



/* Includes */
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_delay_Handling.h"

/* MCAL */
#include "I2C_Int.h"

/* HAL */
#include "EEPROM_Int.h"

#include "log_Int.h"


//uin16 EEPROM_ADDRESSES[5] = {50,55,60,65,70} ;



// void LogIN_Init(void)
// {
// 	EEPROM_voidInit();
// }
// 
// 
// void ADD_User()
// {
// 	uin8 ID_User ;
// 	in8 Added_Password[4] ;
// 	// Get ID_User with SPI 
// 	
// 	// Get Added_Password With SPI
// 	
// 	EEPROM_voidWritePage(EEPROM_ADDRESSES[ID_User],Added_Password,PassDigit);
// }
// 
// void Delete_User()
// {
// 	uin8 ID_User ;
// 	// Get ID_User with SPI
// 		
// 	// Delete user from EEPROM	
// 	EEPROM_voidWritePage(EEPROM_ADDRESSES[ID_User],"000",PassDigit);
// }
// 
// Pass_Statue_t Compare_User()
// {
// 	in8 User_Pass[4] , Statue;
// 	uin8 ID_User ;
// 	in8 Checked_Password[4] ;
// 	// Get ID_User with SPI
// 	
// 	// Get Added_Password With SPI
// 	
// 	
// 	EEPROM_voidReadPage(EEPROM_ADDRESSES[ID_User],User_Pass,PassDigit);
// 	User_Pass[3] = '\0' ;
// 	if(strcmp(User_Pass , Checked_Password))
// 	{
// 		Statue = Pass_False ;
// 	}else
// 	{
// 		Statue = Pass_True ;
// 	}
// 	return Statue ;
// }




// void ADD_User(uin8 User, in8*Added_Password)
// {
// 	EEPROM_voidWritePage(EEPROM_ADDRESSES[User],Added_Password,PassDigit);
// }
// 
// void Delete_User(uin8 User)
// {
// 	EEPROM_voidWritePage(EEPROM_ADDRESSES[User],"000",PassDigit);
// }
// 
// Pass_Statue_t Compare_User(uin8 User , in8*Checked_Password)
// {
// 	in8 User_Pass[4] , Statue;
// 	EEPROM_voidReadPage(EEPROM_ADDRESSES[User],User_Pass,PassDigit);
// 	User_Pass[3] = '\0' ;
// 	if(strcmp(User_Pass , Checked_Password))
// 	{
// 		Statue = Pass_False ;
// 	}else
// 	{
// 		Statue = Pass_True ;
// 	}
// 	return Statue ;
// }

