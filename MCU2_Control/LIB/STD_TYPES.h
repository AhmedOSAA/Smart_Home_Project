/*•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 •                                                                      •
 •••••••••••••••••••••••••  Date    : 9/8/2023        •••••••••••••••••••
 •••••••••••••••••••••••••  Name    : Ahmed Osama     •••••••••••••••••••
 •••••••••••••••••••••••••  Version : 1.0             •••••••••••••••••••
 •••••••••••••••••••••••••  SWC     : STD_TYPES       •••••••••••••••••••
 •                                                                      •
 •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••*/

#ifndef STD_TYPES_
#define STD_TYPES_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES_H.h"

/*•••••••• Datatype_typedef ••••••••*/

typedef char							      in8 ;
typedef unsigned char						 uin8 ;
typedef volatile unsigned char				vuin8 ;

typedef signed short int					  in16;
typedef unsigned short int					 uin16;
typedef volatile unsigned short int         vuin16;

typedef signed long int						  in32;
typedef unsigned long int					 uin32;
typedef volatile unsigned long int			vuin32;


#ifndef NULL
#define NULL							      (0)
#endif /* NULL */

#endif /* STD_TYPES_ */