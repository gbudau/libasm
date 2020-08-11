		global		ft__strdup
		extern		malloc
		extern		ft__strlen
		extern		ft__strcpy

		section		.text
ft__strdup:
.length:
		push	rdi					; preserve rdi (string address)
		call	ft__strlen			; calculate length of string
.allocate:
		mov		rdi, rax			; copy length in rdi for malloc
		inc		rdi					; increment rdi for null byte
		call	malloc wrt ..plt	; allocate memory
		mov		rcx, rax			; save address of allocated space into rcx
.copy:
		mov		rdi, rax			; set dst to malloc return address
		pop		rsi					; restore rdi into rsi
		call	ft__strcpy			; copy string from src to dst
.done
		mov		rax, rcx			; set rax to address of allocated space
		ret
