.ORIG x3000

INSERT
INSERT_REC	; DO NOT EDIT THIS LINE. IT WILL BE EDITED DURING GRADING
; callee setup
ADD R6,R6,#-1	;1st parameter
ADD R6,R6,#-1	;2nd parameter
ADD R6,R6,#-1	;3rd parameter
ADD R6,R6,#-1	;return value
ADD R6,R6,#-1	;R5 save
STR R5,R6,#0	;save R5 in specified memory
ADD R6,R6,#-1	;R7 save
STR R7,R6,#0	;save R7 in specified memory
ADD R6,R6,#-1	; current_node->next
ADD R6,R6,#-1	; reserved_node->value
ADD R6,R6,#-1	; reserved_node->next
ADD R5,R6,#4	; R5 points to bottom of local vars??

; Check for base case IF STATEMENT
LDR R0,R6,#6	; load number into R0
LDR R1,R6,#8	; load current node into R1??
NOT R0,R0	; 
ADD R0,R0,R1	; setcc
BRp RET_R0	; doesn't go into if statement

; Base case implementation. If you set up R5 correctly and implement
; RET_R0 correctly, this code works. However, you have NO OBLIGATION
; to use this code.
LDR R0, R5, #4	; R0 <- current_node
LDR R1, R5, #5	; R1 <- reserved_node
STR R1, R0, #1	; current_node->next = reserved_node
LDR R0, R5, #6	; R0 <- number
STR R0, R1, #0	; reserved_node->value = number
LDR R0, R5, #0	; R0 <- next_node
STR R0, R1, #1	; reserved_node->next = next_node
ADD R0, R0, #0	; R0 <- 0
ADD R0, R0, #1	; R0 <- 1
BRnzp RET_R0	; return R0: YOU MUST IMPLEMENT

	; caller setup
ADD R6,R6,#-1	; make room to push on stack

JSR INSERT_REC	; make recursive call

	; caller teardown
ADD R6,R6,#1	; i have no idea wtf is happening

RET_R0
;return
STR R0,R6,#5	; store R0 in ret val place


; callee teardown
ADD R6,R6,#8	; return R6 to bottom
LDR R5,R6,#4
LDR R7,R6,#5
RET

.END
