/*
 * Smart_Home_Interface.c
 * Created: 10/11/2023 8:56:50 AM
 * Author : 
			ENG. Hadeer Ihab
			ENG. Afnan Talaat
			ENG. Moaz Adel
			Eng. Ahmed Osamaa
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "GIE_Int.h"
#include "EEPROM_Int.h"
#include "TWI_Int.h"
#include "SPI_Int.h"
#include "HLCD_Int.h"
#include "HKPD_Int.h"
#include "USART_Int.h"
#include "SPI_Int.h"
#include <string.h>

/* Terminal Function & Variables */

void Terminal_Handling();
/**/
void Rx_ISR();
uin8 Control_Condition ;
in8 st_Re[5]={0} ;
in8 admin_Pass[3] = { 1,1,1 };
/**/

/**/

#define ADD_USER 2
#define REMOVE_USER 3
#define MISO PORTB6
#define MOSI PORTB5
#define SCK PORTB7
#define BUZZER PORTA0

u16 EEPROM_ADDRESSES[10]={ 210 , 220 , 240 , 250 , 260 , 272 , 280 , 288 , 296 , 312 };
U8 counter=0;

/*operations*/

#define Open_Door		1
#define Close_Door		2
#define AirC_On			3
#define AirC_Off		4
#define Light_Sys		5

#define All_Light_On	1
#define All_Light_Off	2
#define Contrast		3
#define Rooms			4
#define Room_1_on			1
#define Room_1_off			2
#define Room_2_on			3
#define Room_2_off			4
#define Room_3_on			5
#define Room_3_off			6


/**/

#define PassDigit			4

typedef enum
{
	Pass_False = 0 ,
	Pass_True = 1
}Pass_Statue_t;

void Delete_User(u16 ID_User );
void LogIN_Init(void)
{
	uin8 i ;
	EXTEEPROM_VoidInit();
	for(i = 0 ; i<10 ; i++)
	{
		Delete_User(i);
	}
}


void ADD_User(u16 ID_User ,in8* Added_Password)
{
	EXTEEPROM_VoidWritePage(EEPROM_ADDRESSES[ID_User],Added_Password,PassDigit);
}

void Delete_User(u16 ID_User )
{
	EXTEEPROM_VoidWritePage(EEPROM_ADDRESSES[ID_User],"$$$",PassDigit);
}

Pass_Statue_t Compare_User(u16 ID_User,in8 Checked_Password[4])
{
	in8 User_Pass[4], Statue = 3 ;

	EXTEEPROM_VoidReadPage(EEPROM_ADDRESSES[ID_User],User_Pass,PassDigit);

	if(strcmp(User_Pass , Checked_Password))
	{
		Statue = Pass_False ;
	}else
	{
		Statue = Pass_True ;
	}
	return Statue ;
}


