.text
.globl add
add:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp),%eax
	movl 12(%ebp),%edx
	addl %edx,%eax
	leave
	ret
