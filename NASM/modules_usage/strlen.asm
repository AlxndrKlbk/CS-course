global strlen

section .text
; procedure strlen
; [ebp+8] == address pf the string

strlen: push ebp
        mov ebp, esp
        xor eax, eax
        mov ecx, [ebp+8]

.lp:    cmp byte [eax+ecx], 0
        jz .quit
        inc eax
        jmp short .lp

.quit:  pop ebp
        ret

