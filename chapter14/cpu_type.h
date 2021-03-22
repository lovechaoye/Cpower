#ifndef __CPU_TYPE__
#define __CPU_TYPE__

#define STRING(a) #a
#define COMBINE(a) CPU_##a
char* cpu_type(void){
	#ifdef VAX
		return STRING(COMBINE(VAX)); 
	#elif defined(M68000)
		return STRING(CPU_68; 
	#elif defined(M68020)
		return STRING(CPU_VAX); 
	#elif defined(I80386)
		return STRING(CPU_VAX); 
	#elif defined(X6809)
		return STRING(CPU_VAX); 
	#elif defined(X6502)
		return STRING(CPU_VAX); 
}


#endif

