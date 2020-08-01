section.text:
	global	ft__strlen

ft__strlen:
			push	rdi				; save the registers that we will use
			push	rcx

			xor		rcx, rcx		; set rcx to 0
			not		rcx				; set rcx to -1 or 18446744073709551615

			xor		al, al			; the byte that we compare to is zero
									; C end of string '\0' so set 'al' to zero

			cld						; clear direction flag
	repne	scasb					; scan string compare 'al' with byte at 'rdi'
									; repeat if not equal to the value or 'al'

			not		rcx				; we started from -1 then decreased until
									; after 'al' was found so the value is '- strlen - 2'
									; or 'strlen + 2'
									; doing 'not' its like abs(strlen) - 1 so  now we have
									; rcx = strlen + 1

			lea		rax, [rcx-1]	; store 'rcx-1' into 'rax'

			pop		rcx				; restore the registers that we used
			pop		rdi

			ret						; done
