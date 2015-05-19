//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    sysinit.c
//Targer :       
//MCU :          HT68F40
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  config system
//History : 
//___________________________________________________________________
//___________________________________________________________________
#include "config.h"




volatile unsigned char counter10ms;
volatile unsigned int  counter3s;
extern unsigned char  keyCount;

void _clearRam(void){
	_bp = 0x00;
	_mp1 = 0x80;
		for(_tblp = 0x00;_tblp < 128;_tblp++)
		{
			 _iar1 = 0;
			  _mp1++;
		}
	_bp = 0x01;
	_mp1 = 0x80;		
		for(_tblp = 0x00;_tblp < 64;_tblp++)
		{
			 _iar1 = 0;
			  _mp1++;
		}
	_bp=0x00;
	}

void _reset_init(void){
	_sysinit();
	}

//
void _sysinit(void){
//IO
	_pac=0;
	_pa=0;
	_papu=0xff;
	_pawu=1;
	
	_pbc=0;
	_pb=0;
	_pbpu=0xff;
	
	_pcc=0;
	_pc=0;
	_pcpu=0xff;
	
	_pdc=0;
	_pd=0;
	_pdpu=0xff;
	
	_pec=0;
	_pe=0;
	_pepu=0xff;
	
	_pfc=0;
	_pf=0;
	_pfpu=0xff;	
	
//cp
	_cp0c=0;
	_cp1c=0;	
//Timer
	_tm0c0=0x00;
	_tm0c1=0xc1;
	_tm0al=0xe8;
	_tm0ah=0x03;
	_mf0f=0;
	_mf0e=1;
	_t0ae=1;
	_t0af=0;
	_emi=1;
	_t0on=1;
//Ram
	counter10ms=10;
	counter3s=300;
	keyCount=0;
	flag_byte0.byte=0;
	}
	
DEFINE_ISR(timer0, 0x14){
//	flag_1ms=1;
	counter10ms--;
	if(counter10ms==0){
		flag_10ms=1;
		counter10ms=10;	
		counter3s--;
		if(counter3s==0){
			flag_3s=1;
			counter3s=300;
		}
	}	
	_t0af=0;
}