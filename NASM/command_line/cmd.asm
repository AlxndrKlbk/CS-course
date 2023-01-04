global  _start

section .text
nlstr   db  10, 0

strlen:     ; arg1 == addres of the string
        push ebp
        mov ebp, esp
        xor eax, eax        ; eax == 0
        mov ecx, [ebp+8]    ; [arg1]

.lp:    cmp byte [ebp+ecx], 0
        jz  .quit
        inc eax
        jmp short .lp
.quit:  pop ebp
        ret

print_str:  ; arg1 == address of tge string
        push ebp
        mov ebp, esp
        push ebx
        mov ebx, [ebp+8]
        push ebx
        call strlen
        add esp, 4

%ifdef OS_FREEBSD
        push eax        ; length
        push ebx        ; arg1
        push dword 1    ; stdout
        mov eax, 4      ; write
        push eax     ; extra dword
        int 80h
        add esp, 16       
%elifdef OS_LINUX
        mov edx, eax        ; edx now contains the length
        mov ecx, ebx        ; arg1; was stored in ebx
        mov ebx, 1          ; stdout
        mov eax, 4          ; write
        int 80h
%else
%error please define either OS_FREEBSV OR OS_LINUX     
%endif
        pop ebx
        mov esp, ebp
        pop ebp
        ret

_start:
        mov ebx, [esp]
        mov esi, esp
        add esi, 4

again:  push dword [esi]
        call print_str
        add esp, 4
        push dword nlstr 
        call print_str
        add esp, 4
        add esi, 4
        dec ebx
        jnz again

%ifdef OS_FREEBSD
    push dwords 0
    mov eax, 1
    push eax
    int 80h
%else
    mov ebx, 0
    mov eax, 1
    int 80h
%endif

