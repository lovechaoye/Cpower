# 目的：此程序打印消息"hello world"并退出
#

.section .data

helloworld:
	.ascii "hello world\n\0"

.section .text
.globl _start
_start:
	pushl $helloworld
	call printf

	pushl $0
	call exit

# as helloworld-lib.s -o helloworld-lib.o , ld -dynamic-linker /lib/ld-linux.so.2 -o helloworld-lib helloworld-lib.o -lc

