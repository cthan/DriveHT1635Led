#ifndef _config_H
#define _config_H






/************************Type Defination*****************/
	
	typedef unsigned char		BOOL;
	typedef unsigned char		U8;
	typedef unsigned int		U16;
	typedef unsigned long		U32;
	typedef char				S8;
	typedef int					S16;
	typedef long				S32;							

	#define FALSE				0
	#define TRUE				1
	#define NULL				0
	
	typedef unsigned char __1_byte;
	typedef struct {
	    unsigned char b0:1;
	    unsigned char b1:1;
	    unsigned char b2:1;
	    unsigned char b3:1;
	    unsigned char b4:1;
	    unsigned char b5:1;
	    unsigned char b6:1;
	    unsigned char b7:1;
	} __8_bits;
	typedef union {
	    __8_bits bits;
	    __1_byte byte;
	} __byte_type;



#include "HT68F40.h"
#include "IIC.h"
#include "LedDisplay.h"
#include "sysinit.h"
#include "funscankey.h"
#include "volatile.h"

#endif