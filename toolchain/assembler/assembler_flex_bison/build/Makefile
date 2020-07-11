main: lexer ../src/assembler.h
	gcc -o main `pkg-config --cflags glib-2.0` -I../src -I../../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`

parser: ../src/parser.y
	bison -d ../src/parser.y

lexer: ../src/lexer.l parser
	flex ../src/lexer.l

debug: lexer ../src/assembler.h
	gcc -g -o main `pkg-config --cflags glib-2.0` -I../src -I../../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`

clean:
	rm main lex.yy.c parser.tab.c parser.tab.h

run: main
	./main ../../assembler_c/fibonacci_slow.asm
