/*
The first step in creating printf and gets, etc. Good job, team.
-David


*/
#include "puts.h"

#ifndef _STDARG_H_
#define _STDARG_H_

typedef struct {
	unsigned int gp_offset;
	unsigned int fp_offset;
	void *overflow_arg_area;
	void *reg_save_area;
} va_list[1];

void test(void){
	puts("hello", 0x02);



}




#endif //not  _STDARG_H_


