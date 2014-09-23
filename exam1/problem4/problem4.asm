;Answer problem 4 here
		
		.ORIG x3000
		AND R0,R0,#0	 ; clear R0
		AND R1,R1,#0	 ; clear R1
		AND R4,R4,#0	 ; clear R4 (stays 0 if no x5)
		AND R5,R5,#0
		ADD R5,R5,#-5	 ; R5 = #-5
		AND R7,R7,#0	 
		ADD R7,R7,#8	 ; how many addresses
		LEA R0,MEM_START ; address of 1st memory location in R0
		
LOOP		LDR R1,R0,#0	 ; value of thing at address that R0 contains
		ADD R6,R1,R5	 ; R6 <-[number - 5]
		BRz FOUND	 ; if number =5, done
		ADD R0,R0,#1	 ; R0 points to next address
		ADD R7,R7,#-1    ; loop counter (address counter too)
		BRz END_P        ; if we pass 8 addresses, done
		ADD R7,R7,#0     ; dummy step
		BRnzp LOOP	 ; look at next value

FOUND		ADD R4,R4,#1
		BRnzp END_P

END_P		HALT

MEM_START		.FILL x4100

		.END
