		global		ft_read
		extern		__errno_location

		section		.text
ft_read:
			mov		rax, 0						; syscall code for read, other parameters are on the stack
			syscall								; make syscall
			test	rax, rax					; error checking, set flags
			jl		.error						; if rax is less than 0 jump to error
			ret									; return

.error:
			mov		rcx, rax					; copy error code in rcx
			call	__errno_location wrt ..plt	; save address of errno in rax
			neg		rcx							; change rcx sign (since it is negative will convert to positive)
			mov		[rax], rcx					; move the value of rcx (error code) into the value pointed by rax (errno variable)
			mov		rax, -1						; set rax to -1
			ret									; return
