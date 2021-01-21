#include "puts.h"
#include "stdarg.h"
#include "types.h"
#include "sfuncts.h"
#include "printf.h"
#include "gets.h"



int kmain()
{
	clearScreen();
	puts("Welcome to the shell. Type \"help\" to see command options.", 0x02);
	while (1){

		puts("\nFAOSS> ", 0x02);
		string ch = readStr();
		if (strEql(ch, "help")){
			puts("\nThis is the very first version with a shell that can recieve user input. \"help\" is actually the only command that exists right now.", 0x02);

		}

	}
	return 0;
}



