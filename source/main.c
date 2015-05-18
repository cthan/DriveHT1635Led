//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    MAIN.C
//Targer :       
//MCU :          HT68F40
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  MAIN function
//History : 
//___________________________________________________________________
//___________________________________________________________________
/*#include "HT68F40.h"*/
#include "config.h"


unsigned char poweron = 0;
unsigned char flag_10ms = 0;

void main()
{
	if (_to == 0 || _pdf ==0)
	{
//		ram_init();
//		sys_init();
//		poweron_init();
	}
	else
	{	
//		reset_init();
	}
	init_led();
	updateDisplayHello();
	while(1)
	{
		if (flag_10ms==1)
		{
			fun_scan_key();
		}
	}		

}