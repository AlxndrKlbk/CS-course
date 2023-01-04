%include "stud_io.inc"
global _start

section .text
_start: mov     eax, 0
again:  PRINT "Hello World"
        PUTCHAR 10
        inc     eax
        cmp     eax, 5
        jl      again
        FINISH

