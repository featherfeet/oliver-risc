#include <stdio.h>
#include <glib.h>

FILE *input_file = NULL;
char *input_buffer = NULL;

void cleanup() {
    if (input_file) {
        fclose(input_file);
        input_file = NULL;
    }
    if (input_buffer) {
        g_free(input_buffer);
        input_buffer = NULL;
    }
}

long load_input_file(const char *input_filename) {
    input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Could not open input file `%s`.\n", input_filename);
        cleanup();
        return -1;
    }
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    if (input_file_size == -1) {
        fprintf(stderr, "ftell() on input_file failed.\n");
        cleanup();
        return -1;
    }
    fseek(input_file, 0, SEEK_SET);
    input_buffer = (char *) g_malloc(input_file_size + 1);
    if (!input_buffer) {
        fprintf(stderr, "Failed to allocate enough memory for input file.\n");
        cleanup();
        return -1;
    }
    size_t bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    if (bytes_read != input_file_size) {
        fprintf(stderr, "Failed to read entire input file.\n");
        cleanup();
        return -1;
    }
    input_buffer[bytes_read] = '\0';
    return input_file_size;
}

// Forward declarations of functions in lexer.l that allow Flex to parse an in-memory buffer instead of a file handle.
void flex_start_parsing_string(const char *);
void flex_finish_parsing_string(void);

// Forward declarations of symbols from c_compiler_parser.c (the parser generated by Bison).
extern int yydebug;
int yyparse(void);

int main(int argc, char *argv[]) {
    yydebug = 1;
    // Check arguments and show help.
    if (argc < 2) {
        printf("Usage: ./main program.pl0 [output.asm]\n");
        return 1;
    }

    // Get arguments.
    const char *input_filename = argv[1];
    const char *output_filename = "output.asm";
    if (argc == 3) {
        output_filename = argv[2];
    }

    // Load input file.
    long input_file_size = load_input_file(input_filename);
    if (input_file_size == -1) {
        return -1;
    }

    flex_start_parsing_string(input_buffer);
    yyparse();
    flex_finish_parsing_string();

    cleanup();
    return 0;
}