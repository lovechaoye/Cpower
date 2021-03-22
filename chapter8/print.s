# 打印文件
.section .data
EOF:
.int '\n'
.section .bss
buff:
	.int
.section .text
.globl _start
_start:
	call getchar
	cmpl %eax,EOF
	je end
	pushl %eax
	call putchar
	jmp _start
	end:
	pushl EOF
	call putchar
	call exit
	
	
