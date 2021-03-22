section	.text
	global	_ft_strcpy

; rdi : dest, rsi : src
_ft_strcpy:
	mov	rax, rdi
	mov	rcx, 0
	jmp	cpy

cpy:
	mov			dl, byte [rsi + rcx]
	mov			byte [rax + rcx], dl
	cmp			byte [rsi + rcx], 0
	je			end
	inc			rcx
	jmp			cpy

end:
	ret
