.section .data
format:
	.string "%d\n"

.section .text

.globl say
.type say,@function
	say:
	.equ param1,8
	.equ param2,12
	.equ param3,16
	pushl %ebp
	movl %esp,%ebp
	subl $16,%esp
	movl param1(%ebp),%eax
	addl param2(%ebp),%eax
	addl param3(%ebp),%eax
	movl %ebp,%esp
	popl %ebp
	ret
