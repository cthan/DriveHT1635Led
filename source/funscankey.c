#include "config.h"

unsigned char keyCount;

extern unsigned char modecount;
extern unsigned char displayState;

void fun_scan_key(void){
	KEYC=1;//key input mode
	if (KEY==0)
	{
		keyCount++;
		if(keyCount==5)
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
				break;
			case displayState_Bink0:
				displayState=displayState_Bink1;
				break;
			case displayState_Bink1:
				displayState=displayState_Normal;
				break;
			default:
				break;
		}
	}	
}



