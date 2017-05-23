#include <stdio.h>
#include <stdlib.h>

#define N 10
int array[N];

int main() {
    int i;
    for (i = 0; i < N; i++)
        array[i] = i;
    int min = array[0];
    for (i = 1; i < N; i++)
        if (array[i] < min)
            min = array[i];
    printf("%d\n", min);
    return 0;
}

/*
	.file	"5_1.c"
	.intel_syntax noprefix
	.comm	array,40,32
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR [rbp-4], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	mov	edx, DWORD PTR [rbp-4]
	mov	DWORD PTR array[0+rax*4], edx
	add	DWORD PTR [rbp-4], 1
.L2:
	cmp	DWORD PTR [rbp-4], 9
	jle	.L3
	mov	eax, DWORD PTR array[rip]
	mov	DWORD PTR [rbp-8], eax
	mov	DWORD PTR [rbp-4], 1
	jmp	.L4
.L6:
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	mov	eax, DWORD PTR array[0+rax*4]
	cmp	eax, DWORD PTR [rbp-8]
	jge	.L5
	mov	eax, DWORD PTR [rbp-4]
	cdqe
	mov	eax, DWORD PTR array[0+rax*4]
	mov	DWORD PTR [rbp-8], eax
.L5:
	add	DWORD PTR [rbp-4], 1
.L4:
	cmp	DWORD PTR [rbp-4], 9
	jle	.L6
	mov	eax, DWORD PTR [rbp-8]
	mov	esi, eax
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	printf
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
*/
