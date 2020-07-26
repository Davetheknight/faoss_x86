[BITS 16]
[ORG 0x7C00]

MOV SI, BOOTLOADERSTR
CALL printstring
JMP $


PrintCharacter:
MOV AH, 0x0E
MOV BH, 0x00
MOV BL, 0x07
ENT 0x10
RET


printstring
next_character:
MOV AL, [SI]
INC SI
OR AL, AL
JZ exit_function
CALL PrintCharacter
exit_function
RET

;DATA
BOOTLOADERSTR db 'F.C.E. 365 Bootloader for faoss v0' , 0

TIMES 510 - ($ - $$)) db 0
DW 0xAA55




