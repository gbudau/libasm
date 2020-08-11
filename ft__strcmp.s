		global	ft__strcmp

		section .text:
ft__strcmp:
		xor		rcx, rcx					; set rcx to 0, use it as counter
		xor		rax, rax					; set rax to 0, use it to store src chars
		xor		rdx, rdx					; set rdx to 0, use it to store dst chars

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
		ret									; return
