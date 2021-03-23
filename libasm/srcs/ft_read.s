section	.text
	global	_ft_read
	extern	___error

; fdi:fd, rsi:buf, rdx:size
_ft_read:
	mov rax, 0x2000003
	syscall
	jc error
	ret

error:
	push	rax
	call	___error
	pop		rdx
	mov		[rax], rdx
	mov		rax, -1
	ret
