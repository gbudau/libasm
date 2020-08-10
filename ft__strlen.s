		global		ft__strlen			; make ft__strlen visible by linker

		section .text:					; specify start of read only part
ft__strlen:
		mov		rax, -1					; set rax to -1 (will use it as index)
.loop:
		cmp		byte [rdi + rax + 1], 0	; check if the char at s1 + idx + 1 is zero
		lea		rax, [rax + 1]			; increment rax, lea does not alter flags
		jne		.loop					; keep looping if string has not reach end
		ret								; return rax which contain the length of string
