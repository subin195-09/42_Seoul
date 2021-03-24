section	.text
	global	_ft_list_push_front
	extern	_malloc

; rdi:**list , rsi:*data
; sizeof(t_list) = 16
; t_list 의 앞 data 8, 뒤의 next포인터 8을 쓴다.
_ft_list_push_front:
	push	rdi	;받은 인자 저장
	push	rsi
	mov		rdi, 16	;t_list 사이즈 만큼 할당
	call	_malloc
	cmp		rax, 0
	jz		error
	pop		rsi
	pop		rdi
	mov		[rax], rsi	;앞에 주소를 참조하여 data 저장
	mov		rcx, [rdi]
	mov		[rax + 8], rcx ;뒤의 8자리에 t_list의 원래 첫번째 였던 주소를 저장
	mov		[rdi], rax ;리스트의 헤드 변경
	ret

error:
	ret
