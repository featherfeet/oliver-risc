emulator: emulator.c ../assembler/src/assembler.h
	gcc -std=c99 -g -I../assembler/src -I.. -o emulator emulator.c
run: emulator
	./emulator ../assembler/build/out.bin
