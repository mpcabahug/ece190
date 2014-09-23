        .ORIG x3000

        LD R0, N    	; load R0 with the value to be passed into the subroutine.
 	AND R3,R3,#0
	ADD R3,R3,#3	; R3 = #3 (number of times we add N to itself)
	AND R4,R4,0
	ADD R4,R4,#4 	; R4 = #4 (added to 3N)
        JSR SUB     	

        HALT     
 
SUB	ADD R0,R0,R0
	ADD R3,R3,#-1
	BRp SUB
	ADD R0,R0,R4
        RET       
 
N       .FILL #VALUE    ; value of N
 
SaveReg     .FILL x0000 ; space for the subroutine to save and restore registers it will 			alter.
 
RESULT      .FILL x0000 ; 
 
        .END        ; end directive
