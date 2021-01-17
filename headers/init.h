
/* file used to set up variables */


#include "types.h"


#ifndef _MINIT_H_
#define _MINIT_H_


const uint8 sw = 80, sh = 25, sd = 2;
int cursorX = 0, cursorY = 0;

uint8 inportb (uint16 _port){

	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;

}


void outportb (uint16 _port, uint8 _data){

	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));




}

#endif // not minit_h




