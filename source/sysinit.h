//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    sysinit.C
//Targer :       
//MCU :          HT68F40
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  config sysinit function
//History : 
//___________________________________________________________________
//___________________________________________________________________
#ifndef _SYSINIT_H
#define _SYSINIT_H

#define RambankMaxSector	2

void _clearRam(void);
void _sysinit(void);
void _reset_init(void);




#endif