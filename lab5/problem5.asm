;Answer problem 5 here; R0 = address of current character
; R1 = current character
; R2 = string length count
; R3 = output
; R4 = first character
; R5 = last character

		.ORIG x3000
		
		AND R3,R3,#0	; clear R3
		ADD R3.R3.#1	; add 1 to R3
		LEA R0,TESTSTR	; R0 <- address of current character

LOOPTOP		LDR R1,R0,#0 	; load the current char into R1
		BRz LOOPNEXT	; if at null terminator, we donezo
		ADD R2,R2,#1	; add to counter if not null terminator
		ADD R0,R0,#1 	; make R0 point to next character address
				; R0 will have address of last character at end of loop

LOOPNEXT	LDR R4,R0,#0	; load last character into R4
		NOT R2,R2	; make value of R2 negative
		ADD R0,R0,R2	; subtract counter from address of last character
		LDR R5,R0,#0	; load first character into R5
		NOT R4,R4	; make last character negative
		ADD R5,R5,R4	; subract first and last character
		BRz PALLIN	; if first = last, finish
		BRnp NOTPAL	; if first =/= last, clear R3

NOTPAL		AND R3,R3,#0	; clear R3 if not pallindrome

PALLIN		HALT	
INPUT		.FILL x4000
TESTSTR		.STRINGZ INPUT
		.END
