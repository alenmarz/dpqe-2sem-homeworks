#include <stdio.h>

void read(char * str) {
    char c;
    int index = 0;
    while ((c = getchar()) != '\n')
        str[index++] = c;
    str[index] = '\0';
}

int main() {
    typedef struct {
        char FAMILY[20];
        char NAME[15];
        int AGE;
    } PERSON;
    PERSON me;
    read(me.FAMILY);
    read(me.NAME);
    scanf("%d", &me.AGE);
    printf("%s %s\n", me.FAMILY, me.NAME);
    return 0;
}

/*
	.file	"5_3.c"
	.intel_syntax noprefix
	.text
	.globl	read
	.type	read, @function
read:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-24], rdi
	mov	DWORD PTR [rbp-4], 0        ;i = 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [rbp-4]      
	lea	edx, [rax+1]                ;увеличение счетчика (i++)
	mov	DWORD PTR [rbp-4], edx      
	movsx	rdx, eax                ;в rdx запихивают неувеличенное значение
	mov	rax, QWORD PTR [rbp-24]     ;в rax <- [rbp-24]
	add	rdx, rax                    ;rdx увеличивают на rax
	movzx	eax, BYTE PTR [rbp-5]   ;в eax запихивают тот самый символ
	mov	BYTE PTR [rdx], al          ;и в rdx
.L2:
	call	getchar
	mov	BYTE PTR [rbp-5], al        ;считывание в c
	cmp	BYTE PTR [rbp-5], 10
	jne	.L3
	mov	eax, DWORD PTR [rbp-4]
	movsx	rdx, eax
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	read, .-read
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%s %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	lea	rax, [rbp-48]
	mov	rdi, rax
	call	read
	lea	rax, [rbp-48]
	add	rax, 20
	mov	rdi, rax
	call	read
	lea	rax, [rbp-48]
	add	rax, 36
	mov	rsi, rax
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	__isoc99_scanf
	lea	rax, [rbp-48]
	lea	rdx, [rax+20]
	lea	rax, [rbp-48]
	mov	rsi, rax
	mov	edi, OFFSET FLAT:.LC1
	mov	eax, 0
	call	printf
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
*/
