	.file	"argv.c"
	.section	.rodata
.LC0:
	.string	"count = %d,argc = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 28(%esp)
	jmp	.L2
.L3:
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	puts
.L2:
	movl	28(%esp), %eax
	leal	1(%eax), %edx
	movl	%edx, 28(%esp)
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 24(%esp)
	cmpl	$0, 24(%esp)
	jne	.L3
	movl	28(%esp), %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, (%esp)
	call	exit
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
