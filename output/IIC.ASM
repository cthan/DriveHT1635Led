; Generated by holtek-gcc v3.12, Mon May 18 19:36:58 2015
; 
; Configuration:
;       without long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:15
;       with mp1
;       with tbhp, address(0x9)
;          Use ret-const
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.12" "build 20130711"
; Rebuild 113

ir equ [2]
mp equ [3]
sbp equ [7]
acc equ [5]
bp equ [4]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
intc equ [11]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @HCCINIT, @HCCINIT0
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
public __delay
#pragma debug scope 2 1
#line 133 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
__delay .section 'code'
__delay proc
#line 134 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 134 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	nop
#line 135 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 135 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	nop
#line 136 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 136 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	nop
#line 137 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 137 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	nop
#line 138 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 138 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	nop
#line 139 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 139 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	clr wdt
#line 140 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 140 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	clr wdt1
#line 141 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
;# 141 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c" 1
	clr wdt2
	ret
__delay endp
#line 141 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _iicStart
#pragma debug scope 3 1
#line 37 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_iicStart .section 'code'
_iicStart proc
#line 38 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].0
#line 39 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 40 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].0
	call __delay
#line 41 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 42 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].0
	call __delay
#line 43 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	call __delay
	ret
_iicStart endp
#line 43 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _iicStop
#pragma debug scope 4 1
#line 50 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_iicStop .section 'code'
_iicStop proc
#line 51 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].0
#line 52 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 53 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].0
	call __delay
#line 54 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 55 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].0
	call __delay
#line 56 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	call __delay
	ret
_iicStop endp
#line 56 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _Ack
#pragma debug scope 5 1
#line 64 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_Ack .section 'code'
_Ack proc
#line 65 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].0
#line 66 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 67 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].0
	call __delay
#line 68 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 69 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	call __delay
#line 70 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].0
	call __delay
	ret
_Ack endp
#line 70 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _NoAck
#pragma debug scope 6 1
#line 76 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_NoAck .section 'code'
_NoAck proc
#line 77 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].0
#line 78 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 79 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].0
	call __delay
#line 80 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 81 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	call __delay
	ret
_NoAck endp
#line 81 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _TestAck
#pragma debug scope 7 1
#line 88 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_TestAck .section 'code'
_TestAck proc
    local _TestAck_2 db 1 dup(?)	; 0,1
#line 90 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [27].0
#line 91 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 93 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 94 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,[26]
	and a,1
	mov _TestAck_2[0],a
	call __delay
#line 95 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	call __delay
#line 96 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].0
#line 98 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,_TestAck_2[0]
	ret
_TestAck endp
#line 98 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _iicWrite
#pragma debug scope 8 1
#line 103 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_iicWrite .section 'code'
_iicWrite proc
    local _iicWrite_2 db 2 dup(?)	; 0,2
	mov _iicWrite_2[0],a
#pragma debug variable 8 8 _iicWrite_2+0 "Data"
#line 105 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].0
#line 106 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 107 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,9
	mov _iicWrite_2[1],a
	jmp _L8
_L9:
#line 109 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].0
#line 110 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	call __delay
#line 111 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 112 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	call __delay
_L8:
	sdz _iicWrite_2[1]
	jmp _L9
	ret
_iicWrite endp
#line 112 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _iicSendCommand
#pragma debug scope 9 1
#line 22 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_iicSendCommand .section 'code'
_iicSendCommand proc
public _iicSendCommand_2
    local _iicSendCommand_2 db 3 dup(?)	; 2,1
	mov _iicSendCommand_2[2],a
#pragma debug variable 8 9 _iicSendCommand_2+2 "address"
#pragma debug variable 8 9 _iicSendCommand_2+0 "command"
#pragma debug variable 8 9 _iicSendCommand_2+1 "commandData"
#line 23 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	call _iicStart
#line 24 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,_iicSendCommand_2[2]
	call _iicWrite
_L13:
#line 25 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	call _TestAck
	mov ra,a
	sz ra
	jmp _L13
#line 26 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,_iicSendCommand_2[0]
	call _iicWrite
_L15:
#line 27 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	call _TestAck
	mov ra,a
	sz ra
	jmp _L15
#line 28 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,_iicSendCommand_2[1]
	mov ra,a
	mov a,ra
	call _iicWrite
_L17:
#line 29 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	call _TestAck
	mov ra,a
	sz ra
	jmp _L17
#line 30 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	call _iicStop
	ret
_iicSendCommand endp
#line 30 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
public _iicRead
#pragma debug scope 10 1
#line 120 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
_iicRead .section 'code'
_iicRead proc
    local _iicRead_2 db 2 dup(?)	; 0,2
#line 122 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [27].0
#line 123 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [27].1
#line 124 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,9
	mov _iicRead_2[1],a
#line 121 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr _iicRead_2[0]
_L19:
	sdz _iicRead_2[1]
	jmp _LI1
	jmp _L21
_LI1:
#line 126 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	set [26].1
	call __delay
#line 127 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,_iicRead_2[0]
	add a,_iicRead_2[0]
	mov rb,a
#line 128 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,[26]
	and a,1
	mov ra,a
	mov a,rb
	or a,ra
	mov _iicRead_2[0],a
#line 129 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	clr [26].1
	jmp _L19
_L21:
#line 132 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
	mov a,_iicRead_2[0]
	ret
_iicRead endp
#line 132 "E:\Doing\�Ҽw�q�l\DriveHT1635Led\source\IIC.c"
#pragma debug scope 1 1
___pa equ [01ah]
#pragma debug struct_begin 42 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 [01ah] "__pa" 1
___pac equ [01bh]
#pragma debug struct_begin 44 "__pac_bits"
#pragma debug field 21 8 0 1 "__pac0" ;0,1
#pragma debug field 21 8 0 1 "__pac1" ;1,1
#pragma debug field 21 8 0 1 "__pac2" ;2,1
#pragma debug field 21 8 0 1 "__pac3" ;3,1
#pragma debug field 21 8 0 1 "__pac4" ;4,1
#pragma debug field 21 8 0 1 "__pac5" ;5,1
#pragma debug field 21 8 0 1 "__pac6" ;6,1
#pragma debug field 21 8 0 1 "__pac7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 [01bh] "__pac" 1
IFDEF ISR_SYSTEM_STACK_BEFORE_2014_12_23
ELSE
ENDIF

; 
; Generated by holtek-gcc v3.12, Mon May 18 19:36:58 2015
; Rebuild 113
; end of file