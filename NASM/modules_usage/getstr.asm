%include "kernel.inc"

global getstr

section .text

getstr:     ; arg1 - buffers addres, arg2 - length
        push ebp
        mov ebp, esp
        xor ecx, ecx
        mov edx, [ebp+8]

.again: inc ecx
        cmp ecx, [ebp+12]
        jae .quit
        push ecx
        push edx
        kernel 3, 0, edx, 1
        pop edx
        pop ecx
        cmp eax, 1
        jne .quit
        mov al, [edx]
        cmp al, 10
        je .quit
        inc edx
        jmp .again

.quit:  mov [edx], byte 0
        mov esp, ebp
        pop ebp
        ret

