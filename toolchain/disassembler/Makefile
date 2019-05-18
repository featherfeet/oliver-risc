disassembler: disassembler.c assembler.h ../processor.h
	gcc -g -std=c99 -o disassembler disassembler.c
run: disassembler
	./disassembler ../assembler/out.bin
