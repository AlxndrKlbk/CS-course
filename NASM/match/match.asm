global _start

section .text

;
;  [ebp+8] is pointer to string
;  [ebp+12] is pointer to pattern
;  returns eax==0 for false, eax==1 for true
;
match:
		push ebp
		mov ebp, esp
		sub esp, 4		; local I (index) is [ebp-4]
		push esi		; we use esi, edi  and eax,
		push edi		; but eax is changed anyway
		mov esi, [ebp+8]	; esi always points to the string
		mov edi, [ebp+12]	; edi -------------------- pattern
.again:
		cmp byte [edi], 0	; pattern end?
		jne .not_end
		cmp byte [esi], 0	; string end?
		jne near .false		; out of range
		jmp .true
.not_end:
		cmp byte [edi], '*'
		jne .not_star
					; now the "star cycle" begins
		mov dword [ebp-4], 0	; I := 0
.star_loop:
					; prepare the recursive call
		mov eax, edi		; second arg of match is pattern+1
		inc eax
		push eax
		mov eax, esi		; first arg of match is string+I
		add eax, [ebp-4]	; prepare the recursive call
		push eax
		call match
		add esp, 8		; remove params from stack
		test eax, eax		; what is returned, true or false?
		jnz .true		; if 1, then match is found, return 1
		add eax, [ebp-4]
		cmp byte [esi+eax], 0	; may be string ended?
		je .false		; if so, no more possibilities to try
		inc dword [ebp-4]	; I := I + 1
		jmp .star_loop		; try the next possibility
.not_star:
		mov al, [edi]		; we already know pattern isn't ended
		cmp al, '?'
		je .quest
		cmp al, [esi]		; if the string's over, this cmp fails
		jne .false		; as well as if the chars differ
		jmp .goon
.quest:
		cmp byte [esi], 0	; we only need to check for string end
		jz .false
.goon:
		inc esi
		inc edi
		jmp .again
.true:
		mov eax, 1
		jmp .quit
.false:
		xor eax, eax
.quit:
		pop edi
		pop esi
		mov esp, ebp
		pop ebp
		ret



;
;  MAIN PROGRAM
;
_start:
		pop eax
		cmp eax, 3
		jne wrong_args
		pop esi  ; ignore argv[0]
		pop esi  ; get argv[1]
		pop edi  ; get argv[2]
		mov [string], esi
		mov [pattern], edi

		push edi
		push esi
		call match
		add esp, 8
		test eax, eax
		jz print_no

		mov edx, 4		; print yes
		mov ecx, m_yes
		mov ebx, 1
		mov eax, 4
		int 80h
		jmp quit
print_no:			; print no
		mov edx, 4
		mov ecx, m_no
		mov ebx, 1
		mov eax, 4
		int 80h
		jmp quit

wrong_args:			; say wrong args
		mov edx, m_wrong_len
		mov ecx, m_wrong
		mov ebx, 1
		mov eax, 4
		int 80h
		jmp quit


quit:
		mov ebx, 0
		mov eax, 1
		int 80h	

section .bss

string		resd	1
pattern		resd	1

section .data

m_yes		db	"YES", 10
m_no		db	"NO ", 10
m_wrong		db	"wrong arguments count, must be 2", 10
m_wrong_len	equ	$-m_wrong
