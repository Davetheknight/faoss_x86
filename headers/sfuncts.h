/* Screen functions- clear screen functions, etc.
essential
*/



void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        string vidmem=(string)0xb8000;
        for(i;i<(sw*(to+1)*sd);i++)
        {
                vidmem[i] = 0x0;
        }
}


