emul_name='elf'
os_name='OS_LINUX'
macro='../macroses'

nasm -f $emul_name -d $os_name -i $macro strlen.asm 
nasm -f $emul_name -d $os_name -i $macro putstr.asm 
nasm -f $emul_name -d $os_name -i $macro getstr.asm 
nasm -f $emul_name -d $os_name -i $macro quit.asm 
nasm -f $emul_name -d $os_name -i $macro greet.asm 
