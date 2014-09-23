;Answer problem 6 here

		.ORIG x3000
		
		ADD R2,R2,#0
		BRz NOT_PWR	 ; if R2 is 0, it is not a power of 2
		AND R1,R1,#0	 ; clears R1
		ADD R1,R2,#-1	 ; R1 <-[N-1]
		AND R4,R1,R2	 ; R4 <-[N & (N-1)]
		BRz IS_PWR	 ; if R4 = 0, N is pwr of 2
NOT_PWR		AND R3,R3,#0	 ; otherwise R3 = 0
		BRnzp END_P

IS_PWR		AND R3,R3,#0
		ADD R3,R3,#1
		BRnzp END_P

END_P		HALT
		.END
