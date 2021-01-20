	.file	"ex6.c"
	.intel_syntax noprefix
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	call	___main
	jmp	L2
L3:
	add	DWORD PTR [esp+12], 1
L2:
	cmp	DWORD PTR [esp+8], 3
	jle	L3
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
