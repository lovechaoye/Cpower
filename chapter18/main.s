	.file	"main.c"
	.globl	static_num
	.data
	.align 4
	.type	static_num, @object
	.size	static_num, 4
static_num:
	.long	10
	.section	.rodata
.LC0:
	.string	"sum = %d\n"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.section	.rodata
.LC1:
	.string	"sub = %d\n"
	.text
	.globl	sub
	.type	sub, @function
sub:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	sub, .-sub
	.globl	operate
	.type	operate, @function
operate:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	16(%ebp), %eax
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	operate, .-operate
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$10, 28(%esp)
	movl	$8, 24(%esp)
	movl	$add, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	operate
	movl	$sub, 8(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	operate
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.data
	.align 4
	.type	inner_static.2168, @object
	.size	inner_static.2168, 4
inner_static.2168:
	.long	10
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
