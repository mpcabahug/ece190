;int factorial(int n)
;{
;   if (n==0)
;    {
;        return 1;
;    }
;    return n*factorial(n-1);
;}
;	AT CALL
;	n <- R6

;	STEADY STATE
;	R7 save
;	R5 save
;	return val
;	n
;	
;	AT RETURN
;	return value <- R6
;	n
		.ORIG x3000
	
FACTORIAL	ADD R6,R6,#-1	; allocate space for return value
		
		; store R7 and R5
		ADD R6,R6,#-1	; R5 save
		STR R5,R6,#0
		ADD R6,R6,#-1	; R7 save
		STR R7,R6,#0

		; no local variables, look at that!

		; load R0 with the parameter
		LDR R0,R6,#3	; R0 <-[n]
		ADD R1,R0,#0	; check if R0 = 0
		BRnp FAC_REC	; if its not 0, get recursive in this bitch
		AND R0,R0,#0	; if R0 =0, return 1
		ADD R0,R0,#1	
		BRnzp END_P	;
		
		; time to get recursive in this bitch
		; compute n * factorial(n-1)
		; caller - built stack for factorial(n-1) call
		; so we have to push n-1 into the stack

FAC_REC		ADD R6,R6,#-1	; allocate space (n-1)
		STR R2,R6,#0	; R2 <- [address of (n-1)]

		JSR FACTORIAL	; does factorial(n-1)
		
		; pop function argument from the run-time stack to R0
		LDR R0,R6,#0	
		ADD R6,R6,#1	; increment top of stack pointer

		; pop function argument from the run-time stack
		ADD R6,R6,#1	;
		
		; multiply n by the return value (which is already in R0)
		LDR R1,R5,#?	
		MUL R0,R0,R1	; R0 <- n * factorial(n-1)

		STR R0,R5,#0	; store result in memory
		BRnzp RETURN;

RETURN		;get them return values
		LDR R0,R5,#0
		STR R0,R5,#1
		
END_P		;restore caller's frame pointer and return address
		; callee teardown
		LDR R5,R6,#0
		ADD R6,R6,#1
		LDR R7,R6,#0
		ADD R6,R6,#1
		RET		; R0 has return value



























