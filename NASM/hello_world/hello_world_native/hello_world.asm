global _start

section .data
msg         db  "Hello world", 10
msg_len     equ $-msg
msg2        db  "2", 1
msg2_len    equ $-msg2

section .text
_start: mov     eax, 4          ; number 4 is write command
        mov     ebx, 1          ; number 1 is std output
        mov     ecx, msg
        mov     edx, msg_len
        int     80h             ; system interraption
        
        mov     eax, 4
        mov     ebx, 1 
        mov     ecx, msg2
        mov     edx, msg2_len
        int     80h        

        mov     eax, 1          ; call system _exit
        mov     ebx, 0          ; succes return code
        int     80h     


