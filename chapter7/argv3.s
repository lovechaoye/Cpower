	.file	"argv3.c"
	.section	.rodata
.LC0:
	.string	"argc = %d\n"
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
	pushl	%edi
	pushl	%esi
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	movl	$0, 28(%esp)
#APP
# 7 "argv3.c" 1
	movl 12(%ebp),%esi
	1:movl 28(%esp),%ecx
	movl (%esi,%ecx,4),%edi
	cmpl $0,%edi
	je 2f
	pushl %ecx
	pushl %edi
	call puts
	addl $4,%esp
	popl %ecx
	incl 28(%esp)
	jmp 1b
	2:
# 0 "" 2
#NO_APP
	movl	%ecx, %eax
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, (%esp)
	call	exit
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
