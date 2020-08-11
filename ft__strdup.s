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
		test	rax, rax			; check if there was an error and rax is NULL
		je		.error				; jump to .error in case rax is NULL
		mov		rcx, rax			; save address of allocated space into rcx
.copy:
		mov		rdi, rax			; set dst to malloc return address
		pop		rsi					; restore rdi into rsi
		call	ft__strcpy			; copy string from src to dst
.done:
		mov		rax, rcx			; set rax to address of allocated memory
		ret							; return the address of allocated memory

.error:
		ret							; return in case of error, rax will be NULL
