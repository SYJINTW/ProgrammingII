	.file	"ex5.c"
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
	cmp	DWORD PTR [esp+12], 3
	jle	L2
	add	DWORD PTR [esp+8], 1
L2:
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
