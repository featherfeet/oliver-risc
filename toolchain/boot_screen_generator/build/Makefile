boot_screen_generator: ../src/boot_screen_generator.c
	gcc -o $@ ../src/boot_screen_generator.c

debug: ../src/boot_screen_generator.c
	gcc -g -Wall -Wpedantic -fsanitize=address -o boot_screen_generator ../src/boot_screen_generator.c

clean:
	rm -f boot_screen_generator boot_screen.mem

run: boot_screen_generator boot_screen.txt
	./boot_screen_generator boot_screen.txt boot_screen.mem
