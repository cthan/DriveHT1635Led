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
#include "LedDisplay.h"
#include "IIC.h"

unsigned char counter =0;


/***********************
上電對led1 & led2 初始化

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

void init_led(void){
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
	updateDisplayHello();	
}
/***********************
閃爍mode
利用MCU內部的Blink mode
**********/
void updateDisplayBlink2s(void){
	updateDisplayAll();
	iicSendCommand(SLAVEMCU1ADD,BLINK_FRQ_COMMAND,BLINK_0_5HZ);
	iicSendCommand(SLAVEMCU2ADD,BLINK_FRQ_COMMAND,BLINK_0_5HZ);
}
/***********************
顯示hello

**********/
void updateDisplayHello(void){
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
全亮
**********/
void updateDisplayAll(void){
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
全滅

**********/
void updateDisplayoff(void){
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



