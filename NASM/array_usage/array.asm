section .bss
array   resb 256

section .text

        mov ecx, 256
        mov edi, array
        mov al, '@'

again:  mov [edi], al
        inc edi
        dec ecx
        jnz again

