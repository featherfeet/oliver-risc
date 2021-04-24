#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "disassembler.h"

extern int errno;

FILE *file = NULL;
uint8_t *raw_binary = NULL;

void cleanup() {
    if (file) {
        fclose(file);
    }
    if (raw_binary) {
        free(raw_binary);
    }
}

long load_binary(char *argv[]) {
	// Read in binary file.
	file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s: %s\n", argv[1], strerror(errno));
        return -1;
    }
	if (fseek(file, 0L, SEEK_END) < 0) {
        fprintf(stderr, "Failed to seek to end of binary file: %s\n", strerror(errno));
        return -1;
    }
	long raw_binary_length = ftell(file);
    if (raw_binary_length < 0) {
        fprintf(stderr, "Failed to call ftell() on file: %s\n", strerror(errno));
        return -1;
    }
	raw_binary = malloc(raw_binary_length);
    if (!raw_binary) {
        fprintf(stderr, "Failed to allocate %ld bytes of memory to hold binary file.\n", raw_binary_length);
        return -1;
    }
	rewind(file);
	size_t bytes_read = fread(raw_binary, 1, raw_binary_length, file);
    if (bytes_read != raw_binary_length) {
        fprintf(stderr, "Failed to read file.\n");
        return -1;
    }
    return raw_binary_length;
}

int main(int argc, char *argv[]) {
    // Assertions.
    static_assert(sizeof(union Instruction) == INSTRUCTION_SIZE, "Error: sizeof(struct Instruction) needs to be INSTRUCTION_SIZE bytes.");
	// Parse arguments.
	if (argc != 2) {
		fprintf(stderr, "Usage: ./disassembler out.bin\n");
		return EXIT_FAILURE;
	}
    // Load binary file.
    long raw_binary_length = load_binary(argv);
    if (raw_binary_length < 0) {
        cleanup();
        return EXIT_FAILURE;
    }
    // Disassemble the raw binary.
    long valid_instructions = disassemble(raw_binary_length, raw_binary);
    if (valid_instructions < 0) {
        cleanup();
        return EXIT_FAILURE;
    }
    // Clean up.
    cleanup();
    return 0;
}
