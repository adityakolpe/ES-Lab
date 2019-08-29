	AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =0xFFFFFFFF
	MOV R1, #0x20
	MOV R2,#0	
UP	
	RORS R0,#0x1
	BCC DOWN
	ADD R2,#0x01
DOWN
	SUB R1,#0x01
	TEQ R1,#00
	BNE UP
stop
	b stop

	AREA mydata,DATA,READWRITE
	end
	