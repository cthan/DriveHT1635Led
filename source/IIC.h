//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    IIC.h
//Targer :       
//MCU :          HT64F50
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  config IIC function
//History : 
//___________________________________________________________________
//___________________________________________________________________
#ifndef _IIC_H
#define _IIC_H
#include "HT68F40.h"

void iicSendCommand(unsigned char address, unsigned char command,unsigned char commandData);
void iicStart(void);
void iicStop(void);
void Ack(void);
void NoAck(void);
unsigned char TestAck(void);
void iicWrite(unsigned char Data);
unsigned char iicRead(void);
void _delay(void);



#define SLAVEMCU1ADD 	0xD6
#define SLAVEMCU2ADD	0xD4 
#define SDA				_pa6
#define SCL				_pa7
#define SDAC			_pac6
#define SCLC			_pac7


#endif