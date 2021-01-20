	.file	"ex1.c"
	.intel_syntax noprefix
	.comm	_a, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	call	___main
	mov	DWORD PTR _a, 3
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
