	.file	"pthread_join.c"
	.globl	ret
	.data
	.align 4
	.type	ret, @object
	.size	ret, 4
ret:
	.long	10
	.section	.rodata
	.align 8
.LC0:
	.string	"my pid = %ld ,tid = %lx,msg = %s\n"
	.text
	.globl	dosth
	.type	dosth, @function
dosth:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	call	pthread_self
	movq	%rax, %rbx
	call	getpid
	cltq
	movq	-24(%rbp), %rdx
	movq	%rdx, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$10, %edi
	call	sleep
	movl	$ret, %edi
	call	pthread_exit
	.cfi_endproc
.LFE2:
	.size	dosth, .-dosth
	.section	.rodata
.LC1:
	.string	"hello,myson"
.LC2:
	.string	"pthread_create failed : %s\n"
	.align 8
.LC3:
	.string	"my pid = %ld,tid = %lx,ret = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	leaq	-32(%rbp), %rax
	movl	$.LC1, %ecx
	movl	$dosth, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	je	.L3
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	strerror
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %edi
	call	exit
.L3:
	movq	-32(%rbp), %rax
	leaq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pthread_join
	movq	-40(%rbp), %rax
	movl	(%rax), %r12d
	call	pthread_self
	movq	%rax, %rbx
	call	getpid
	cltq
	movl	%r12d, %ecx
	movq	%rbx, %rdx
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
