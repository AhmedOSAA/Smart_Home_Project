/*
 * DIO_Cfg.h
 * Created: 9/8/2023 11:27:42 AM
 * Author: ENG.Ahmed Osama
 */ 

#include "STD_TYPES.h"

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/* •••••••• Pin configuration ••••••••
@ref : PIN_Define
#define PIN_Output_LoW			0x1
#define PIN_Output_High			0x3
#define PIN_Input				0x0
#define PIN_Input_PU			0x2 */

/* DIOA */
#define PA0_cfg					PIN_Input
#define PA1_cfg					PIN_Input
#define PA2_cfg					PIN_Input
#define PA3_cfg					PIN_Input
#define PA4_cfg					PIN_Input
#define PA5_cfg					PIN_Input
#define PA6_cfg					PIN_Input
#define PA7_cfg					PIN_Input

/* DIOB */
#define PB0_cfg					PIN_Input
#define PB1_cfg					PIN_Input
#define PB2_cfg					PIN_Input
#define PB3_cfg					PIN_Input
#define PB4_cfg					PIN_Input
#define PB5_cfg					PIN_Input
#define PB6_cfg					PIN_Input
#define PB7_cfg					PIN_Input

/* DIOC */
#define PC0_cfg					PIN_Input
#define PC1_cfg					PIN_Input
#define PC2_cfg					PIN_Input
#define PC3_cfg					PIN_Input
#define PC4_cfg					PIN_Input
#define PC5_cfg					PIN_Input
#define PC6_cfg					PIN_Input
#define PC7_cfg					PIN_Input

/* DIOD */
#define PD0_cfg					PIN_Input
#define PD1_cfg					PIN_Input
#define PD2_cfg					PIN_Input
#define PD3_cfg					PIN_Input
#define PD4_cfg					PIN_Input
#define PD5_cfg					PIN_Input
#define PD6_cfg					PIN_Input
#define PD7_cfg					PIN_Input

uin8 PA_arr[8] = {PA0_cfg,PA1_cfg,PA2_cfg,PA3_cfg,PA4_cfg,PA5_cfg,PA6_cfg,PA7_cfg};
uin8 PB_arr[8] = {PB0_cfg,PB1_cfg,PB2_cfg,PB3_cfg,PB4_cfg,PB5_cfg,PB6_cfg,PB7_cfg};
uin8 PC_arr[8] = {PC0_cfg,PC1_cfg,PC2_cfg,PC3_cfg,PC4_cfg,PC5_cfg,PC6_cfg,PC7_cfg};
uin8 PD_arr[8] = {PD0_cfg,PD1_cfg,PD2_cfg,PD3_cfg,PD4_cfg,PD5_cfg,PD6_cfg,PD7_cfg};
	
#endif /* DIO_CFG_H_ */