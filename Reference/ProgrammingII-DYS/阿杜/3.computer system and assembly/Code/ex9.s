	.file	"ex9.c"
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
	mov	DWORD PTR [esp+4], 2
	mov	DWORD PTR [esp+8], -6
	mov	DWORD PTR [esp+12], 10000
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
