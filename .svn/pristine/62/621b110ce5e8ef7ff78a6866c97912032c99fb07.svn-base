;Answer problem 6 here; R0 = n value
; R1 = 2n value
; R2 = address of A value
; R3 = actual A value
; R4 = address of B value
; R5 = actual B value
; R6 = n value ticker
; R7 = C value

		.ORIG x3000
		
		LEA R0,N_VAL	; R0 <- n value
		LEA R6,N_VAL	; R6 <- n value
		AND R1,R1,#0	; Clear R1
		AND R3,R3,#0	; clear R3
		AND R5,R5,#0	; clear R5
		ADD R1,R0,R0	; R1 <- 2n
		LEA R2,A_START	; R2 <- A addr
		ADD R1,R1,R2	; R3 <- C addr
		

ADDLOOP		LDR R3,R2,#0	; load current A value into R3
		LDR R4,R2,R0	; load current B value into R4 (A addr + n)
		ADD R7,R3,R4	; R7<-[An + Bn]
		STR R7,R1,#0	; Store R7 in C addr	
		ADD R1,R1,#1	; Next C addr
		ADD R0,R0,#1	; R0 points to next address
		ADD R6,R6,#-1	; check if done
		BRzn DUNZO	; if done exit

DUNZO		HALT	

N_VAL		.FILL x4000
A_START		.FILL x4001

		.END
