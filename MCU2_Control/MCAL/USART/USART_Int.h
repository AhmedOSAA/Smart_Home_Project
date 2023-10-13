/*
 * USART_Int.h
 * Created: 9/22/2023 2:59:11 PM
 * Author: Eng. Ahmed Osama
 */ 


#ifndef USART_INT_H_
#define USART_INT_H_

#include "USART_Cfg.h"
#include "USART_Priv.h"

/* APIs */

void USART_Init(S_USARTCfg_t* USART_CFG);

void USART_Transmitter(uin16 DataTx);

void USART_Recevier(uin16* DataRx);

#endif /* USART_INT_H_ */