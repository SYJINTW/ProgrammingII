	.file	"ex11.c"
	.intel_syntax noprefix
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "foo=%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	push	ebx
	and	esp, -16
	sub	esp, 32
	call	___main
	mov	DWORD PTR [esp+28], 10
	mov	DWORD PTR [esp+24], 15
	mov	eax, DWORD PTR [esp+28]
	mov	edx, DWORD PTR [esp+24]
	mov	ebx, edx
/APP
 # 7 "ex11.c" 1
	add %ebx,%eax
 # 0 "" 2
/NO_APP
	mov	DWORD PTR [esp+28], eax
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_printf
	mov	eax, 0
	mov	ebx, DWORD PTR [ebp-4]
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
	.def	_printf;	.scl	2;	.type	32;	.endef
