;Answer problem 4 here
		.ORIG x3000 ; Starts at x3000
	
		AND R0,R0,#0 ; clear R0 - #-5
		AND R1,R1,#0 ; clear R1 - value
		AND R2,R2,#0 ; clear R2 - final counter
		AND R3,R3,#0 ; clear R3 - address count down
		ADD R3,R3,#11; countdown 10 addresses
		AND R4,R4,#0 ; clear R4 - current address
		AND R5,R5,#0 ; check if <5
	
		ADD R0,R0,#5 ; R0 = #5
		NOT R0,R0    
		ADD R0,R0,#1 ; R0 = #-5	
	
LOOPONE 	ADD R3,R3,#-1
		BRnz STO_VAL
		LD R4, FIN_MEM 	
		ADD R4,R4,R3 ; R4 = address
		LDR R1,R4,#0 ; 
		ADD R5,R1,R0 ; R5 <-[input - 5]
		BRnz LOOPONE ; if input<5 or =5,try next address
		ADD R2,R2,#1 ; add to counter if input >5
 
STO_VAL 	ST R3, FIN_MEM ;	

LOOPONEBOT	 HALT

BEG_MEM	.FILL x40A0
MEM_TWO	.FILL x40A1
MEM_THR	.FILL x40A2
MEM_FOU	.FILL x40A3
MEM_FIV	.FILL x40A4
MEM_SIX	.FILL x40A5
MEM_SEV	.FILL x40A6
MEM_EIG	.FILL x40A7
MEM_NIN	.FILL x40A8
MEM_TEN	.FILL x40A9
FIN_MEM	.FILL x40AA 

.END 
