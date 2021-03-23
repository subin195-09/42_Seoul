section	.text
	global	_ft_atoi_base
	extern	_ft_strlen
	extern	_malloc
	extern	___error

; rdi:str, base:rsi
_ft_atoi_base:
	push	rdi
	mov		rdi, rsi
	call	_ft_strlen
	cmp		rax, 2
	jb		error
	jmp		atoi

atoi:
	

error:
	push	rax
	call	___error
	pop		rdx
	mov		[rax], rdx
	mov		rax, -1
	ret

