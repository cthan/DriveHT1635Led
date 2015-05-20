//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    LedDisplay.c
//Targer :       
//MCU :          HT64F40
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  ledDisplay function
//History : 
//___________________________________________________________________
//___________________________________________________________________
#include "config.h"

extern unsigned char displayState ;

volatile unsigned char counter =0;


const unsigned char	LedDisplayHell0Table[]={
0x08,0x20,0xF8,0x3F,0x08,0x21,0x00,0x01,
0x00,0x01,0x08,0x21,0xF8,0x3F,0x08,0x20,/*"H",0*/
0x00,0x00,0x00,0x1F,0x80,0x22,0x80,0x22,
0x80,0x22,0x80,0x22,0x00,0x13,0x00,0x00,/*"e",1*/
0x00,0x00,0x08,0x20,0x08,0x20,0xF8,0x3F,
0x00,0x20,0x00,0x20,0x00,0x00,0x00,0x00,/*"l",2*/
0x00,0x00,0x08,0x20,0x08,0x20,0xF8,0x3F,
0x00,0x20,0x00,0x20,0x00,0x00,0x00,0x00,/*"l",3*/
0x00,0x00,0x00,0x1F,0x80,0x20,0x80,0x20,
0x80,0x20,0x80,0x20,0x00,0x1F,0x00,0x00/*"o",4*/
};
const unsigned char LedDisplayNormalTable[]={
0X00,0X00,0X00,0X00,
0x00,0x00,0xF8,0x0F,0x80,0x00,0x80,0x00,
0x80,0x00,0xF8,0x0F,				/*"H",0*/
0x00,0x00,0xF0,0x07,0x08,0x08,0x08,0x08,
0x08,0x08,0xF0,0x07,				/*"O",1*/
0x00,0x00,0xF8,0x0F,0x00,0x08,0x00,0x08,
0x00,0x08,0x00,0x08,				/*"L",2*/
0x00,0x00,0x08,0x00,0x08,0x00,0xF8,0x0F,
0x08,0x00,0x08,0x00,				/*"T",3*/
0x00,0x00,0xF8,0x0F,0x88,0x08,0x88,0x08,
0x88,0x08,0x08,0x08,				/*"E",4*/
0x00,0x00,0xF8,0x0F,0x80,0x00,0x60,0x03,
0x18,0x0C,0x00,0x00,				/*"K",5*/
0X00,0X00,0X00,0X00
};


/*****************************
 *@�y�z �W�q��led1 & led2 ��l��
 *@�Ѽ� �L
 *@��^ �L
 ****************************/
void _init_led(void){
	//init HT1635B 1 
	iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND    , SYS_LED_DEFAULT1    );
	iicSendCommand( SLAVEMCU1ADD , BLINK_FRQ_COMMAND  , BLINK_DEFAULT	    );
	iicSendCommand( SLAVEMCU1ADD , DRIVE_OUT_COMMAMND , DRIVE_TYPE_DEFAULT1 );
	iicSendCommand( SLAVEMCU1ADD , CASCADE_COMMAND    , CASCADE_DEFAULT1    );
	iicSendCommand( SLAVEMCU1ADD , PWM_DUTY_COMMAND   , PWM_DUTY_DEFAULT1   );
	//init HT1635B 2
	iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND    , SYS_LED_DEFAULT2    );
	iicSendCommand( SLAVEMCU2ADD , BLINK_FRQ_COMMAND  , BLINK_DEFAULT		);
	iicSendCommand( SLAVEMCU2ADD , DRIVE_OUT_COMMAMND , DRIVE_TYPE_DEFAULT2 );
	iicSendCommand( SLAVEMCU2ADD , CASCADE_COMMAND    , CASCADE_DEFAULT2	);
	iicSendCommand( SLAVEMCU2ADD , PWM_DUTY_COMMAND   , PWM_DUTY_DEFAULT2	);
	//power on Display hello
	_updateDisplayHello();
	displayState=displayState_Hello;	
}
/**************************
 *@�y�z �]�wLED�{�{mode (�Q��MCU������Blink mode)
 *@�Ѽ� �L
 *@��^ �L
 *************************/
void _updateDisplayBlink(void){
	_updateDisplayAll();	
	iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU1ADD , BLINK_FRQ_COMMAND , BLINK_1HZ );
	iicSendCommand( SLAVEMCU2ADD , BLINK_FRQ_COMMAND , BLINK_1HZ );
}
/***************************
 *@�y�z ���hello
 *@�Ѽ� �L
 &@��^ �L
 *************************/
