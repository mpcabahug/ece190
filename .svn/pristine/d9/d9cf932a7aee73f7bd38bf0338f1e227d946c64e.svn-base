; Michelle Cabahug (working with Kevin Boldingh (boldngh2) Fall 2013

; This file should be submitted in both mp2.1 and mp2.2
;Allows user to choose a character in the printboard table
;User enters a row and column number and that data is returned via R4 and R5

; R6 = size, R4 = column number, R5 = row number, R2 = -R6
; R3 = R7 initial ret value

		.ORIG x3300
		
GETINPUT	AND R3, R3, #0
		ADD R3, R7,#0
		AND R2,R2,#0	
		NOT R2,R6		
		ADD R2, R2, #1; inputsize = -inputsize

DISP_ASKROW	AND R0,R0,#0		; clear R0
		LEA R0,ASKROW 		; load the address of the ASKROW string into R0
		PUTS            	; print the ASKROW string
		AND R0,R0,#0		; clear R0 again	
		GETC			; R0 = input number
		OUT			; displays input number
		ADD R0,R0,#-16
		ADD R0,R0,#-16
		ADD R0,R0,#-16		; R0 is now decimal value (must subtract #48)
		BRnz DISP_ERR1		; if R0 = 0, error
		JSR CHECK_ROW
		AND R5,R5,#0		; clear R5
		ADD R5,R5,R0		; R5 = row number		

DISP_ASKCOL	AND R0,R0,#0		; clear R0
		LEA R0,ASKCOLUMN 	; load the address of the ASKCOLUMN string into R0
		PUTS            	; print the ASKCOLUMN string
		AND R0,R0,#0		; clear R0 again	
		GETC			; R0 = input number
		OUT			; displays input number
		ADD R0,R0,#-16
		ADD R0,R0,#-16
		ADD R0,R0,#-16		; R0 is now decimal value (must subtract #48)
		BRnz DISP_ERR2		; if R0 = 0, error
		JSR CHECK_COL
		AND R4,R4,#0		; clear R4
		ADD R4,R4,R0		; R4 = column number

END_P		AND R6, R6, #0
		NOT R6, R2		; R6 = original value again
		ADD R6,R6,#1
		AND R7, R7, #0
		ADD R7, R3,#0		
		RET			; end of subroutine GETINPUT

CHECK_ROW	AND R1,R1,#0		; clear R1
		ADD R1,R0,R2		; R1 <- [R0 - R6]
		BRp DISP_ERR1
		RET

CHECK_COL	AND R1,R1,#0		; clear R1
		ADD R1,R0,R2		; R1 <- [R0 - R6]
		BRp DISP_ERR2
		RET

DISP_ERR1	AND R0,R0,#0	
		LEA R0,ERRORINPUT	; load the address of the ERRORINPUT string into R0
		PUTS            	; print the ERRORINPUT string
		BRnzp DISP_ASKROW

DISP_ERR2	AND R0,R0,#0	
		LEA R0,ERRORINPUT	; load the address of the ERRORINPUT string into R0
		PUTS            	; print the ERRORINPUT string
		BRnzp DISP_ASKCOL

R7VALUE .BLKW 1		; The memory reserved for R7
ASKROW .STRINGZ "\nPlease input a valid row number:\n"	; The words that should be displayed to ask row number
ASKCOLUMN .STRINGZ "\nPlease input a valid column number:\n" ; The words that should be displayed to ask column number
ERRORINPUT .STRINGZ "\nYour input is not valid."	; The words that should be displayed if the input is not valid
		.END



