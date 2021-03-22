	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"a.h"
	.text
	.globl	Say
	.type	Say, @function
Say:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, (%esp)
	call	puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	Say, .-Say
	.section	.rodata
.LC1:
	.string	"hello,world"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	$1684501357, 23(%esp)
	movl	$1684300900, 27(%esp)
	movl	$1684300900, 31(%esp)
	movl	$1684300900, 35(%esp)
	movl	$1684300900, 39(%esp)
	movl	$1684300900, 43(%esp)
	movb	$0, 47(%esp)
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	puts
	movl	$.LC1, (%esp)
	call	puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
