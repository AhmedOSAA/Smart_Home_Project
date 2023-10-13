/* Inclusion */
#include "DIO_Priv.h"
#include "DIO_int.h"

volatile U8 *PTR_DDR[4]={&MCAL_DDRA,&MCAL_DDRB,&MCAL_DDRC,&MCAL_DDRD};
volatile U8 *PTR_PORT[4]={&MCAL_PORTA,&MCAL_PORTB,&MCAL_PORTC,&MCAL_PORTD};
volatile U8 *PTR_PIN[4]={&MCAL_PINA,&MCAL_PINB,&MCAL_PINC,&MCAL_PIND};
void MCAL_DIOVoidChannelMode(U8 A_U8Port,U8 A_U8Direction){
	if(A_U8Direction==INPUT_FLOATING){
		SET_BIT(MCAL_SFIOR,2);}
	else{
		CLR_BIT(MCAL_SFIOR,2);}
	switch(A_U8Port/8){
	case 0: WRT_BIT(MCAL_DDRA,(A_U8Port%8),(A_U8Direction%2)); break;
	case 1: WRT_BIT(MCAL_DDRB,(A_U8Port%8),(A_U8Direction%2)); break;
	case 2: WRT_BIT(MCAL_DDRC,(A_U8Port%8),(A_U8Direction%2)); break;
	case 3: WRT_BIT(MCAL_DDRD,(A_U8Port%8),(A_U8Direction%2)); break;
	default: break;
	}
}
void MCAL_DIOWriteChannel(U8 A_U8Port,U8 A_U8Value){
	switch(A_U8Port/8){
	case 0: WRT_BIT(MCAL_PORTA,(A_U8Port%8),A_U8Value); break;
	case 1: WRT_BIT(MCAL_PORTB,(A_U8Port%8),A_U8Value); break;
	case 2: WRT_BIT(MCAL_PORTC,(A_U8Port%8),A_U8Value); break;
	case 3: WRT_BIT(MCAL_PORTD,(A_U8Port%8),A_U8Value); break;
	default: break;
	}
}
void MCAL_DIOToggelChannel(U8 A_U8Port){
	switch(A_U8Port/8){
		case 0: TOG_BIT(MCAL_PORTA,(A_U8Port%8)); break;
		case 1: TOG_BIT(MCAL_PORTB,(A_U8Port%8)); break;
		case 2: TOG_BIT(MCAL_PORTC,(A_U8Port%8)); break;
		case 3: TOG_BIT(MCAL_PORTD,(A_U8Port%8)); break;
		default: break;
		}
}
void MCAL_DIOReadChannel(U8 A_U8Port,U8 *A_U8PtrBuffer){
	switch(A_U8Port/8){
		case 0:*A_U8PtrBuffer=GET_BIT(MCAL_PINA,A_U8Port%8); break;
		case 1:*A_U8PtrBuffer=GET_BIT(MCAL_PINB,A_U8Port%8); break;
		case 2:*A_U8PtrBuffer=GET_BIT(MCAL_PINC,A_U8Port%8); break;
		case 3:*A_U8PtrBuffer=GET_BIT(MCAL_PIND,A_U8Port%8); break;
		default: break;
		}
}
void MCAL_DIOReadPort(U8 A_U8Port,U8 *A_U8PtrBuffer){
	switch(A_U8Port){
		case 0:*A_U8PtrBuffer=GET_PORT(MCAL_PINA); break;
		case 1:*A_U8PtrBuffer=GET_PORT(MCAL_PINB); break;
		case 2:*A_U8PtrBuffer=GET_PORT(MCAL_PINC); break;
		case 3:*A_U8PtrBuffer=GET_PORT(MCAL_PIND); break;
		default: break;
		}
}
void MCAL_DIOWritePort(U8 A_U8Port,U8 A_U8Value){
	switch(A_U8Port){
	case 0: WRT_PORT(MCAL_PORTA,A_U8Value); break;
	case 1: WRT_PORT(MCAL_PORTB,A_U8Value); break;
	case 2: WRT_PORT(MCAL_PORTC,A_U8Value); break;
	case 3: WRT_PORT(MCAL_PORTD,A_U8Value); break;
	default: break;
	}
}
void MCAL_SetPinMode(U8 A_U8PIN, U8 A_U8MODE){
	U8 L_U8DetectPort=A_U8PIN/8;
	U8 L_U8DetectPin=A_U8PIN%8;
	switch(A_U8MODE){
	case OUTPUT_HIGH:
		SET_BIT(*PTR_DDR[L_U8DetectPort],L_U8DetectPin);
		SET_BIT(*PTR_PORT[L_U8DetectPort],L_U8DetectPin); break;
	case OUTPUT_LOW:
		SET_BIT(*PTR_DDR[L_U8DetectPort],L_U8DetectPin);
		CLR_BIT(*PTR_PORT[L_U8DetectPort],L_U8DetectPin); break;
	case INPUT_PULLUP:
		//CLR_BIT(MCAL_SFIOR,2);
		CLR_BIT(*PTR_DDR[L_U8DetectPort],L_U8DetectPin);
		SET_BIT(*PTR_PORT[L_U8DetectPort],L_U8DetectPin); break;
	case INPUT_FLOATING:
		CLR_BIT(*PTR_DDR[L_U8DetectPort],L_U8DetectPin);
		SET_BIT(MCAL_SFIOR,2);break;
	default: break;
	}
}

void MCAL_DIOInit(void){
	for(U8 i=0;i<32;i++){
		//MCAL_SetPinMode(i,MCAL_DIO_INIT[i]);
	}
}

