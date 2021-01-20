	.file	"ex7.c"
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
	lea	eax, [esp+8]
	mov	DWORD PTR [esp+12], eax
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
