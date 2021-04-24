disassembler: main.c disassembler.c disassembler.h
	gcc -Wall -Wpedantic -o disassembler main.c disassembler.c
debug: main.c disassembler.c disassembler.h
	gcc -g -Wall -Wpedantic -o disassembler main.c disassembler.c
asan: main.c disassembler.c disassembler.h
	gcc -fsanitize=address -g -Wall -Wpedantic -o disassembler main.c disassembler.c
fuzz: disassembler.c fuzzer_target.c
	clang -o fuzzer -g -O1 -fsanitize=fuzzer,address,undefined disassembler.c fuzzer_target.c
run: disassembler
	./disassembler ../rust_assembler/out.bin
