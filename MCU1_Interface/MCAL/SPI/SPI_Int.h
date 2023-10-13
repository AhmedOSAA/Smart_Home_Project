/*
 * SPI_Int.h
 *
 * Created: 9/23/2023 12:04:50 PM
 *  Author: midom
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

#include "SPI_Cfg.h"


//=======================================
//***************  APIs  ****************
//=======================================

void SPI_Init (S_SPICfg_t* CONFIG);
void SPI_DeInit (void);
uin8 SPI_SendData (uin8 Data);
uin8 SPI_ReveiveData (uin8 DataTOsend);



#endif /* SPI_INT_H_ */