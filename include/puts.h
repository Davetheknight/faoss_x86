
/*
Welcome! This has been my first ever small custom header file for the project. Something tells
 me that I'll have to code lots more of this. Postscript: I'll definitely remember these times
 of operating systen engineering.

Signed: 15 year old David Mella, 1/9/21.

*/

#include "types.h"
#include "init.h"
#include "sfuncts.h"

#ifndef _MPUTS_H_
#define _MPUTS_H_

void printch(char c);
void newLineCheck();
void scrollUp(uint8 lineNumber);

void puts(string ch, int colour)
{
	uint16 i =0;
	for (i; i<strlength(ch);i++)
	{
		printch(ch[i]);
	}
}

void printch(char c)
{
    string vidmem = (string) 0xb8000;
    switch(c)
    {
        case (0x08):
                if(cursorX > 0)
                {
	                cursorX--;
                        vidmem[(cursorY * sw + cursorX)*sd]=0x00;
	        }
	        break;
        case (0x09):
                cursorX = (cursorX + 8) & ~(8 - 1);
                break;
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = 0x0F;
                cursorX++;
                break;
    }
    if(cursorX >= sw)
    {
        cursorX = 0;
        cursorY++;
    }
    newLineCheck();
    updateCursor();
}






void newLineCheck()
{
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}



void scrollUp(uint8 lineNumber)
{
        string vidmem = (string)0xb8000;
        uint16 i = 0;
        for (i;i<sw*(sh-1)*sd;i++)
        {
                vidmem[i] = vidmem[i+sw*sd*lineNumber];
        }
        clearLine(sh-1-lineNumber,sh-1);
        if((cursorY - lineNumber) < 0 ) 
        {
                cursorY = 0;
                cursorX = 0;
        } 
        else 
        {
                cursorY -= lineNumber;
        }
        updateCursor();
}


#endif // not _PUTS_H_
