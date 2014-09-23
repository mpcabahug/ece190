;Michelle Cabahug (working with Kevin Boldingh) Fall 2013

;Allows the user to input a size for the square table to be created in printboard
;This size is passed to printboard for use in R6
;R6 = size
;R0 = various messages to be printed out
;R4 =  temporarily holds decimal value of R0


; This file should be submitted in both mp2.1 and mp2.2
; GETSIZE is a subroutine with two subroutines inside of it! 

		.ORIG x3100		; labelled subroutine
		
GETSIZE		AND R4,R4,#0		; clear R4
		AND R6,R6,#0		; clear R6

DISP_ASK	AND R0,R0,#0		; clear R0
		LEA R0,ASKSIZE 		; load the address of the ASKSIZE string into R0
		PUTS            	; print the ask age string
		AND R0,R0,#0		; clear R0 again	
		GETC
		OUT
		ADD R0,R0,#-16
		ADD R0,R0,#-16
		ADD R0,R0,#-16		; R0 is now decimal value (must subtract #48)
		ADD R4,R0,#0		; R4 = R0
		JSR LESSTWO
		
		AND R0,R0,#0
		ADD R0,R0,R4		; R0 = original again
		JSR LESSNINE

END_P		ADD R6,R4,#0
		RET			; END OF SUBROUTINE		

LESSTWO		ADD R0,R0,#-2 		; R0 <-[R0-2]
		BRn DISP_ERR
		RET		

LESSNINE	ADD R0,R0,#-9		; R0 <-[R0-9]
		BRp DISP_ERR
		RET

DISP_ERR	AND R0,R0,#0	
		LEA R0,ERRORSIZE	; load the address of the ERRORSIZE string into R7
		PUTS            	; print the ask age string
		BRnzp DISP_ASK

ASKSIZE	.STRINGZ "\nPlease enter the size of your board[2..9]:\n" ; The words that should be displayed to ask size
ERRORSIZE .STRINGZ "\nYour input is not valid!\n"	; The words that should be displayed if the input is not valid
.END

