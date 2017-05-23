#include <stdio.h>
#include <stdlib.h>

#define N 10
int array[N][N];

int main() {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            array[i][j] = i + j;
    int min = array[0][0];
    for (i = 1; i < N; i++)
        for (j = 1; j < N; j++)
            if (array[i][j] < min)
                min = array[i][j];
    printf("%d\n", min);
    return 0;
}

/*
	.file	"5_2.c"
	.intel_syntax noprefix
	.comm	array,400,64
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
.L5:
	mov	DWORD PTR [rbp-8], 0
	jmp	.L3
.L4:
	mov	edx, DWORD PTR [rbp-4]
	mov	eax, DWORD PTR [rbp-8]
	lea	ecx, [rdx+rax]
	mov	eax, DWORD PTR [rbp-8]		;<кусок кода, в котором производится обращение к массиву>
	movsx	rsi, eax
	mov	eax, DWORD PTR [rbp-4]	
	movsx	rdx, eax
	mov	rax, rdx
	sal	rax, 2				;сдвиг <-
	add	rax, rdx
	add	rax, rax
	add	rax, rsi
	mov	DWORD PTR array[0+rax*4], ecx	;</кусок кода, в котором производится обращение к массиву>
	add	DWORD PTR [rbp-8], 1		
.L3:
	cmp	DWORD PTR [rbp-8], 9
	jle	.L4
	add	DWORD PTR [rbp-4], 1
.L2:
	cmp	DWORD PTR [rbp-4], 9
	jle	.L5
	mov	eax, DWORD PTR array[rip]
	mov	DWORD PTR [rbp-12], eax
	mov	DWORD PTR [rbp-4], 1
	jmp	.L6
.L10:
	mov	DWORD PTR [rbp-8], 1
	jmp	.L7
.L9:
	mov	eax, DWORD PTR [rbp-8]
	movsx	rcx, eax
	mov	eax, DWORD PTR [rbp-4]
	movsx	rdx, eax
	mov	rax, rdx
	sal	rax, 2
	add	rax, rdx
	add	rax, rax
	add	rax, rcx
	mov	eax, DWORD PTR array[0+rax*4]
	cmp	eax, DWORD PTR [rbp-12]
	jge	.L8
	mov	eax, DWORD PTR [rbp-8]
	movsx	rcx, eax
	mov	eax, DWORD PTR [rbp-4]
	movsx	rdx, eax
	mov	rax, rdx
	sal	rax, 2
	add	rax, rdx
	add	rax, rax
	add	rax, rcx
	mov	eax, DWORD PTR array[0+rax*4]
	mov	DWORD PTR [rbp-12], eax
.L8:
	add	DWORD PTR [rbp-8], 1
.L7:
	cmp	DWORD PTR [rbp-8], 9
	jle	.L9
	add	DWORD PTR [rbp-4], 1
.L6:
	cmp	DWORD PTR [rbp-4], 9
	jle	.L10
	mov	eax, DWORD PTR [rbp-12]
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
