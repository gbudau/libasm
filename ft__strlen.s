		global		ft__strlen			; make ft__strlen visible by linker

		section .text					; specify start of read only part
ft__strlen:
	mov		rcx, 0FFFFFFFFFFFFFFFFh		; use largest possible RCX
	xor		al, al						; al = 0
	cld									; clear flag direction

	repnz scasb							; scan for teminating 0

;
; repnz will go one step too far, so length is FFFFFFFFFFFFFFFE - RCX,
; FFFFFFFFFFFFFFFF - RCX
;

	mov		rax, 0FFFFFFFFFFFFFFFEh
	sub		rax, rcx					; length = 0FFFFFFFFFFFFFFFEh - rcx
	ret									; return
