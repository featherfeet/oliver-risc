disassembler: disassembler.c assembler.h ../processor.h
	gcc -g -std=c99 -I.. -o disassembler disassembler.c
run: disassembler
	./disassembler ../assembler/build/out.bin
