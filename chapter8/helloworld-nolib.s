# 目的：此程序打印消息“hello world”并退出
#

.include "linux.s"
.section .data

helloworld:
	.ascii "hello,world\n"
helloworld_end:
	
	.equ helloworld_len,helloworld_end-helloworld

	.section .text
	.globl _start
	_start:
		movl $STDOUT,%ebx
		movl $helloworld,%ecx
		movl $helloworld_len,%edx
		movl $SYS_WRITE,%eax
		int $LINUX_SYSCALL

		movl $0,%ebx
		movl $SYS_EXIT,%eax
		int $LINUX_SYSCALL
	
# 编译链接指令 : as helloworld-nolib.s -o helloworld-nolib.o ,ld helloworld-nolib.o -o helloworld
