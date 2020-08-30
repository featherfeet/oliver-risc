emulator: emulator.c assembler.h ../processor.h
	gcc -g -std=c99 -I.. -o emulator emulator.c
run: emulator
	./emulator ../assembler/build/out.bin
