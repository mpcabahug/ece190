; Michelle Cabahug (working with Kevin Boldingh) Fall 2013

; This file should be submitted in both mp2.1 and mp2.2

;Subroutine is passed a size in R6.
;Uses this to construct a grid that is size x size of char '1's

;R0 = value or new line
;R2 = GAMEBOARD address
;R4 = counter
;R6 = passed board size
;R1 = stores new line to be used in R0

        	.ORIG x3200
       
PRINTBOARD	AND R1,R1,#0

	        AND R5,R5,#0	        ; clear R5
		ADD R5,R5,R6       	; copy R6 to R5 for later
		
		AND R4,R4,#0        	; clear R4
		ADD R4,R4,R6        	; copy R6 to R4 as decrementor

	        LD R2,GAMEBOARD    	; R2 = x3600 
	        LEA R1,NEW_LINE    	; load the address of the NEW_LINE string into R1
		
		AND R0,R0,#0
		ADD R0,R1,#0
		PUTS			; blank row at the beginning		 

ONE_ROW		AND R0,R0,#0        	; clear R0
		LDR R0,R2,#0		; R0 = value at address held in R2	
		OUT               	; prints R0
	   	ADD R2,R2,#1        	; increments address (offset)
		ADD R4,R4,#-1       	; decrement
		BRp ONE_ROW        	; keep going until R4 = 0

CHECK_ROW	ADD R6,R6,#-1        	; decrements row counter
		BRz END_P		; if 0 end PRINTBOARD
		AND R0,R0,#0        	; clear R0
		ADD R0,R1,#0  	
		PUTS            	; new row       
		AND R4,R4,#0
		ADD R4,R4,R5        	; otherwise reload decrementor with row size
		BRnzp ONE_ROW        	; print out another row           
       
END_P 		AND R6,R6,#0			
		ADD R6,R6,R5        	; R6 back to original board size
		AND R0,R0,#0
		ADD R0,R1,#0
		PUTS			; blank row at the end
		RET			; end of PRINTBOARD subroutine
               
NEW_LINE	.STRINGZ "\n"    	; blank space
GAMEBOARD	.FILL x3600      	; GAMEBOARD start

        	.END
