
/*
Welcome! This has been my first ever small custom header file for the project. Something tells
 me that I'll have to code lots more of this. Postscript: I'll definitely remember these times
 of operating systen engineering.

Signed: 15 year old David Mella, 1/9/21.

*/

#ifndef _PUTS_H_
#define _PUTS_H_

void puts(const char *string, int colour)
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}








#endif // not _PUTS_H_
