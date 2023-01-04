global _start
extern putstr
extern getstr
extern quit

section .data
nmq     db      "Hi, what is your name?", 10, 0
pmy     db      "Pleased to meet you, dear ", 10, 0
exc     db      "!", 10, 0

section .bss
buf     resb    512
buflen  equ     $-buf

section .text
_start: push dword nmq      ; prepare for nmq
        call putstr
        add esp, 4
        push dword buflen   ; put params
        push dword buf      ; for getstr 
        call getstr
        add esp, 8
        push dword pmy      ; put params for stack
        call putstr
        add esp, 4
        push dword buf
        call putstr
        add esp, 4
        push dword exc
        call putstr
        add esp, 4
        call quit

