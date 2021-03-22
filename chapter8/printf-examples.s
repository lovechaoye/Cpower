# 目的：这个程序用于说明如何调用printf
#


 .section .data


# 这个字符串被称为格式化字符串，是第一个参数
# printf用这个参数来确定给定了多少个参数
# 以及他们分别是什么类型

firststring:
	.ascii "Hello! %s is a %s who loves the number %d\n\0"
name:
	.ascii "Jonathan\0"
personstring:
	.ascii "Person\0"

	#这也可以用.equ,但为了有趣，我们决定给其一个实际内存地址
numberloved:
	.long 3

 .section .text
 .globl _start

 _start:
 	# 注意：参数传递顺序与函数原型中列出的顺序相反

	pushl $numberloved   # 这是%d
	pushl $personstring # 这是第二个%s
	pushl $name # 这是第一个%s
	pushl $firststring # 这是原型中的格式化字符串
	call printf
	pushl $0
	call exit

