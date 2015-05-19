#include "config.h"

volatile unsigned char keyCount;

extern unsigned char modecount;
extern unsigned char displayState;

void fun_scan_key(void){
	KEYC=1;//key input mode
	keyold
	if (KEY==0)
	{
		keyCount++;
		if(keyCount==4)
		{
			flag_keypush=1;
			keyCount=0;
		}
	}
	else
	{
		keyCount=0;
	}	
}


void fun_task_key(void){
	if(flag_keypush==1){
		flag_keypush=0;
		switch(displayState){
			case displayState_Hello:
				displayState=displayState_All;
				break;
			case displayState_All:
				displayState=displayState_Bink0;
				_updateDisplayBlink();
				break;
			case displayState_Bink0:
				displayState=displayState_Bink1;
				break;
			case displayState_Bink1:
				displayState=displayState_Normal;
				break;
			case displayState_Normal:
				displayState=displayState_Off;
				break;
			case displayState_Off:
				displayState=displayState_Hello;
				break;
			default:
				break;
		}
	}	
}