int main()
{
	HKPD_VoidInit();
	LCD_voidInit()	;
	TWI_VoidInitMstr(0xff);
	LogIN_Init();
//	EXTEEPROM_VoidInit();

	/* UART Configurations */

	MCAL_SetPinMode(PORTD0, INPUT_FLOATING);
	MCAL_SetPinMode(PORTD1, OUTPUT_LOW);

	S_USARTCfg_t U_Cfg ;
	U_Cfg.USART_Role = USART_Role_Tx_Rx ;
	U_Cfg.USART_Interrupt = USART_Interrupt_Rx ;
	U_Cfg.MODE = USART_MODE_ASYNC ;
	U_Cfg.Parity = USART_Parity_DISABLE ;
	U_Cfg.Stop_BIT = USART_STOP_1BIT ;
	U_Cfg.Data_Size = USART_Data_8BIT ;
	U_Cfg.CLK_Polarity = USART_polarity_DISABLE ;
	U_Cfg.Baud_Rate = USART_BaudRate_9600 ;
	U_Cfg.Speed = USART_Speed_Normal ;

	U_Cfg.RXC_CALLBACK  = Rx_ISR  ;
	U_Cfg.TXC_CALLBACK  = NULL  ;
	U_Cfg.UDRE_CALLBACK = NULL  ;

	USART_Init(&U_Cfg);

	Terminal_Handling();

	/**/


	// SPI Config

	MCAL_SetPinMode(SCK, OUTPUT_LOW);
	MCAL_SetPinMode(MOSI, OUTPUT_LOW);
	MCAL_SetPinMode(MISO, INPUT_FLOATING);
	MCAL_SetPinMode(PORTB4, OUTPUT_LOW);


	S_SPICfg_t SPI_Cfg ;

	SPI_Cfg.SPI_EN = SPI_Enable ;
	SPI_Cfg.MODE = SPI_Mode_Master ;
	SPI_Cfg.DataORD = SPI_DataORD_LSB ;
	SPI_Cfg.Data_Mode = SPI_DataMode_Leading_RisingSample ;
	SPI_Cfg.Clock_Rate = SPI_Clock_Divide_4 ;
	SPI_Cfg.Interrupt_EN = SPI_Interrupt_Disable ;
	SPI_Cfg.SPI_CALLBACK = NULL ;

	SPI_Init(&SPI_Cfg);

	/**/
	/* Global Interrupt Enable */
	GIE_voidEnable();
	/**/

	//u8 NOTUSED[5]={0};
	u8 READ_KEYPAD=80;
	in8 password[4];					// 4 for null at the end
	u8 admin_password[3]={1,1,1};
	u8 admin_entry[3]={0,0,0};
	u8 digit_counter=0;
	u8 Admin_Error_counter=0;
	U8 ID=0;
	u8 true=1;
	u8 admin_password_counter=0;
	u8 admin_password_verify=0;

	u8 USER_ID = 0 ;
	in8 USER_ENTRY_PASS[4];
	u8 USER_password_counter = 0;
	u8 USER_Error_counter = 0;
	u8 Select_Operation = 0;

	while(1){
		line1:
		admin_password_counter=0;
		admin_password_verify=0;

		LCD_voidClear();
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidWriteString(" 1:Admin");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidWriteString(" 2:User");
		line4:
		READ_KEYPAD=80;
		READ_KEYPAD=HKPD_GetPressedKey();
		if(READ_KEYPAD!=80){
			switch(READ_KEYPAD){
				case 1: LCD_voidClear(); goto line9; break;   //admin function
				case 2: LCD_voidClear(); goto line3; break;   // user function
				default:  break;
			}
		}
		goto line4;
		line9:
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidWriteString(" Enter password");
		LCD_voidGoToSpecificPosition(1,0);
		while(true){
			READ_KEYPAD=HKPD_GetPressedKey();
			if(READ_KEYPAD!=80){
				admin_entry[admin_password_counter]=READ_KEYPAD;
				LCD_voidGoToSpecificPosition(1,admin_password_counter);
				LCD_voidSendChar('*');
				admin_password_counter++;
				if(admin_password_counter<3){goto line9;}
				else{true=0; goto line8;}
			}
		}
		//verify admin password
		line8:
		for(u8 i=0;i<3;i++){
			if(admin_entry[i]==admin_password[i]){
				admin_password_verify++;
			}
		}
		if(admin_password_verify==3){
			goto line2;
		}
		else {
			Admin_Error_counter++;
			if(Admin_Error_counter==3)
			{
				MCAL_SetPinMode(BUZZER,OUTPUT_HIGH)	;
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString("thief!!!!             ");
				LCD_voidGoToSpecificPosition(1,0);
				LCD_voidWriteString("                       ");
				_delay_ms(4000);
				goto line1;
			}
			admin_password_counter=0;
			admin_password_verify=0;
			LCD_voidGoToSpecificPosition(0,0);
			LCD_voidWriteString("wrong password        ");
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidWriteString("try again             ");
			true=1;
			_delay_ms(100);
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidWriteString("                        ");

			//_delay_ms(500);

		goto line9;}
		line2:
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidWriteString("select 1:Add user       ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidWriteString("select 2:Remove user     ");
		READ_KEYPAD=80;
		READ_KEYPAD=HKPD_GetPressedKey();
		if(READ_KEYPAD!=80){
			switch(READ_KEYPAD){
				case 1:
				LCD_voidClear();
				line7:
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString("Enter ID            ");
				ID=HKPD_GetPressedKey();
				if(ID!=80){
					LCD_voidGoToSpecificPosition(1,0);
					LCD_voidWriteNumber(ID);
					_delay_ms(3);
					LCD_voidGoToSpecificPosition(1,0);
					LCD_voidWriteString("                         ");
					goto line6;
				}
				else{goto line7;}
				line6:

				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString("Enter Password          ");

				READ_KEYPAD=HKPD_GetPressedKey();
				if(READ_KEYPAD!=80)
				{
					if(READ_KEYPAD == 15){digit_counter=0; goto line10;}
					if(digit_counter<3)
					{
						password[digit_counter]=READ_KEYPAD;
						LCD_voidGoToSpecificPosition(1,digit_counter);
						LCD_voidSendChar('*');
						digit_counter++;
					}
					else{goto line6;}
				}
				goto line6;
				line10:
				password[3] = 0 ;
				// NULL
				ADD_User(ID,password);
				_delay_ms(3);
				goto line1;
				break;
				case 2:

				line13:
				LCD_voidClear();
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString(" Enter ID            ");
				ID=80;
				ID=HKPD_GetPressedKey();
				if(ID!=80){
					LCD_voidGoToSpecificPosition(1,1);
					LCD_voidWriteNumber(ID);
					goto line12;
				}
				else{goto line13;}
				line12:
				Delete_User(ID);
				goto line1;
				break;
				default:  break;
			}
		}
		else goto line2;

		/**************************************************/
		/***    USER Interface ***/
		line3:

		READ_KEYPAD = 80 ;
		LCD_voidClear();
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidWriteString(" Enter ID:  ");
		while(READ_KEYPAD == 80)
		{
			READ_KEYPAD=HKPD_GetPressedKey();
		}
		USER_ID = READ_KEYPAD ;
		LCD_voidGoToSpecificPosition(0,12);
		LCD_voidWriteNumber(READ_KEYPAD);
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidWriteString(" Enter password: ");
		true = 1 ;
		while(true)
		{
			READ_KEYPAD=HKPD_GetPressedKey();
			if(READ_KEYPAD!=80)
			{
				LCD_voidSendChar('*');
				USER_ENTRY_PASS[USER_password_counter] = READ_KEYPAD ;
				USER_password_counter++;
				if(USER_password_counter==3)
				{
					// Compare with EEPROM
					if(Compare_User(USER_ID ,USER_ENTRY_PASS))
					{
						USER_Error_counter = 0 ;
						USER_password_counter = 0 ;
						break;
					}else
					{
						USER_Error_counter++ ;
					}
					if(USER_Error_counter == 3)
					{
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Access Failed !!! ");
						LCD_voidGoToSpecificPosition(1,0);
						LCD_voidWriteString(" Anta men ya 3m Anta!!");
						// Set ALarm
						MCAL_SetPinMode(BUZZER,OUTPUT_HIGH)	;
						LCD_voidGoToSpecificPosition(2,0);
						LCD_voidWriteString("thief!!!!             ");
						_delay_ms(1000);
						USER_Error_counter = 0 ;
						USER_password_counter = 0 ;
						goto line1;

					}else
					{
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Wrong Password ! ");
						LCD_voidGoToSpecificPosition(1,0);
						LCD_voidWriteString(" Try Again ");
						_delay_ms(500);
						USER_password_counter = 0 ;
						goto line3;
					}
				}
			}
		}
		LCD_voidClear();
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidWriteString(" Welcome ");
		_delay_ms(250);
		while(true)
		{
			line50:
			LCD_voidClear();
			LCD_voidGoToSpecificPosition(0,0);
			LCD_voidWriteString(" Operation Select");
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidWriteString("1-DoorON   2-DoorOff");
			LCD_voidGoToSpecificPosition(2,0);
			LCD_voidWriteString("3-AC On    4-AC Off");
			LCD_voidGoToSpecificPosition(3,0);
			LCD_voidWriteString("5-LightSys 6-Exit");
			READ_KEYPAD = 80 ;
			while(READ_KEYPAD == 80)
			{
				READ_KEYPAD=HKPD_GetPressedKey();
			}
			Select_Operation = READ_KEYPAD;
			switch(Select_Operation)
			{
				case Open_Door :

				SPI_SendData (Open_Door);

				LCD_voidClear();
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString(" Door is opened ");
				_delay_ms(250);
				Select_Operation = 0 ;
				break;

				case Close_Door :
				SPI_SendData (Close_Door);
				LCD_voidClear();
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString(" Door is Closed ");
				_delay_ms(250);
				Select_Operation = 0 ;
				break;

				case AirC_On :
				SPI_SendData (AirC_On);
				LCD_voidClear();
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString(" Air Con. is opened ");
				_delay_ms(250);
				Select_Operation = 0 ;
				break;

				case AirC_Off :
				SPI_SendData (AirC_Off);
				LCD_voidClear();
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString(" Air Con. is closed ");
				_delay_ms(250);
				Select_Operation = 0 ;
				break;

				case 6 :
				Select_Operation = 0 ;
				goto line1 ;
				break;

				case Light_Sys :
				line60:
				LCD_voidClear();
				LCD_voidGoToSpecificPosition(0,0);
				LCD_voidWriteString("Light_Sys: 5-Main");
				LCD_voidGoToSpecificPosition(1,0);
				LCD_voidWriteString("1-All Lights On");
				LCD_voidGoToSpecificPosition(2,0);
				LCD_voidWriteString("2-All Lights Off");
				LCD_voidGoToSpecificPosition(3,0);
				LCD_voidWriteString("3-Contrast 4-Rooms ");
				READ_KEYPAD = 80 ;
				while(READ_KEYPAD == 80)
				{
					READ_KEYPAD=HKPD_GetPressedKey();
				}
				Select_Operation = READ_KEYPAD;
				switch(Select_Operation)
				{
					case All_Light_On :
					SPI_SendData ((All_Light_On + 5));
					LCD_voidClear();
					LCD_voidGoToSpecificPosition(0,0);
					LCD_voidWriteString(" All lights on ");
					_delay_ms(250);
					Select_Operation = 0 ;
					break;
					case 5 :
					Select_Operation = 0 ;
					goto line50 ;
					break;
					case All_Light_Off :
					SPI_SendData ((All_Light_Off + 5));
					LCD_voidClear();
					LCD_voidGoToSpecificPosition(0,0);
					LCD_voidWriteString(" All lights off ");
					_delay_ms(250);
					Select_Operation = 0 ;
					break;
					case Contrast :
					SPI_SendData ((Contrast + 5));
					LCD_voidClear();
					LCD_voidGoToSpecificPosition(0,0);
					LCD_voidWriteString(" Contrast Control ");
					_delay_ms(250);
					Select_Operation = 0 ;
					break;
					case Rooms :
					LCD_voidClear();
					LCD_voidGoToSpecificPosition(0,0);
					LCD_voidWriteString(" Rooms Light: 7-Main");
					LCD_voidGoToSpecificPosition(1,0);
					LCD_voidWriteString("1-R1_On  2-R1_Off");
					LCD_voidGoToSpecificPosition(2,0);
					LCD_voidWriteString("3-R2_On  4-R2_Off");
					LCD_voidGoToSpecificPosition(3,0);
					LCD_voidWriteString("5-R3_On  6-R3_Off");
					READ_KEYPAD = 80 ;
					while(READ_KEYPAD == 80)
					{
						READ_KEYPAD=HKPD_GetPressedKey();
					}
					Select_Operation = READ_KEYPAD;
					switch(Select_Operation)
					{
						case Room_1_on :
						SPI_SendData ((Room_1_on + 9));
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Room 1 light on  ");
						break;
						case Room_1_off :
						SPI_SendData ((Room_1_off + 9));
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Room 1 light off  ");
						break;
						case Room_2_on :
						SPI_SendData ((Room_2_on + 9));
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Room 2 light on  ");
						break;
						case Room_2_off :
						SPI_SendData ((Room_2_off + 9));
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Room 2 light off  ");
						break;
						case Room_3_on :
						SPI_SendData ((Room_3_on + 9));
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Room 3 light on  ");
						break;
						case Room_3_off :
						SPI_SendData ((Room_3_off + 9));
						LCD_voidClear();
						LCD_voidGoToSpecificPosition(0,0);
						LCD_voidWriteString(" Room 3 light off  ");
						break;
						case 7 :
						Select_Operation = 0 ;
						goto line60 ;
						break;
					}
					_delay_ms(250);
					Select_Operation = 0 ;
					break;
				}
				_delay_ms(250);
				Select_Operation = 0 ;
				break;
			}
		}
	}
}



/* UART Receive interrupt from terminal */


void Rx_ISR()
{
	static uin8 i = 0 ;
	USART_Recevier((in16*)&st_Re[i]);
	if (st_Re[i] == Enter )
	{
		/*Put null in string*/
		st_Re[i] = 0 ;
		/*Reset String*/
		i = 0;
		/*Your Operation*/

		/* convert to num */
		st_Re[0] -= '0' ;
		st_Re[1] -= '0' ;
		st_Re[2] -= '0' ;

		Control_Condition = st_Re[0] ;
		Terminal_Handling();

	}else
	{
		i++;
	}
}

/**/

/* Terminal Function */
void Terminal_Handling()
{
	static uin8 stage = 0 , Admin_control_operation = 0 , ID = 0;
	if(stage == 0)
	{
		switch(Control_Condition)
		{
			case 0 :
			break;
			case 1 :
			USART_TransmitterString("\rEnter Admin Password :\r");
			stage = 4 ;
			Admin_control_operation = 5 ;
			break;
			case 2 :
			USART_TransmitterString("\rEnter ID\r");
			stage = 4 ;
			Admin_control_operation = 3 ;
			break;
		}
	}else if(stage == 1)
	{

		switch(Control_Condition)
		{
			case 0 :
			break;

			case 1 :
			// ADD USER
			USART_TransmitterString("\rEnter ID\r");
			stage = 4 ;
			Admin_control_operation = 0 ;
			break;

			case 2 :
			// DELETE USER
			USART_TransmitterString("\rEnter ID\r");
			stage = 4 ;
			Admin_control_operation = 2 ;
			break;

			case 3:
			// Go main
			stage = 0 ;
			break;
		}
	}else if(stage == 2)
	{
		// "\rUser Mode :\r1- Open Door\r2- Close Door\r3- AirC ON\r4- AirC OFF\r5- All Lights ON\r6- All lights Off\r7- Rooms\r"
		switch(Control_Condition)
		{
			case 0 :
			break;

			case 1 :
			// Open Door
			SPI_SendData (Open_Door);
			USART_TransmitterString("\rDoor is Opened.\r");
			break;

			case 2 :
			// Close Door
			SPI_SendData (Close_Door);
			USART_TransmitterString("\rDoor is Closed.\r");
			break;

			case 3 :
			// AirC ON
			SPI_SendData (AirC_On);
			USART_TransmitterString("\rAirC ON is ON.\r");
			break;

			case 4 :
			// AirC OFF
			SPI_SendData (AirC_Off);
			USART_TransmitterString("\rAirC ON is OFF.\r");
			break;

			case 5 :
			// 5- All Lights ON
			SPI_SendData ((All_Light_On + 5));
			USART_TransmitterString("\rAll Lights ON is Done.\r");
			break;

			case 6 :
			// All lights Off
			SPI_SendData ((All_Light_Off + 5));
			USART_TransmitterString("\rAll lights Off is Done.\r");
			break;

			case 7 :
			// Rooms
			stage = 3 ;
			//USART_TransmitterString("\r1- R1 ON\r2- R1 OFF\r3- R2 ON\r4- R2 OFF\r5- R3 ON\r6- R3 OFF\r");
			break;

			case 8 :
			// Main
			stage = 0 ;
			//USART_TransmitterString("\r1- R1 ON\r2- R1 OFF\r3- R2 ON\r4- R2 OFF\r5- R3 ON\r6- R3 OFF\r");
			break;
		}
	}else if(stage == 3)
	{

		switch(Control_Condition)
		{
			case 0 :
			break;

			case 1 :
			//  R1 ON
			SPI_SendData ((Room_1_on + 9));
			USART_TransmitterString("\rRoom 1 Light ON\r");
			break;

			case 2 :
			//  R1 OFF
			SPI_SendData ((Room_1_off + 9));
			USART_TransmitterString("\rRoom 1 Light OFF\r");
			break;

			case 3 :
			// R2 ON
			SPI_SendData ((Room_2_on + 9));
			USART_TransmitterString("\rRoom 2 Light ON\r");
			break;

			case 4 :
			//  R2 OFF
			SPI_SendData ((Room_2_off + 9));
			USART_TransmitterString("\rRoom 2 Light OFF\r");
			break;

			case 5 :
			//  R3 ON
			SPI_SendData ((Room_3_on + 9));
			USART_TransmitterString("\rRoom 3 Light ON\r");
			break;

			case 6 :
			//  R3 OFF
			SPI_SendData ((Room_3_off + 9));
			USART_TransmitterString("\rRoom 3 Light OFF\r");
			break;
			case 7 :
			//  Back
			stage = 2;
			break;
		}
	}else if (stage == 4)
	{
		switch(Admin_control_operation)
		{
			case 0 :
			ID = Control_Condition;
			USART_TransmitterString("\rEnter Password : \r");
			Admin_control_operation = 1 ;
			break;

			case 1 :
			// ADD User
			ADD_User(ID,st_Re);
			USART_TransmitterString("\rUser is added.\r");
			stage = 1 ;
			break;

			case 2 :
			// Delete User
			ID = Control_Condition;
			Delete_User(ID);
			USART_TransmitterString("\rUser is deleted.\r");
			stage = 1 ;
			break;

			case 3 :
			ID = Control_Condition;
			USART_TransmitterString("\rEnter Password : \r");
			Admin_control_operation = 4 ;
			break;

			case 4 :
			// compare User
			if(Compare_User(ID ,st_Re))
			{
				_delay_ms(3);
				USART_TransmitterString("\rLog in Success\r\r");
				stage = 2 ;
			}else
			{
				_delay_ms(3);
				USART_TransmitterString("\rPassword is wrong\r");
				stage = 0 ;
			}
			break;

			case 5 :
			if (st_Re[0] == admin_Pass[0] && st_Re[1] == admin_Pass[1] && st_Re[2] == admin_Pass[2] )
			{
				USART_TransmitterString("\rLog in Success\r\r");
				stage = 1 ;
			}else
			{
				USART_TransmitterString("\rPassword is wrong\r");
				stage = 0 ;
			}
			break;
		}
	}

	if(stage == 0)
	{
		USART_TransmitterString("1- Admin\r2- User\r");
	}else if (stage == 1)
	{
		USART_TransmitterString("\rAdmin Mode :\r1- Add User\r2- Delete User\r3- Go main\r");
	}else if (stage == 2)
	{
		USART_TransmitterString("\rUser Mode :\r1- Open Door\r2- Close Door\r3- AirC ON\r4- AirC OFF\r5- All Lights ON\r6- All lights Off\r7- Rooms\r8- Go main\r"); // 7- R1 ON\r8- R1 OFF\r7- R2 ON\r7- R2 OFF\r7- R3 ON\r7- R3 OFF\r
	}else if (stage == 3)
	{
		USART_TransmitterString("\r1- R1 ON\r2- R1 OFF\r3- R2 ON\r4- R2 OFF\r5- R3 ON\r6- R3 OFF\r7- Back\r");
	}
}

/**/




/*
int main(void)
{
    
	
    while (1) 
    {
    }
}
*/
