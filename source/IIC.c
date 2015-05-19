//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    IIC.C
//Targer :       
//MCU :          HT64F50
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  IIC function
//History : 
//___________________________________________________________________
//___________________________________________________________________
#include "config.h"



/**********************************
IIC設置命令發送程序
**********************************/
void iicSendCommand(unsigned char address, unsigned char command,unsigned char commandData)
{
	iicStart();
	iicWrite(address);
	if (TestAck()==1){
		iicStop();
		return;
	}
	iicWrite(command);
	if (TestAck()==1){
		iicStop();
		return;
	}
	iicWrite(commandData);
	if (TestAck()==1){
		iicStop();
		return;
	}
	iicStop();
}

/**********************************
I2C啟動信號
**********************************/
void iicStart(void)
{
	SDAC=0;//設定SDA腳為輸出
	SCLC=0;//設定SCL腳為輸出
	SDA=1;_delay();
	SCL=1;_delay();	//SCL=1 & SDA=1
	SDA=0;_delay();	//SCL=1 & SDA=0 IIC Start flag	
	SCL=0;_delay();	//SCL=0		
}

/**********************************
I2C停止信號
**********************************/
void iicStop(void)
{
	SDAC=0;//設定SDA腳為輸出
	SDA=0;_delay();//SDA=0
	SCL=1;_delay();//SCL=1
	SDA=1;_delay();//SDA=1
	SCL=0;_delay();//SCL=0	
}
//**********************************
//ACK(0)信號信號，通知從幾已讀取資料
//或后面還有資料
//**********************************
void Ack(void)
{
	SDAC=0;//設定SDA腳為輸出
	SDA=0;_delay();//SDA=0
	SCL=1;_delay();//SCL=1
	SCL=0;_delay();//SCL=0
	SDA=1;_delay();//SDA=1
}
//**********************************
//NoAck(1)信號信號，通知從幾無資料讀取
//**********************************
void NoAck(void)
{
	SDAC=0;//設定SDA腳為輸出
	SDA=1;_delay();//SDA=1
	SCL=1;_delay();//SCL=1
	SCL=0;_delay();//SCL=0
}
//**********************************
//主機檢查從幾回傳的ACK信號
//0為ACK完成動作，1為未完成動作
//**********************************
unsigned char TestAck(void)
{	
	volatile unsigned char ErrTime=0;//
	SDAC=1;_delay();	//設定SDA腳為輸入
	SCL =1;_delay();	//SCL=1
	while(SDA==1){
		ErrTime++;
		if (ErrTime>250){
			return 1;
		}
	}
	SCL=0;_delay();
	return 0;
}
//**********************************
//主機將資料以串列方式發射出去
//**********************************
void iicWrite(unsigned char Data)
{
	volatile unsigned char count=8;
	SDAC=0;//設定SDA腳為輸出
	while(count--)
	{
//		SDA=(Data & 0x80);_delay();//取出資料的bit7送到SDA腳	
//		SCL=1;_delay();//送出i2c時鐘脈沖
//		SCL=0;_delay();
//		Data=Data<<1;	//資料左移一位

		if((Data & 0x80)==0){
			SDA=0;
		}
		else{
			SDA=1;
		}
		_delay();
		SCL=1;_delay();//送出i2c時鐘脈沖
		SCL=0;_delay();
		Data=Data<<1;	//資料左移一位		

	}
}
//**********************************
//主機讀取資料
//**********************************
unsigned char iicRead(void)
{
	volatile unsigned char count=8,Data=0;
	SDAC=1;//設定SDA腳為輸入
	while(count--)
	{
		SCL=1;_delay();
		Data=Data<<1;//資料左移一位
		Data=Data|((unsigned char)(SDA));//讀取串bit與Data合并
		SCL=0;
	}	
	return(Data);
}
void _delay(void){
	GCC_NOP();
	GCC_NOP();
	GCC_NOP();
	GCC_NOP();
	GCC_NOP();
}




