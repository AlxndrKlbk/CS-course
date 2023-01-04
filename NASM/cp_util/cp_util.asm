%include "kernel.inc"

global _start

%ifdef OS_FREEBSD
openwr_flag equ 601h
%else
openwr_flag equ 241h
%endif

section .bss
buffer  resb    4096
bufsize equ     $-buffer
fdsrc   resd    1
fddest  resd    1
argc    resd    1
argvp   resd    1

section .data
helpmsg db  "Usage: copy <src> <dest>", 10
helplen equ $-helpmsg
err1msg db  "Couldn't open source file for reading", 10
err1len equ $-err1msg
err2msg db  "Couldn't open destination file for writing", 10
err2len equ $-err2msg

section .text
_start:
        pop dword [argc]
        mov [argvp], esp
        cmp dword [argc], 3
        je  .args_count_ok
        kernel 4, 2, helpmsg, helplen
        kernel 1, 1

.args_count_ok:
        mov esi, [argvp]
        mov edi, [esi+4]
        kernel 5, edi, 0        ;O_RDONLY
        cmp eax, -1
        jne .source_open_ok
        kernel 4, 2, err1msg, err1len
        kernel 1, 2

.source_open_ok:
        mov [fdsrc], eax
        mov esi, [argvp]
        mov edi, [esi+8]
        kernel 5, edi, openwr_flag, 0666q
        cmp eax, -1
        jne .dest_open_ok
        kernel 4, 2, err2msg, err2len
        kernel 1, 3

.dest_open_ok:
        mov [fddest], eax

.again: kernel 3, [fdsrc], buffer, bufsize
        cmp eax, 0
        jle .end_of_file
        kernel 4, [fddest], buffer, eax
        jmp .again

.end_of_file:
        kernel 6, [fdsrc]
        kernel 6, [fddest]
        kernel 1, 0
