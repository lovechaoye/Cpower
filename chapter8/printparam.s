.section .data
.equ param1,4
.equ param2,8
format:
 .ascii "%s\n"
 .lcomm num ,4
.section .text
.globl _start
_start:
	movl param1(%ebp),%eax
	movl param2(%ebp),%ecx
	#movl %ecx,num
	#xorl %ecx,%ecx
	#L1:cmpl %ecx,num
	#jge end
	#pushl (%eax,%ecx,4)
	#pushl $format
	#call printf
	#incl %ecx
	#jmp L1
	end:
		call exit
