#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {

    int * arr_dig = (int*) malloc (sizeof(int) * N);//[rbp-16]
    float * arr_float = (float*) malloc (sizeof(float) * N);//[rbp-24]

    int sum1 = 0; //[rbp-28]
    float sum2 = 0;//[rbp-32]

    int i;
    for (i = 0; i < N; i++) {
        arr_dig[i] = 1 + i;
        arr_float[i] = 1.0 + i;
    }

    /*for (i = 0; i < N; i++) {
        sum1 += arr_dig[i];
        sum2 += arr_float[i];
    }*/

    asm volatile(
      ".intel_syntax noprefix;\n"
      "mov DWORD PTR [rbp-4], 0\n" //12->4
	".L5:\n"
	    "mov eax, DWORD PTR [rbp-4]\n" //12
	    "cdqe\n"
	    "lea rdx, [0+rax*4]\n" //обнулить?
	    "mov rax, QWORD PTR [rbp-16]\n" //24
	    "add rax, rdx\n"
	    "mov eax, DWORD PTR [rax]\n"
	    "add DWORD PTR [rbp-28], eax\n" //4
	    "mov eax, DWORD PTR [rbp-4]\n" //12
	    "cdqe\n"
	    "lea rdx, [0+rax*4]\n"
	    "mov rax, QWORD PTR [rbp-24]\n" //32
	    "add rax, rdx\n"
	    "movss   xmm0, DWORD PTR [rax]\n"
	    "movss   xmm1, DWORD PTR [rbp-32]\n" //8
	    "addss   xmm1, xmm0\n"
	    "movd    eax, xmm1\n"
	    "mov DWORD PTR [rbp-32], eax\n"
	    "add DWORD PTR [rbp-4], 1\n" //counter
	".L4:\n"
	    "cmp DWORD PTR [rbp-4], 9\n"
	    "jle .L5\n"
      ".att_syntax noprefix;"
    );

    printf("Sum1 = %d\nSum2 = %d\n", sum1, sum2);

    return 0;
}

/*
main:
.LFB2:
    .cfi_startproc
    push    rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    mov rbp, rsp
    .cfi_def_cfa_register 6
    sub rsp, 32
    mov edi, 40
    call    malloc
    mov QWORD PTR [rbp-16], rax
    mov edi, 40
    call    malloc
    mov QWORD PTR [rbp-24], rax
    mov DWORD PTR [rbp-28], 0
    mov eax, DWORD PTR .LC0[rip]
    mov DWORD PTR [rbp-32], eax
    mov DWORD PTR [rbp-4], 0
    jmp .L2
.L3:
    mov eax, DWORD PTR [rbp-4]
    cdqe
    lea rdx, [0+rax*4]
    mov rax, QWORD PTR [rbp-16]
    add rax, rdx
    mov edx, DWORD PTR [rbp-4]
    add edx, 1
    mov DWORD PTR [rax], edx
    mov eax, DWORD PTR [rbp-4]
    cdqe
    lea rdx, [0+rax*4]
    mov rax, QWORD PTR [rbp-24]
    add rdx, rax
    pxor    xmm0, xmm0
    cvtsi2sd    xmm0, DWORD PTR [rbp-4]
    movsd   xmm1, QWORD PTR .LC1[rip]
    addsd   xmm0, xmm1
    cvtsd2ss    xmm2, xmm0
    movd    eax, xmm2
    mov DWORD PTR [rdx], eax
    add DWORD PTR [rbp-4], 1
.L2:
    cmp DWORD PTR [rbp-4], 9
    jle .L3
    mov eax, 0
    leave
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE2:
    .size   main, .-main
    .section    .rodata
    .align 4
.LC0:
    .long   0
    .align 8
.LC1:
    .long   0
    .long   1072693248
    .ident  "GCC: (Debian 4.9.2-10) 4.9.2"
    .section    .note.GNU-stack,"",@progbits
*/
