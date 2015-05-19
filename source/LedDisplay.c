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

unsigned char counter =0;


/***********************
�W�q��led1 & led2 ��l��

**********/

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
0x80,0x00,0xF8,0x0F,/*"H",0*/
0x00,0x00,0xF0,0x07,0x08,0x08,0x08,0x08,
0x08,0x08,0xF0,0x07,/*"O",1*/
0x00,0x00,0xF8,0x0F,0x00,0x08,0x00,0x08,
0x00,0x08,0x00,0x08,/*"L",2*/
0x00,0x00,0x08,0x00,0x08,0x00,0xF8,0x0F,
0x08,0x00,0x08,0x00,/*"T",3*/
0x00,0x00,0xF8,0x0F,0x88,0x08,0x88,0x08,
0x88,0x08,0x08,0x08,/*"E",4*/
0x00,0x00,0xF8,0x0F,0x80,0x00,0x60,0x03,
0x18,0x0C,0x00,0x00,/*"K",5*/
0X00,0X00,0X00,0X00
};

void _init_led(void){
	//init HT1635B 1 
	iicSendCommand(SLAVEMCU1ADD, SYS_SET_COMMAND,SYS_LED_DEFAULT1);
	iicSendCommand(SLAVEMCU1ADD,BLINK_FRQ_COMMAND,BLINK_DEFAULT1);
	iicSendCommand(SLAVEMCU1ADD,DRIVE_OUT_COMMAMND,DRIVE_TYPE_DEFAULT1);
	iicSendCommand(SLAVEMCU1ADD,CASCADE_COMMAND,CASCADE_DEFAULT1);
	iicSendCommand(SLAVEMCU1ADD,PWM_DUTY_COMMAND,PWM_DUTY_DEFAULT1);
	//init HT1635B 2
	iicSendCommand(SLAVEMCU2ADD, SYS_SET_COMMAND,SYS_LED_DEFAULT2);
	iicSendCommand(SLAVEMCU2ADD,BLINK_FRQ_COMMAND,BLINK_DEFAULT2);
	iicSendCommand(SLAVEMCU2ADD,DRIVE_OUT_COMMAMND,DRIVE_TYPE_DEFAULT2);
	iicSendCommand(SLAVEMCU2ADD,CASCADE_COMMAND,CASCADE_DEFAULT2);
	iicSendCommand(SLAVEMCU2ADD,PWM_DUTY_COMMAND,PWM_DUTY_DEFAULT2);

	//power on Display hello
	_updateDisplayHello();	
}
/***********************
�{�{mode
�Q��MCU������Blink mode
**********/
void _updateDisplayBlink2s(void){
	_updateDisplayAll();
	iicSendCommand(SLAVEMCU1ADD,BLINK_FRQ_COMMAND,BLINK_0_5HZ);
	iicSendCommand(SLAVEMCU2ADD,BLINK_FRQ_COMMAND,BLINK_0_5HZ);
}
/***********************
���hello

**********/
void _updateDisplayHello(void){
	//update HT1635B 1 data
	iicStart();
	iicWrite(SLAVEMCU1ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter=0; counter < 80; counter=counter+2)
	{
		iicWrite(LedDisplayHell0Table[counter]);
		while(TestAck());
	}
	//update HT1635B 2 data
	iicStart();
	iicWrite(SLAVEMCU2ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter = 1; counter < 80; counter=counter+2)
	{
		iicWrite(LedDisplayHell0Table[counter]);
		while(TestAck());
	}
}
/***********************
���HOLTEK

**********/
void _updateDisplayNormal(void){
	//update HT1635B 1 data
	iicStart();
	iicWrite(SLAVEMCU1ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter=0; counter < 80; counter=counter+2)
	{
		iicWrite(LedDisplayNormalTable[counter]);
		while(TestAck());
	}
	//update HT1635B 2 data
	iicStart();
	iicWrite(SLAVEMCU2ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter = 1; counter < 80; counter=counter+2)
	{
		iicWrite(LedDisplayNormalTable[counter]);
		while(TestAck());
	}
}
/***********************
���G
**********/
void _updateDisplayAll(void){
	//Display all HT1635B 1
	iicStart();
	iicWrite(SLAVEMCU1ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter = 0; counter < 80; counter=counter+2)
	{
		iicWrite(0Xff);
		while(TestAck());
	}
	//Display all HT1635B 2
	iicStart();
	iicWrite(SLAVEMCU2ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter = 0; counter < 80; counter=counter+2)
	{
		iicWrite(0Xff);
		while(TestAck());
	}
	iicStop();
}
/***********************
����

**********/
void _updateDisplayoff(void){
	//Display off HT1635B 1
	iicStart();
	iicWrite(SLAVEMCU1ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter = 0; counter < 80; counter=counter+2)
	{
		iicWrite(0X00);
		while(TestAck());
	}
	//Display off HT1635B 2
	iicStart();
	iicWrite(SLAVEMCU1ADD);
	while(TestAck());
	iicWrite(SEND_DATA_COMMAND);
	while(TestAck());
	iicWrite(0X00);
	while(TestAck());
	for (counter = 0; counter < 80; counter=counter+2)
	{
		iicWrite(0X00);
		while(TestAck());
	}
}



