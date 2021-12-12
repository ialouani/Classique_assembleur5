	 section .text
 	 global evalExpr
 evalExpr:
	 mov r10,0 
  boucle:
	 mov r11,[rdi+r10*8]
 	 push r11 
	 mov r12,[rsi+r10*8]
 	 push r12 
	 pop r8
 	 pop r9
 	 imul r8,r9
 	 push r8
	 pop r13 
 	 lea r15,[rdi+r10*8] 
 	 mov [r15],r13
	 inc r10 
	 mov r14,0 
 	 cmp [rsi+r10*8],r14 
 	 jne boucle
fin:
 	 ret