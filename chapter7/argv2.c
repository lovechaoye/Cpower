#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	register int i = 0;
	__asm__ __volatile__
	(
		"movl 12(%%ebp),%%edx\n\t"	
		"1:movl (%%edx,%%eax,4),%%esi\n\t"
		"cmpl $0,%%esi\n\t"
		"je 2f\n\t"
		"pushl %%esi\n\t"
		"call puts\n\t"
		"addl $4,%%esp\n\t"
		"incl %%eax\n\t"
		"jmp 1b\n\t"
		"2:"
		:"=a"(i):"a"(i):"edi"
	);
	printf("argc = %d\n",i);
	exit(EXIT_SUCCESS);
}
