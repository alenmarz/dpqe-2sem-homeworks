	extern	printf

	section .data
fmt:	db	'Stage = %d', 10, 0
resfmt:	db	'Res = %d', 10, 0

	section .text

	global main

main:
	push	4
	call	factorial
	add	esp, 4

	push	dword eax
	push	resfmt
	call	printf
	add	esp, 8

	mov	eax,0
	ret

factorial:
        mov     eax, [esp+4]
	push	eax
	push	dword eax
	push	fmt
	call	printf
	add	esp, 8
	pop	eax
        cmp	eax, 1
        jnle	L1
        mov	eax, 1
        jmp	L2
L1:
	dec	eax
	push	eax
	call	factorial
	add	esp, 4
	imul	eax, [esp+4]
L2:
	ret
