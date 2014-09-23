; Michelle Cabahug (working with Kevin Boldingh (boldngh2) Fall 2013

; This file should be submitted in mp2.2
; Calls each of the subroutines in order, receives input from checkwin and displays the win value when R0 is 0
; Loops until win

;R2 =  stores address of next subroutine to jump to
;R0 =  win condition (1 is false, 0 is true)

; Comments
		.ORIG x3000
		AND R2,R2,#0
		LD R2, GETSIZ
		JSRR R2


		AND R2,R2,#0
		LD R2, PRINTBOAR
		JSRR R2
AGAIN		AND R2,R2,#0
		LD R2, GETINPU
		JSRR R2
		AND R2,R2,#0
		LD R2, UPDATEBOAR
		JSRR R2
		AND R2,R2,#0
		LD R2, PRINTBOAR
		JSRR R2
		AND R2,R2,#0
		LD R2, CHECKWI
		JSRR R2

		ADD R0,R0,#0		; if checkwin fails, R0 = 1		
		BRnp AGAIN		; if fail, go back to AGAIN
		
		LEA R0,WIN
		PUTS
		
		HALT




WIN .STRINGZ "\nCongratulations, you win!\n"	; The words you need to display if the player wins. 
GETSIZ .FILL x3100	; The location of the subroutine getsize which has 
			; output: R6 boardsize
PRINTBOAR .FILL x3200	; The location of the subroutine printboard which has 
			; input: R6 boardsize 
GETINPU .FILL x3300	; The location of the subroutine getinput which has 
			; input: R6 boardsize output: R4 row R5 column
UPDATEBOAR .FILL x3400	; The location of the subroutine updateboard which has 
			; input: R4 row R5 column R6 boardsize
CHECKWI .FILL x3500	; The location of the subroutine checkwin which has input: R6 boardsize 
			; output: R0 0 for win anyother for fail
GAMEBOAR .FILL x3600	; The location of the gameboard which starts at x3600

		.END

