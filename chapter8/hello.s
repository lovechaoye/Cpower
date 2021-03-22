	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"hello,world"
.LC1:
	.string	"msg"
.LC2:
	.string	"%s:%d ,%s : line : %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	$10, 40(%esp)
	movl	40(%esp), %eax
	addl	$10, %eax
	movl	%eax, 36(%esp)
	movl	$.LC0, (%esp)
	call	puts
	movl	$0, 44(%esp)
	movl	$0, 44(%esp)
	jmp	.L2
.L3:
	movl	$8, 16(%esp)
	movl	$__FUNCTION__.2152, 12(%esp)
	movl	44(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC1, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	addl	$1, 44(%esp)
.L2:
	cmpl	$9, 44(%esp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	__FUNCTION__.2152, @object
	.size	__FUNCTION__.2152, 5
__FUNCTION__.2152:
	.string	"main"
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
