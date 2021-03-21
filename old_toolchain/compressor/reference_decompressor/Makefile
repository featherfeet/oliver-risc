reference_decompressor: reference_decompressor.c
	gcc -Wall -Wpedantic -o $@ reference_decompressor.c

debug: reference_decompressor.c
	gcc -g -Wall -Wpedantic -o reference_decompressor reference_decompressor.c

sanitized: reference_decompressor.c
	gcc -g -Wall -Wpedantic -fsanitize=address -o reference_decompressor reference_decompressor.c

clean:
	rm -f reference_decompressor

run: reference_decompressor
	./reference_decompressor ../out.bin.lzw out.bin
	diff out.bin ../../out.bin
