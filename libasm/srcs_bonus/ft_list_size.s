section	.text
	global	_ft_list_size
	extern	___error

; rdi:begin_list
_ft_list_size:
	xor		rax, rax
	jmp		_lsize

_lsize:
	cmp		rdi, 0
	jz		end
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		_lsize

end:
	ret
