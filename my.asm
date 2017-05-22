; Assemble:     nasm -f elf demo8.asm 
; Link:         gcc -o demo demo8.o 
; Run:          ./demo8 123 456 asd

extern	gets
extern	puts
	
	section		.data
letters:                            ;if small -= 1; if big += 1
    db 0
len:								;Length of string
	dd 0
len2:								;Length of string/2
	dd 0
	
	section		.bss	
msg1:
	resb 101

	section		.text
		
	global main
main:
	push	msg1
	call	gets
	add		esp, 4
	push	msg1
	call	puts
	add		esp, 4	
	jmp		conditions
	ret

conditions:
	xor		ebx, ebx
	xor		eax, eax
	mov		al, BYTE [msg1+ebx]			;Current symbol
	
repeat:
	cmp		al, 0					;Нулевой символ -- конец строки
	je		check
	inc		DWORD [len]                      
							
	cmp		al, 'Z'
	jbe		check_big_letter

    cmp     al, 'z'
    jbe     check_small_letter
	
	inc		ebx
	mov		al, BYTE [msg1+ebx]
	jmp		repeat
	
inc_big_letters_counter:
	inc		BYTE [letters]
	inc		ebx
	mov		al, BYTE [msg1+ebx]
	jmp		repeat

dec_small_letters_counter:
    dec     BYTE [letters]
    inc     ebx
    mov     al, BYTE [msg1+ebx]
    jmp     repeat

check_big_letter:
	cmp		al, 'A'
	jge		inc_big_letters_counter
	inc		ebx
	mov		al, BYTE [msg1+ebx]
	jmp		repeat

check_small_letter:
    cmp     al, 'a'
    jge     dec_small_letters_counter
    inc     ebx
    mov     al, BYTE [msg1+ebx]
    jmp     repeat

rule1:
	xor		ebx, ebx
	xor		eax, eax
	mov		al, BYTE [msg1+ebx]
	
rule11:
	cmp		al, 0
	je		end1
	
	cmp		al, '9'
	jbe		check_number
	
rule1_if_not_a_number:    
	inc		ebx
    mov		al, BYTE [msg1+ebx]
	jmp		rule11

check_number:
    cmp     al, '0'
    jbe     rule1_if_not_a_number
    xor     ah, ah
    add     ah, al
	add		BYTE [msg1+ebx], 'a' - '1'
    xor     ah, ah
	inc		ebx
	mov		al, BYTE [msg1+ebx]
	jmp		rule11

check:
	xor		edx, edx
	xor		eax, eax
	mov		dh, BYTE [letters]
	cmp		dh, 0
	je		rule1

rule2:
	xor		ebx, ebx
	xor		eax, eax

	mov		edx, DWORD [len]
	shr		edx, 1                      ;сдвиг ->
	mov		DWORD [len2], edx

rule22:
	cmp		ebx, DWORD [len2]
	je		end1

	mov		al, BYTE [msg1+ebx]
	mov		edx, DWORD [len]
	dec		edx
	sub		edx, ebx

	mov		ah, BYTE [msg1+edx]
	mov		BYTE [msg1+ebx], ah
	mov		BYTE [msg1+edx], al
	inc		ebx
	jmp		rule22

end1:
	push	msg1
	call	puts
	add     esp, 4
	ret
