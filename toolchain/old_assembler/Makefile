assembler: assembler.c stringproc.c ../processor.h assembler.h
	gcc -std=gnu99 -g -o assembler assembler.c stringproc.c
run: assembler
	./assembler test.asm out.bin
clean:
	rm assembler
