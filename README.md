# Smart_Home_Project

##Project description:

### The Project has two Mode Admin & User:
	Admin mode: The admin can add or delete Users Up to 10 users.
	User Mode: The User can control on all Electrical devices at home like:
			- The door
			- Fans
			- Air-conditions
			- The light system for all rooms
			- Control on home with Bluetooth " In simulation using terminal "
__________________________________________________________________________________________________
### the Project consists of Two MCU (ATMega32):

####First Controller 'Interface':
- Connecting with EEPROM by I2C for adding Users Passwords.
- Connecting with LCD & Keypad for interfacing with admin or user.
- Connecting with Bluetooth Module using USART Protocol “Interrupt" for interfacing with admin or user.
- Connecting with Other Controller using SPI Protocol as a master "Polling".


####Second Controller 'Control’:
- Connecting with Other Controller using SPI Protocol as a slave "Interrupt".
- Connecting with Electrical Devices at home.
- Controlling in Servo with TIMER_1 Mode (14 .
- Reading Analog signal "ADC0 "from Temperature Sensor and Control in Air Condition and Firefighting system.
		• if T > 25 >> AirC ON
		• if T < 18 >> AirC OFF
		• if T > 25 >> Firefighting system "Pump & Bazzer & LED Alarm" ON 
		• if T > 25 >> Firefighting system "Pump & Bazzer & LED Alarm" OFF

#### Simulation Video Click here :
---
![image](https://github.com/AhmedOSAA/Smart_Home_Project/blob/main/Smart_Home_Project_Schematic.jpg)(https://github.com/AhmedOSAA/Smart_Home_Project/blob/main/Smart_Home_Simu_Video.mp4)
---
