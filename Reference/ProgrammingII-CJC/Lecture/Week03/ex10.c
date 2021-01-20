int main(){
    int a[3];
    a[0] = 2;
    a[1] = -6;
    a[2] = 10000;
}

/*
  compile with
     gcc -S -masm=intel ex10.c
  the output is ex10.s
  ----------------------------------
	.file	"ex10.c"
	.intel_syntax noprefix
	.def	___main;	.scl	2;	.type	32;	.endef
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
	and	esp, -16
	sub	esp, 16
	call	___main
	mov	DWORD PTR [esp+4], 2
	mov	DWORD PTR [esp+8], -6
	mov	DWORD PTR [esp+12], 10000
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
	.ident	"GCC: (GNU) 4.8.1"

  */
