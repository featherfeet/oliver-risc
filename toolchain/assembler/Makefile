assembler: assembler.c stringproc.c
	gcc -g -o assembler assembler.c stringproc.c
run: assembler
	./assembler test.asm out.bin
clean:
	rm assembler
