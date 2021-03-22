#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i = 0;
	__asm__ __volatile__
	(
		"movl 12(%%ebp),%%esi\n\t"	
		"1:movl %1,%%ecx\n\t"
		"movl (%%esi,%%ecx,4),%%edi\n\t"
		"cmpl $0,%%edi\n\t"
		"je 2f\n\t"
		"pushl %%ecx\n\t"
		"pushl %%edi\n\t"
		"call puts\n\t"
		"addl $4,%%esp\n\t"
		"popl %%ecx\n\t"
		"incl %1\n\t"
		"jmp 1b\n\t"
		"2:"
		:"=c"(i):"m"(i):"esi","edi"
	);
	printf("argc = %d\n",i);
	exit(EXIT_SUCCESS);
}
