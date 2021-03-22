section.text:
	global _ft_strcmp
;rdi : s1, rsi :s2
_ft_strcmp:
	mov	rcx, -1
	jmp compare

compare:
	inc	rcx
	mov	dl, byte [rdi + rcx]
	mov	al, byte [rsi + rcx]
	cmp dl, 0
	jz	dl_null
	cmp al, 0
	jz	al_null
	cmp	dl, al
	ja	is_above
	jb	is_below
	je	compare

dl_null:
	cmp al, 0
	jz	is_equl
	jmp	is_below

al_null:
	cmp dl, 0
	jz	is_equl
	jmp	is_above

is_equl:
	mov rax, 0
	ret

is_above:
	mov rax, 1
	ret

is_below:
	mov rax, -1
	ret
