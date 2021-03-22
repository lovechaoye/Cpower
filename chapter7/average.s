	.file	"average.c"
	.text
	.globl	average
	.type	average, @function
average:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	.LC0, %eax
	movl	%eax, -8(%ebp)
	leal	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -4(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	fildl	-20(%ebp)
	flds	-8(%ebp)
	faddp	%st, %st(1)
	fstps	-8(%ebp)
	addl	$1, -4(%ebp)
.L2:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L3
	fildl	8(%ebp)
	flds	-8(%ebp)
	fdivp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	average, .-average
	.section	.rodata
	.align 4
.LC0:
	.long	0
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
