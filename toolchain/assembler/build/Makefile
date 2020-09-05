main: lex.yy.c parser.tab.h parser.tab.c ../src/assembler.h ../../processor.h
	gcc -Wall -o $@ `pkg-config --cflags glib-2.0` -I../src -I../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`

parser.tab.h parser.tab.c: ../src/parser.y
	bison -d ../src/parser.y

lex.yy.c: ../src/lexer.l parser.tab.h parser.tab.c
	flex ../src/lexer.l

debug: lex.yy.c parser.tab.h parser.tab.c ../src/assembler.h ../../processor.h
	gcc -g -Wall -o main `pkg-config --cflags glib-2.0` -I../src -I../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`

clean:
	rm main lex.yy.c parser.tab.c parser.tab.h out.bin

run: main mult_div_test.asm
	./main mult_div_test.asm
