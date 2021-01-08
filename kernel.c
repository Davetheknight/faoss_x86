#include "headers/puts.h"
int kmain()
{
	char* vidmem = (char*)0xb8000;
	vidmem[0] = 'A';
	vidmem[1] = 0x02;
	puts("yes", 0x02);

	return 0;
}
