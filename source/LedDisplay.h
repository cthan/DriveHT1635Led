//___________________________________________________________________
//___________________________________________________________________
//Copyright :    2015 by HOLTEK SEMICONDUCTOR INC
//File Name :    LedDisplay.h
//Targer :       
//MCU :          HT64F40
//Version :      V00
//Author :       ChenTing
//Date :         2015/05/18
//Description :  ledDisplay function config
//History : 
//___________________________________________________________________
//___________________________________________________________________
#ifndef _LEDDISPLAY_H
#define _LEDDISPLAY_H

void _init_led(void);
void _updateDisplayBlink2s(void);
void _updateDisplayHello(void);
void _updateDisplayAll(void);
void _updateDisplayoff(void);
void _updateDisplayNormal(void);

#define displayState_Hello	0
#define displayState_All	1
#define displayState_Off	2
#define displayState_Bink0	3	//HT1635  內部閃爍
#define displayState_Bink1	4	//HT68F40 控制閃爍時間
#define displayState_Normal 5
#define BinkState_All		0
#define BinkState_Off		1

#define SEND_DATA_COMMAND	0x80

//system oscillator & led display config
#define SYS_SET_COMMAND		0x82
#define SYS_DIS_LED_OFF		0x00	//power on status
#define SYS_EN_LED_OFF		0x02
#define SYS_EN_LED_ON		0x03
#define SYS_LED_DEFAULT1	SYS_EN_LED_ON
#define SYS_LED_DEFAULT2	SYS_EN_LED_ON
//Blinking frequency config
#define	BLINK_FRQ_COMMAND 	0x84
#define BLINK_OFF			0x00	//power on status
#define BLINK_2HZ			0x01	
#define BLINK_1HZ			0x02	
#define BLINK_0_5HZ			0x03
#define BLINK_DEFAULT1		BLINK_1HZ	
#define BLINK_DEFAULT2		BLINK_1HZ	
//Drive config
#define DRIVE_OUT_COMMAMND	0x88
#define DRIVE_TYPE_NMOS		0x00	//power on status
#define DRIVE_TYPE_PMOS		0x01
#define DRIVE_TYPE_DEFAULT1	DRIVE_TYPE_NMOS
#define DRIVE_TYPE_DEFAULT2	DRIVE_TYPE_NMOS
//Cascade config
#define CASCADE_COMMAND		0xA0
#define MASTER_OSC_SINGLE 	0x04	//power on status
#define MASTER_OSC_CASCADE 	0x05
#define MASTER_EXT_SINGLE 	0x06
#define MASTER_EXT_CASCADE 	0x07
#define SLAVE_EXT_CASCADE	0x00
#define CASCADE_DEFAULT1	MASTER_OSC_SINGLE		
#define CASCADE_DEFAULT2	MASTER_OSC_SINGLE		
//PWM duty config
#define PWM_DUTY_COMMAND	0xC0
#define ROW_PULSE_1_16		0x00
#define ROW_PULSE_2_16		0x01
#define ROW_PULSE_3_16		0x02
#define ROW_PULSE_4_16		0x03
#define ROW_PULSE_5_16		0x04
#define ROW_PULSE_6_16		0x05
#define ROW_PULSE_7_16		0x06
#define ROW_PULSE_8_16		0x07
#define ROW_PULSE_9_16		0x08
#define ROW_PULSE_10_16		0x09
#define ROW_PULSE_11_16		0x0a
#define ROW_PULSE_12_16		0x0b
#define ROW_PULSE_13_16		0x0c
#define ROW_PULSE_14_16		0x0d
#define ROW_PULSE_15_16		0x0e
#define ROW_PULSE_16_16		0x0f	//power on status
#define PWM_DUTY_DEFAULT1	ROW_PULSE_1_16
#define PWM_DUTY_DEFAULT2	ROW_PULSE_1_16



#endif