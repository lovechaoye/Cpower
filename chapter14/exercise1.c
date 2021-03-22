void print_ledger(int num){
	#if defined(OPTION_LONG)
		print_ledger_long(num);
	#elif defined(OPTION_DETAILED)
		print_leger_detailed(num);
	#else
		print_leger_default(num);
	#endif
}

