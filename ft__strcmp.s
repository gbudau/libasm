		global	ft__strcmp

		section .text:
ft__strcmp:
		mov		dl, byte [rdi]			; copy first char of s1 into rdx
		xor		eax, eax				; set eax to 0
		mov		r8b, byte [rsi]			; copy first char of s2 into r8
		test	dl, dl					; check if rdx is 0 (end of first string)
		je		.done					; jump to .done if it is
		mov		ecx, 1					; move 1 into ecx (will use this as counter)
.loop:
		test	r8b, r8b				; check if r8 is zero (end of second string)
		je		.diff					; jump to .diff if its zero
		cmp		dl, r8b					; compare the two chars at current index
		jne		.diff					; if they are not equal jump to .diff
		movzx	edx, byte [rdi + rcx]	; move the char from s1 + index into edx, zero extend
		movzx	r8d, byte [rsi + rcx]	; move the char from s2 + index into r8d, zero extend
		add		rcx, 1					; increment counter
		test	dl, dl					; test if fist first string reach end
		jne		.loop					; jump to .loop (keep looping) if not
		jmp		.done					; jump to .done if it reach the end
.diff:
		movsx	eax, dl					; move the char from s1 + index into eax, sign extend
.done:
		movsx	ecx, r8b				; move the char from s2 + index into ecx, sign extend
		sub		eax, ecx				; substract the char at s1 + index with s2 + index
		ret								; return the value of substraction
