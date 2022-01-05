/*
probably a better alternative to puts... most of you would prefer this over puts, i think...
contact me (david) if you think otherwise
*/
#include "myputs.h"
#include "mytypes.h"
#include "myinit.h"


#ifndef _MPRINTF_H_
#define _MPRINTF_H_




void printk(string ch){

        uint16 i = 0;
        uint8 length = strlength(ch)-1;              //Updated (Now we store string length on a variable to call the function only once)
        for(i;i<length;i++)
        {
                printch(ch[i]);
        }
       /* while((ch[i] != (char)0) && (i<=length))
                print(ch[i++]);*/


}




#endif //not _PRINTF_H_
