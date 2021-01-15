



all:
	./scripts/check.sh



	nasm -f elf32 kernel/kernel.asm
	mv kernel/kernel.o intermediates/kasm.o
	gcc -m32 -c -fno-builtin kernel/kernel.c -o intermediates/kc.o
	ld -m elf_i386 -T kernel/link.ld -o kernel.bin intermediates/kasm.o intermediates/kc.o
	mv kernel.bin faoss/boot
	./scripts/rtrash.sh

	grub2-mkrescue -o faoss.iso faoss/



runqemu:

	./scripts/check.sh


	nasm -f elf32 kernel/kernel.asm
	mv kernel/kernel.o intermediates/kasm.o
	gcc -m32 -c -fno-builtin kernel/kernel.c -o intermediates/kc.o
	ld -m elf_i386 -T kernel/link.ld -o kernel.bin intermediates/kasm.o intermediates/kc.o
	mv kernel.bin faoss/boot
	./scripts/rtrash.sh





	qemu-system-x86_64 -kernel faoss/boot/kernel.bin



