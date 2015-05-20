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
#include "config.h"

volatile unsigned char	displayState;
volatile unsigned char	BinklState;



void main()
{
	if (_to == 0 || _pdf ==0){
		_clearRam();
		_sysinit();
	}
	else{	

	}
	//power on Display hello
	_init_led();
	_updateDisplayHello();
	while(1){
		if(flag_10ms==1){
			fun_scan_key();
			fun_task_key();	
			flag_10ms=0;	
			switch(displayState){
				case displayState_Hello:				
					_updateDisplayHello();
					break;
				case displayState_All:
					_updateDisplayAll();
					break;			
//				case displayState_Off:
//					_updateDisplayoff();
//					break;			
//				case displayState_Bink0:
//					break;			
//				case displayState_Bink1:
//					break;
//				case displayState_Normal:
//					_updateDisplayNormal();
/*					break;	*/				
				default:
					break;	
			}		
		}
		if (flag_3s==1 && displayState==displayState_Bink1)
		{
			flag_3s=0;
			if (BinklState==BinkState_All)
			{
				BinklState=BinkState_Off;
				//_updateDisplayoff();
				iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_OFF);
				iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_DIS_LED_OFF);
			}
			else if (BinklState==BinkState_Off)
			{
				BinklState=BinkState_All;
				//_updateDisplayAll();
				iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
				iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
			}
		}
		GCC_CLRWDT();
		GCC_CLRWDT1();
		GCC_CLRWDT2();	
	}		

}