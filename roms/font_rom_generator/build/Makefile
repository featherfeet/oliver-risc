font_rom_generator: ../src/font_rom_generator.c
	gcc -Wall -Wpedantic -o $@ ../src/font_rom_generator.c

debug: ../src/font_rom_generator.c
	gcc -g -Wall -Wpedantic -fsanitize=address -o font_rom_generator ../src/font_rom_generator.c

clean:
	rm -f font_rom_generator font_rom.v font_rom.mem

run: font_rom_generator unifont.hex
	./font_rom_generator unifont.hex font_rom.v font_rom.mem
