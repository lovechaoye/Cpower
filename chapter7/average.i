# 1 "average.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "average.c"




# 1 "/usr/lib/gcc/i686-redhat-linux/4.8.5/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/i686-redhat-linux/4.8.5/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 98 "/usr/lib/gcc/i686-redhat-linux/4.8.5/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 6 "average.c" 2

float average(int n_values,...){
 va_list var_arg;
 int count;
 float sum = 0;




 __builtin_va_start(var_arg,n_values);





 for(count = 0;count < n_values;count++){
  sum += __builtin_va_arg(var_arg,int);
 }




 __builtin_va_end(var_arg);

 return sum / n_values;

}
