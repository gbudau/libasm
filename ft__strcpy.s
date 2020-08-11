			global		ft__strcpy

			section		.text
ft__strcpy:
			push		rsi
			push		rdi
			cld						; clear direction flag

.cpy_loop:
			lodsb					; load AL & increment rsi(src)
			stosb					; store AL & increment rdi(dst)
			or			al, al		; set condition flag if al is zero
			jnz			.cpy_loop	; if not past terminating zero, continue

			pop			rdi
			pop			rsi
			mov			rax, rdi	; copy dst address to rax to return it
			ret