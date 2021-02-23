



#checks for the compiling user's project directory location
PROJECT_ROOT := $(shell pwd)


fedoraiso:
#check for missing folders
	./scripts/check.sh



#common section
	nasm -f elf32 kernel/kernel.asm
	mv kernel/kernel.o intermediates/kasm.o
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/headers kernel/kernel.c -o intermediates/kc.o
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/headers -E kernel/kernel.c > intermediates/long.c
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/kernel/shell kernel/shell -o intermediates/shell.o
	ld -m elf_i386 -T kernel/link.ld -o kernel.bin intermediates/kasm.o intermediates/kc.o
	mv kernel.bin faoss/boot



#section unique to "fedoraiso"
	grub2-mkrescue -o faoss.iso faoss/
	@echo HEADER ROOT IS $(PROJECT_ROOT)/headers



ubuntuiso:
#check for missing folders
	./scripts/check.sh



#common section
	nasm -f elf32 kernel/kernel.asm
	mv kernel/kernel.o intermediates/kasm.o
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/headers kernel/kernel.c -o intermediates/kc.o
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/headers -E kernel/kernel.c > intermediates/long.c
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/kernel/shell kernel/shell -o intermediates/shell.o
	ld -m elf_i386 -T kernel/link.ld -o kernel.bin intermediates/kasm.o intermediates/kc.o
	mv kernel.bin faoss/boot


#section unique to "ubuntuiso"
	grub-mkrescue -o faoss.iso faoss/
	@echo HEADER ROOT IS $(PROJECT_ROOT)/headers


runqemu:
#check for missing folders
	./scripts/check.sh



#common secton
	nasm -f elf32 kernel/kernel.asm
	mv kernel/kernel.o intermediates/kasm.o
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/headers kernel/kernel.c -o intermediates/kc.o
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/headers -E kernel/kernel.c > intermediates/long.c
	gcc -m32 -c -fno-builtin -I$(PROJECT_ROOT)/kernel/shell kernel/shell -o intermediates/shell.o
	ld -m elf_i386 -T kernel/link.ld -o kernel.bin intermediates/kasm.o intermediates/kc.o
	mv kernel.bin faoss/boot


#section unique to runqemu
	qemu-system-x86_64 -kernel faoss/boot/kernel.bin
	@echo HEADER ROOT IS $(PROJECT_ROOT)/headers


