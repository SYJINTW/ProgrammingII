#include <stdio.h>

int main(void)
{
  int foo = 10, bar = 15;

  asm(
    "add %%ebx,%%eax"
    :"=a"(foo)
    :"a"(foo), "b"(bar)
  );

  printf("foo=%d\n", foo);
  return 0;
}
/*
  compile with
     gcc -S -masm=intel ex9.c
  the output is
  ----------------------------------
	.file	"ex9.c"
	.intel_syntax noprefix
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "foo=%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB6:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	ebx
	and	esp, -16
	sub	esp, 32
	.cfi_offset 3, -12
	call	___main
	mov	DWORD PTR [esp+28], 10
	mov	DWORD PTR [esp+24], 15
	mov	eax, DWORD PTR [esp+28]
	mov	edx, DWORD PTR [esp+24]
	mov	ebx, edx
/APP
 # 7 "ex9.c" 1
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
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
	.ident	"GCC: (GNU) 4.8.1"
	.def	_printf;	.scl	2;	.type	32;	.endef

*/
