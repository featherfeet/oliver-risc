main: lex.yy.c parser.tab.h parser.tab.c
	gcc -Wall -o $@ `pkg-config --cflags glib-2.0` -I../src -I../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`

parser.tab.h parser.tab.c: ../src/parser.y
	bison -t -d ../src/parser.y

lex.yy.c: ../src/lexer.l parser.tab.h parser.tab.c
	flex ../src/lexer.l

debug: lex.yy.c parser.tab.h parser.tab.c
	#gcc -Wall -Wpedantic -fsanitize=address -g -o main `pkg-config --cflags glib-2.0` -I../src -I../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`
	gcc -Wall -Wpedantic -g -o main `pkg-config --cflags glib-2.0` -I../src -I../.. parser.tab.c lex.yy.c -lfl `pkg-config --libs glib-2.0`

clean:
	rm main lex.yy.c parser.tab.c parser.tab.h

run: main program.pl0
	./main program.pl0
