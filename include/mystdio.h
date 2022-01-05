#ifndef _STDIO_H_
#define _STDIO_H_


#include "myputs.h"
#include "mystdarg.h"
#include "mytypes.h"
#include "mysfuncts.h"
#include "myprintk.h"
#include "mygets.h"
#include "mystring.h"
#include "mystdbool.h"
#include "myprintk.h"
#define sizeof(object) (char *)(&object+1) - (char *)(&object)


/* There is a terrible error here and it is  unfortunate. Just uncomment this and compile and you'll find it.
int reverse(char s[1000], int i){

	char r[1000];
	int begin,end;
	end = i-1;

	while (s[i] != '\0'){
		i++;
	}



	for (begin = 0; begin < i; begin++) {
		r[begin] = s[end];
		end--;
	}

	r[begin] = '\0';





	return 0;
}





// Implementation of itoa() 
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    // Handle 0 explicitely, otherwise empty string is printed for 0
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}
*/
















#endif //not stdio
