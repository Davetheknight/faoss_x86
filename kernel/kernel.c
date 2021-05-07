
#include "stdio.h"
#include "shell.h"


int kmain()
{
	clearScreen();
	printk("Welcome to the kernelspace.");
	while (1){

		printk("\nFAOSS> ");
		string ch = readStr();
		if (strEql(ch, "help")){
			kputs("\nThis is the very first version with a shell that can recieve user input. \"help\" is actually the only command that exists right now.", 0x02);
		}
		else if(strEql(ch, "clear"))
		{
			clearScreen();

		}

	}
	return 0;
}



