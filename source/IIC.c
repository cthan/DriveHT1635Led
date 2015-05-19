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
IIC�]�m�R�O�o�e�{��
**********************************/
void iicSendCommand(unsigned char address, unsigned char command,unsigned char commandData)
{
	iicStart();
	iicWrite(address);
	while(TestAck());
	iicWrite(command);
	while(TestAck());
	iicWrite(commandData);
	while(TestAck());
	iicStop();
}

/**********************************
I2C�ҰʫH��
**********************************/
void iicStart(void)
{
	SDAC=0;//�]�wSDA�}����X
	SCLC=0;//�t��SCL�}����X
	SDA=1;_delay();//SDA=1
	SCL=1;_delay();//SCL=1
	SDA=0;_delay();//SDA=0
	SCL=0;_delay();//SCL=0	
}

/**********************************
I2C����H��
**********************************/
void iicStop(void)
{
	SDAC=0;//�]�wSDA�}����X
	SCLC=0;//�t��SCL�}����X
	SDA=0;_delay();//SDA=0
	SCL=1;_delay();//SCL=1
	SDA=1;_delay();//SDA=1
	SCL=0;_delay();//SCL=0
		
}
//**********************************
//ACK(0)�H���H���A�q���q�X�wŪ�����
//�ΦZ���٦����
//**********************************
void Ack(void)
{
	SDAC=0;//�]�wSDA�}����X
	SCLC=0;//�t��SCL�}����X
	SDA=0;_delay();//SDA=0
	SCL=1;_delay();//SCL=1
	SCL=0;_delay();//SCL=0
	SDA=1;_delay();//SDA=1
}
//**********************************
//NoAck(1)�H���H���A�q���q�X�L���Ū��
//**********************************
void NoAck(void)
{
	SDAC=0;//�]�wSDA�}����X
	SCLC=0;//�t��SCL�}����X
	SDA=1;_delay();//SDA=1
	SCL=1;_delay();//SCL=1
	SCL=0;_delay();//SCL=0
}
//**********************************
//�D���ˬd�q�X�^�Ǫ�ACK�H��
//0��ACK�����ʧ@�A1���������ʧ@
//**********************************
unsigned char TestAck(void)
{	
	unsigned char Ack_Bit;//�w�qack�줸
	SDAC=1;//�]�wSDA�}����J
	SCLC=0;//�t��SCL�}����X
	//SDA=1;_delay();//SDA=1
	SCL=1;_delay();//SCL=1
	Ack_Bit=SDA;_delay();//Ū���^�ǽT�{ACK
	SCL=0;_delay();//SCL=0
	SDAC=0;
	return Ack_Bit;
}
//**********************************
//�D���N��ƥH��C�覡�o�g�X�h
//**********************************
void iicWrite(unsigned char Data)
{
	unsigned char count=8;
	SDAC=0;//�]�wSDA�}����X
	SCLC=0;//�t��SCL�}����X
	while(count--)
	{
		SDA=(Data & 0x80);//���X��ƪ�bit7�e��SDA�}
		_delay();
		SCL=1;_delay();//�e�Xi2c�����ߨR
		SCL=0;_delay();
		Data=Data<<1;//��ƥ����@��
	}
}
//**********************************
//�D��Ū�����
//**********************************
unsigned char iicRead(void)
{
	unsigned char count=8,Data=0;
	SDAC=1;//�]�wSDA�}����J
	SCLC=0;//�t��SCL�}����X
	while(count--)
	{
		SCL=1;_delay();
		Data=Data<<1;//��ƥ����@��
		Data=Data|((unsigned char)(SDA));//Ū����bit�PData�X�}
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
	GCC_CLRWDT();
	GCC_CLRWDT1();
	GCC_CLRWDT2();
}




