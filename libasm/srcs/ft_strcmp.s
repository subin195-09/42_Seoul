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
	jz	cmp_null
	cmp al, 0
	jz	cmp_null
	cmp	dl, al
	ja	is_above
	jb	is_below
	jz	compare

cmp_null:
	cmp	dl, al
	ja	is_above
	jb	is_below
	jz	is_equl

is_equl:
	mov rax, 0
	ret

is_above:
	mov rax, 1
	ret

is_below:
	mov rax, -1
	ret
