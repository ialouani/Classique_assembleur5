	section .text
 	global evalExpr
 evalExpr:
	 push 4
	 push rdi
	 pop r8
 	 pop r9
 	 add r8,r9
 	 push r8
	 push rsi
	 pop r8
 	 pop r9
 	 imul r8,r9
 	 push r8
fin:
	 pop rax
	 ret
