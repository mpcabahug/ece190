; Michelle Cabahug (working with Kevin Boldingh (boldngh2) Fall 2013
; This file should be submitted in mp2.2
; Checks if the gameboard is completely filled with 0's, if so, the player wins
; R6 = gameboard size (inputted)
; R0 = output. R0 = 0 if all pieces are 0, game over. R0 = 1 if game not over.
; FIRST POINTER = x3600
; LAST POINTER = x3600 + [R6^2 - 1]

		.ORIG x3500
		
CHECKWIN	AND R0,R0,#0
		ADD R0,R0,#1		; R0 = 1. Assumption = not win		
		AND R1,R1,#0
		ADD R1,R1,R6		; R6 SAVED TO R1 => NUMBER OF TIMES R6 IS ADDED TO ITSELF
		ADD R1,R1,#-2
		AND R5,R5,#0

		ADD R5,R6,R6		; R5=R6 - 1st time

LAST_SPOT	ADD R5,R5,R6		; R5 = R5+R6	
		ADD R1,R1,#-1		; decrement how many times R6 is added to R5
		BRp LAST_SPOT
		ADD R5,R5,#-1		; R5 = [R6^2 -1] 
		
		AND R2,R2,#0		
		AND R3,R3,#0		
		LD R2,GB_POINTER	; R2 = x3600
		
CHECK		LDR R4,R2,#0		; character at address
		ADD R4,R4,#-16
		ADD R4,R4,#-16		
		ADD R4,R4,#-16
		ADD R4,R4,#-1		; subract #49 to check if value is #1
		BRz END_P		; if R4-#49 = 0, game not over
		ADD R5,R5,#-1		; check offset
		BRn WIN			; if at final memory location and no 1's, exit loop
		ADD R2,R2,#1		; point to next memory location
		BRnzp CHECK

END_P		RET

WIN		AND R6,R6,#0		; clear R6 if game over
		AND R0,R0,#0		; clear R0 if game over
		BRnzp END_P		


GB_POINTER	.FILL x3600		; start of GAMEBOARD 
		.END
