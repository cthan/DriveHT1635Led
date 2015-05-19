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
I2C�ҰʫH��
**********************************/
void iicStart(void)
{
	SDAC=0;//�]�wSDA�}����X
	SCLC=0;//�]�wSCL�}����X
	SDA=1;_delay();
	SCL=1;_delay();	//SCL=1 & SDA=1
	SDA=0;_delay();	//SCL=1 & SDA=0 IIC Start flag	
	SCL=0;_delay();	//SCL=0		
}

/**********************************
I2C����H��
**********************************/
void iicStop(void)
{
	SDAC=0;//�]�wSDA�}����X
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
	volatile unsigned char ErrTime=0;//
	SDAC=1;_delay();	//�]�wSDA�}����J
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
//�D���N��ƥH��C�覡�o�g�X�h
//**********************************
void iicWrite(unsigned char Data)
{
	volatile unsigned char count=8;
	SDAC=0;//�]�wSDA�}����X
	while(count--)
	{
//		SDA=(Data & 0x80);_delay();//���X��ƪ�bit7�e��SDA�}	
//		SCL=1;_delay();//�e�Xi2c�����ߨR
//		SCL=0;_delay();
//		Data=Data<<1;	//��ƥ����@��

		if((Data & 0x80)==0){
			SDA=0;
		}
		else{
			SDA=1;
		}
		_delay();
		SCL=1;_delay();//�e�Xi2c�����ߨR
		SCL=0;_delay();
		Data=Data<<1;	//��ƥ����@��		

	}
}
//**********************************
//�D��Ū�����
//**********************************
unsigned char iicRead(void)
{
	volatile unsigned char count=8,Data=0;
	SDAC=1;//�]�wSDA�}����J
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
}




