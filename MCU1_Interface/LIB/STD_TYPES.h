#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#include "AVR_delay_Handling.h"
#include <stdint.h>
/*
 * Signed Data Types

 */
typedef unsigned char           U8;
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;

/*
 * Unsigned Data Types
 */
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;

/*
 * Floating point Types
 */
typedef float                   f32;
typedef double                  f64;

/*
 * Address NULL
 */

typedef char							      in8 ;
typedef unsigned char						 uin8 ;
typedef volatile unsigned char				vuin8 ;

typedef signed short int					  in16;
typedef unsigned short int					 uin16;
typedef volatile unsigned short int         vuin16;

typedef signed long int						  in32;
typedef unsigned long int					 uin32;
typedef volatile unsigned long int			vuin32;

#define ADDRESS_NULL ( (void *) 0x00)
#define NULL		0

#endif /* _STD_TYPES_H */
