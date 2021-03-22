	.file	"bit_field.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"ch = %#x\t,font = %#x\t,size = %#x\n"
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
	subl	$32, %esp
	movzbl	28(%esp), %eax
	andl	$-128, %eax
	orl	$10, %eax
	movb	%al, 28(%esp)
	movzwl	28(%esp), %eax
	andw	$-8065, %ax
	orb	$10, %ah
	movw	%ax, 28(%esp)
	movl	28(%esp), %eax
	andl	$8191, %eax
	orl	$8192000, %eax
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	shrl	$13, %eax
	movl	%eax, %ecx
	movzwl	28(%esp), %eax
	shrw	$7, %ax
	andl	$63, %eax
	movzbl	%al, %edx
	movzbl	28(%esp), %eax
	andl	$127, %eax
	movzbl	%al, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
