#include "config.h"

volatile unsigned char keyCount;
unsigned char keychk;
unsigned char keytemp;
unsigned char keychat;
extern unsigned char modecount;
extern unsigned char displayState;
extern unsigned char BinklState;
extern unsigned int counter3s;

void fun_scan_key(void){
	KEYC=1;//key input mode
//	keytemp=pa & 0x10;	//PA4
//
//	if(keytemp!=keychk){
//		flag_keyin=1;
//		keychk=keytemp;
//		keychat=4;
//	}
//	else if(flag_keyin==1){
//		keychat--;
//		
//
//	}
	if (KEY==0){
		keyCount++;
		if(keyCount==3)
		{
			flag_keypush=1;
			keyCount=0;
		}
	}
	else{
		keyCount=0;
	}	
	if(flag_keypush==1&&KEY==1){
		flag_keypush=0;
		flag_keypop=1;
		keyCount=0;
	}
	
}


void fun_task_key(void){
	if(flag_keypop==1){
		flag_keypop=0;
		switch(displayState){
			case displayState_Hello:
				displayState=displayState_All;
				break;
			case displayState_All:	//LED¥ß§Yoff
				displayState=displayState_Bink1;
				iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_OFF);
				iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_DIS_LED_OFF);
				BinklState=BinkState_Off;
				flag_3s=0;
				counter3s=300;
				break;				
			case displayState_Bink1:
				displayState=displayState_Hello;
				break;				
//			case displayState_All:
//				displayState=displayState_Bink0;
//				_updateDisplayBlink();
//				break;
//			case displayState_Bink0:
//				displayState=displayState_Bink1;
//				_updateDisplayAll();
//				break;
//			case displayState_Bink1:
//				displayState=displayState_Normal;
//				break;
//			case displayState_Normal:
//				displayState=displayState_Off;
//				break;
//			case displayState_Off:
//				displayState=displayState_Hello;
//				break;
			default:
				break;
		}
	}	
}



