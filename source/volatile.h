#ifndef _Variable_H_
#define	_Variable_H_



/************************Key_Scan Variable****************/					
extern	volatile			__byte_type 		flag_byte0;
#define flag_keypush 		flag_byte0.bits.b0
#define flag_3s		 		flag_byte0.bits.b1
#define flag_10ms 			flag_byte0.bits.b2


#endif