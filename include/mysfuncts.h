/* Screen functions- clear screen functions, etc.
essential
*/

#include "mytypes.h"
#include "myinit.h"

#ifndef _MSFUNCTS_H_
#define _MSFUNCTS_H_




void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        string vidmem=(string)0xb8000;
        for(i;i<(sw*(to+1)*sd);i++)
        {
                vidmem[i] = 0x0;
        }
}
void updateCursor();
void clearScreen(){

	clearLine(0,sh-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}

void updateCursor(){

	unsigned temp;
	temp = cursorY * sw + cursorX;
	outportb(0x3D4,14);
        outportb(0x3D5, temp >> 8);
        outportb(0x3D4, 15);
        outportb(0x3D5, temp);
}



#endif //not msfuncts_h
