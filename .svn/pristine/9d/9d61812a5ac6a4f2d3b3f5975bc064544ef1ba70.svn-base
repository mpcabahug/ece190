        .ORIG x3000

        LD R0, N    	; load R0 with the value to be passed into the subroutine.
 	AND R3,R3,#0
	ADD R3,R3,#3	; R3 = #3 (number of times we add N to itself)
	ST R3, SAVE_R3
	AND R4,R4,0
	ADD R4,R4,#4 	; R4 = #4 (added to 3N)
	AND R5,R5,#0
	ADD R5,R5,#3	; R5 = #3 (number of times SUB_2 iterates)
        JSR SUB 
	JSR SUB_2    	

	ADD R0,R4,#0	; +4
        HALT     
 
SUB	ADD R0,R0,R0
	ADD R3,R3,#-1
	BRp SUB
	ADD R0,R0,R4
	ST R0,RESULT
        RET      

SUB_2	LD R0,RESULT    ; load R0 with RESULT
	LD R3,SAVE_R3	; R3 = #3 again
	ADD R5,R5,#-1
	BRp SUB
	RET 
 
N       .FILL #VALUE    ; value of N
 
SAVE_R3     .FILL x4000 ; 
 
RESULT      .FILL x4001 ; 
 
        .END        ; end directive
