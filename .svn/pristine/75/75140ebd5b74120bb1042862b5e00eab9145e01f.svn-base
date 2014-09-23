; Michelle Cabahug (working with Kevin Boldingh (boldngh2) Fall 2013

; R4 = col # (changed to col # -1)
; R5 = row # (changed to row # -1)
; R6 = board size
; R1 = used as -R6
; R2 = address of current index
; R3 = current character
; R0 = R5 used as counter

.ORIG x3400

UPDATEBOARD	ST R7, R7initial	;stores R7 in memory to be retrieved at the end of the subroutine
		ST R4, R4initial	;stores R4 in memory to be retrieved at the end of the subroutine
		ST R5, R5initial	;stores R5 in memory to be retrieved at the end of the subroutine
		
		AND R1,R1,#0
		NOT R1,R6
		ADD R1,R1,#1	
		AND R0,R0,#0
		

		ADD R4, R4, #-1		; R4-1
				
		ADD R5, R5, #-1		; initialize counter R5 = R5 - 1
		ADD R0, R5,#0

		AND R2, R2, #0	
		LD R2, GB_POINTER	; R2 = x3600
	
		ADD R0, R0, #0		; if R0 = 0, dont loop
		BRz POSTLOOP
LOOP		ADD R2, R2, R6		; R2 = R2 + R6
		ADD R0, R0, #-1		; decrement counter
		BRp LOOP		; at the end R2 = x3600 + R6*(row #-1)

POSTLOOP	ADD R2, R2, R4		; chosen location R2 = x3600 + R6*(row #-1) + (col #-1)
		JSR FLIP
	
		ADD R2, R2, #-1		; left location
		ADD R4, R4, #0		; if first column, no left
		BRz RIGHT
		JSR FLIP

RIGHT		ADD R2, R2, #2		; right location
		ADD R4, R4, R1
		ADD R4, R4, #1		; if last column, no right
		BRz BOT
		JSR FLIP

BOT		ADD R2, R2, #-1		; bottom location
		ADD R2, R2, R1
		ADD R5, R5, #0		; if first row, no top
		BRz TOP
		JSR FLIP

TOP		ADD R2, R2, R6		; top location
		ADD R2, R2, R6
		ADD R5, R5, R1		; if last row, no bottom
		ADD R5, R5, #1
		BRz DONE
		JSR FLIP
		BRnzp DONE
				
FLIP		LDR R3, R2, #0

		ADD R3,R3,#-16
		ADD R3,R3,#-16		
		ADD R3,R3,#-16		; ascii '0'
		BRz SETONE	
	
		ADD R3,R3,#15		;if not 0 set to 0
		ADD R3,R3,#15		
		ADD R3,R3,#15
		ADD R3,R3,#2
		
		BRnzp NEXT


SETONE		ADD R3,R3,#15	; if 0 set to 1
		ADD R3,R3,#15		
		ADD R3,R3,#15				
		ADD R3,R3,#4
	
NEXT		STR R3, R2, #0 ; store current index
		RET

DONE		LD R4, R4initial
		LD R5, R5initial
		LD R7, R7initial
		RET ;make ret

		GB_POINTER	.FILL x3600		; start of GAMEBOARD 
		R5initial	.FILL x0
		R4initial	.FILL x0
		R7initial	.FILL x0
.END
