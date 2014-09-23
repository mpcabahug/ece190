;Answer problem 5 here


		.ORIG x3000

CHECK_A		ADD R2,R2,#0
		BRn CONVERT_A
		ADD R2,R2,#0
		BRz ZERO_MOD
		
CHECK_B		ADD R3,R3,#0
		BRp FIRST
		ADD R3,R3,#0
		BRn SEC
		AND R4,R4,#0
		BRnzp FIRST

CONVERT_A	NOT R2,R2
		ADD R2,R2,#1
		BRnzp CHECK_B

FIRST		NOT R3,R3
		ADD R3,R3,#1	 ; makes for -B
SEC		ADD R1,R2,R3	 ; R1 <-[A-B]
		BRn MODULO	 ; if already negative, get the mod
		ADD R1,R1,#0
		BRz ZERO_MOD	 ; if already 0, make R4 = 0
				
LOOP		ADD R1,R1,R3	 ; [A-B] - B
		BRp LOOP 	 ; still remainder, keep subtracting
		ADD R1,R1,#0 	 
		BRn MODULO       ; if negative, get mod
		ADD R1,R1,#0
		BRz ZERO_MOD     ; if if B is multiple of A, mod = 0

MODULO		NOT R3,R3
		ADD R3,R3,#1	 ; R3 = B again
		ADD R4,R1,R3	 ; R4 = value of R1 before it went negative
		BRnzp END_P

ZERO_MOD	AND R4,R4,#0
		BRnzp END_P

END_P		HALT

		.END
