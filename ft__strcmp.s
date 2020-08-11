		global	ft__strcmp

		section .text:
ft__strcmp:
		push	rsi							; save rsi
		push	rdi							; save rdi on stack
		push	rcx							; save rcx on stack
		push	rdx							; save rdx on stack
		xor		rcx, rcx					; use rcx as counter
		xor		rax, rax					; set rax to 0
		xor		rdx, rdx					; set rdx to 0

.cmp_loop:
		mov		al, byte [rdi + rcx]		; move first char of first str into rax
		mov		dl, byte [rsi + rcx]		; move first char of sec str into rdx
		test	al, al						; test if al is 0
		je		.done						; jump to done if its 0
		test	dl, dl						; test if dl is 0
		je		.done						; jump to done if its 0
		cmp		al, dl						; compare the two characters
		jne		.done						; jump to done if not equal
		add		rcx, 1						; increment the counter
		jmp		.cmp_loop					; keep looping
.done:
		sub		rax, rdx					; substract the two characters
		pop		rdx							; restore rdx
		pop		rcx							; restore rcx
		pop		rdi							; restore rdi
		pop		rsi							; restore rsi
		ret									; return
