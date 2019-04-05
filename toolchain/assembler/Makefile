assembler: assembler.c stringproc.c
	gcc -std=c99 -g -o assembler assembler.c stringproc.c
run: assembler
	./assembler test.asm out.bin
clean:
	rm assembler
