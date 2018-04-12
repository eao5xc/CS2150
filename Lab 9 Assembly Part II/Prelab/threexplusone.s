	;Pat Wongwiset
	;nw9ca@virginia.edu
	;11/8/17
	;threexplusone.s
	;optimization: using bit shift for multiplication and division
	;		finding moludo by 'and' instruction
	; 1st param rdi
	global threexplusone

	section .text

threexplusone:
	push	rdx		; remainder
	push	rbp		; counter step
	mov	rbp, 0
	mov	rdx, 1		; to compare in modulo
base:				
	cmp	rdi, 1		; does rdi = 1?
	je	end		; if so, go to end
	and	rdx, rdi	; optimize: using and to find remainder
	cmp	rdx, 1	; if it's equal, go to odd
	je	odd
even:
	add	rbp,1
	sar	rdi, 1		; shift right to store new result
	call	threexplusone
	add	rbp, rax
	jmp	base
odd:
	add	rbp, 1
	mov	rdx, rdi
	sal	rdi, 1
	add	rdi, rdx
	add	rdi, 1
	call	threexplusone
	add	rbp, rax
	jmp	base
end:
	mov	rax, rbp
	pop	rbp
	pop	rdx
	ret		
