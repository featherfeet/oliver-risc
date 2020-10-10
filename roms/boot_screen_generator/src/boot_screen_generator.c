#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./boot_screen_generator Boot\\ Screen.txt Boot\\ Screen.mem\n");
        return 1;
    }
    
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, input_file)) != -1) {
        // Loop over characters in the line, writing out their hex equivalents. Loop uses (read - 1) because we have to skip the final \n character.
        for (int i = 0; i < read - 1; i++) {
            fprintf(output_file, "%X\n", line[i]);
        }
    }

    free(line);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
