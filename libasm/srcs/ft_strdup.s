section	.text
	global	_ft_strdup
	extern	_ft_strlen
	extern	_ft_strcpy
	extern	_malloc

; rdi:src
_ft_strdup:
	push	rdi
	call	_ft_strlen	;rdi에 길이를 알고싶은 string을 넣어야함
	inc		rax
	mov		rdi, rax
	call	_malloc	;rdi에 할당하고 싶은 만큼의 사이즈를 넣어줘야함
	cmp		rax, 0
	jz		error
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy ;rdi에 dest, rsi에 src를 넣어줘야함
	ret

error:
	ret
