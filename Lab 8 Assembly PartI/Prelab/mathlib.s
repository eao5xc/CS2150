	;Pat Wongwiset
	;nw9ca@virginia.edu
	;10/29/17
	; mathlib.s
	; 1st param rdi
	; 2nd param rsi
	global product, power

	section .text

product:
	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start:	
	cmp	r10, rsi	 ; does i == n?
	je	done		 ; if so, end  the loop
	add	rax, rdi	 ; add rdi
	inc	r10		 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	
	; no callee-saved registers to restore, and we do not
	; no any local variables to deallocate
	ret

power:
	xor	rax, rax	; set return to 0
	mov	rax, 1
base:
	cmp	rsi, 0		; does rsi = 0?
	je	end		; if so, return val in rax
recurse:
	dec	rsi
	call 	power		; call recursively by passing two param (rax = power(rdi, rsi-1) )
	mov	rsi, rax	; move rax to rsi
	call	product	; call product to be base(rdi) * power(rdi, rsi - 1)
end:
	ret		
