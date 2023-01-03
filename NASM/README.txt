Some usefull references and descriptions for NASM learning. 

---------
---FAQ---
---------

- ld - GNU linker for building executable files

ld -m elf_i386 file.o -o file

usefull keys: 
-m  - emulation
-o  - name executable file
-V  list of available emulations  

----------
---NASM---
----------
nasm -f elf file.asm

----------------
---ASM sintax---
----------------

name: command - name is a marker to memory cell with command


------------------
---CP registers (i386)---
------------------
EAX     - Extended Accumulator (possible EAH, EAL) 
EBX     - Extended Base
ECX     - Extended Counter
EDX     - Extended Data
SI, DI  - Source index & Destination Index (ESI, EDI used with arrays)
BP      - Base Pointer
SP      - Stack Pointer
EIP     - Current Instruction Pointer
FLAGS   - Boolean Flags
ZF      - Zero Flag
CF      - Carry Flag (value movement to unexist rank)
SF      - Sign Flag
OF      - Overflow Flag
DF      - Direction Flag (std to turn on, cld to turn off)
AF, PF  - Auxiliary carry flag & Parity Flag
IF, TF  - Interrupt Flag & Trap Flag 

-----------------
---CP commands---
-----------------

inc                 - increment value in registry
cmp                 - to compare (results of compare writen to flags registry)
jl                  - jump if less
jnz                 - jump if not zero
resb, resw, resd    - reserve one bite, two bite, double two bite cells (memory usage)
db, dw, dd          - writing initial data (db - one bite, dw - wtire machine word, dd - write double machine word) 
mov                 - to move (mov to from)
lea                 - load effective addres
add, sub            - addition and subtraction
mul, imul           - multiplication
div, idiv           - division
cwb                 - convert word to doubleword
cbw                 - convert byte to word