void _updateDisplayHello(void){
	iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU1ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
	iicSendCommand( SLAVEMCU2ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
//update HT1635B 1 data
	iicStart();
	//�o�eHT1635B 1 IIC�a�}
	iicWrite(SLAVEMCU1ADD);	
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);				
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 1���ƾ�
	for (counter=0; counter < 80; counter=counter+2){
		iicWrite(LedDisplayHell0Table[counter]);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
	//HT1635B 1���ƾڼg�J�����A����IIC
	iicStop();

//update HT1635B 2 data
	iicStart();
	//�o�eHT1635B 2 IIC�a�}
	iicWrite(SLAVEMCU2ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 2���ƾ�
	for (counter = 1; counter < 80; counter=counter+2){
		iicWrite(LedDisplayHell0Table[counter]);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
	//HT1635B 2���ƾڼg�J�����A����IIC
	iicStop();	
}
/***********************
���HOLTEK

**********/
void _updateDisplayNormal(void){
	iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU1ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
	iicSendCommand( SLAVEMCU2ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
//update HT1635B 1 data
	iicStart();
	//�o�eHT1635B 1 IIC�a�}
	iicWrite(SLAVEMCU1ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O	
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 1���ƾ�
	for (counter=0; counter < 80; counter=counter+2){
		iicWrite(LedDisplayNormalTable[counter]);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
	//HT1635B 1���ƾڼg�J�����A����IIC
	iicStop();

//update HT1635B 2 data
	iicStart();
	//�o�eHT1635B 2 IIC�a�}
	iicWrite(SLAVEMCU2ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 2���ƾ�
	for (counter = 1; counter < 80; counter=counter+2){
		iicWrite(LedDisplayNormalTable[counter]);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
}
/***********************
���G
**********/
void _updateDisplayAll(void){
	iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU1ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
	iicSendCommand( SLAVEMCU2ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
//Display all HT1635B 1
//	iicStart();
//	//�o�eHT1635B 1 IIC�a�}
//	iicWrite(SLAVEMCU1ADD);
//	if (TestAck()==1){
//		iicStop();
//		return;
//	}
//	//�o�e�g�ƾکR�O
//	iicWrite(SEND_DATA_COMMAND);
//	if (TestAck()==1){
//		iicStop();
//		return;
//	}
//	//�o�e�g�J�_�l�a�}
//	iicWrite(0X00);
//	if (TestAck()==1){
//		iicStop();
//		return;
//	}
//	//�`���g�JHT1635B 1���ƾ�
//	for (counter = 0; counter < 44; counter++){
//		iicWrite(0Xff);
//		if (TestAck()==1){
//			iicStop();
//			return;
//		}
//	}
	//Display all HT1635B 2
	iicStart();
	//�o�eHT1635B 2 IIC�a�}
	iicWrite(SLAVEMCU2ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 2���ƾ�
	for (counter = 0; counter < 44; counter++){
		iicWrite(0Xff);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
	iicStop();
	iicStart();
	//�o�eHT1635B 1 IIC�a�}
	iicWrite(SLAVEMCU1ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 1���ƾ�
	for (counter = 0; counter < 44; counter++){
		iicWrite(0Xff);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
	iicStop();
}
/***********************
����

**********/
void _updateDisplayoff(void){
	iicSendCommand( SLAVEMCU1ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU2ADD , SYS_SET_COMMAND  , SYS_EN_LED_ON);
	iicSendCommand( SLAVEMCU1ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
	iicSendCommand( SLAVEMCU2ADD , BLINK_FRQ_COMMAND  , BLINK_OFF);
	//Display off HT1635B 1
	iicStart();
	//�o�eHT1635B 1 IIC�a�}
	iicWrite(SLAVEMCU1ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 1���ƾ�
	for (counter = 0; counter < 44; counter++){
		iicWrite(0X00);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
	//Display off HT1635B 2
	iicStart();
	//�o�eHT1635B 2 IIC�a�}
	iicWrite(SLAVEMCU2ADD);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�ƾکR�O
	iicWrite(SEND_DATA_COMMAND);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�o�e�g�J�_�l�a�}	
	iicWrite(0X00);
	if (TestAck()==1){
		iicStop();
		return;
	}
	//�`���g�JHT1635B 2���ƾ�
	for (counter = 0; counter < 44; counter++){
		iicWrite(0X00);
		if (TestAck()==1){
			iicStop();
			return;
		}
	}
}



