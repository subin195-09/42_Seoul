section	.data
	message	db	"Hello, World!", 10

section	.text
global	_hello

_hello:
	mov rax, 0x2000004
	syscall
	ret
