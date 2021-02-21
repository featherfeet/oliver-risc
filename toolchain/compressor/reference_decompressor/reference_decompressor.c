#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_DICTIONARY_SIZE 65536 // maximum number of items in the LZW dictionary (the maximum number of items that can be indexed with 2-byte unsigned integers)

uint8_t **dictionary = NULL; // Each element in the dictionary array is a pointer to a buffer containing a dictionary item.
uint32_t *dictionary_item_sizes = NULL; // Stores the lengths (in bytes) of dictionary items.

uint8_t *dictionary_items = NULL; // Stores all the dictionary items, end-to-end in a single buffer.

int dictionary_length = 0; // Stores the number of items in the dictionary.
int dictionary_items_size_bytes = 0; // Stores the number of bytes in use of the dictionary_items buffer.

FILE *input_file = NULL;
FILE *output_file = NULL;
uint8_t *input_data = NULL;

void cleanup() {
    if (input_file) {
        fclose(input_file);
        input_file = NULL;
    }
    if (output_file) {
        fclose(output_file);
        output_file = NULL;
    }
    if (input_data) {
        free(input_data);
        input_data = NULL;
    }
    if (dictionary) {
        free(dictionary);
        dictionary = NULL;
    }
    if (dictionary_item_sizes) {
        free(dictionary_item_sizes);
        dictionary_item_sizes = NULL;
    }
    if (dictionary_items) {
        free(dictionary_items);
        dictionary_items = NULL;
    }
}

void display_dictionary() {
    printf("[0-255]: [0-255]\n");
    for (int index = 256; index < dictionary_length; index++) {
        printf("%d: ", index);
        uint8_t *dictionary_item = dictionary[index];
        for (int i = 0; i < dictionary_item_sizes[index]; i++) {
            if (dictionary_item[i] >= 'A' && dictionary_item[i] <= 'z') {
                printf("%c ", dictionary_item[i]);
            }
            else {
                printf("%u ", dictionary_item[i]);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    // Check arguments and display help if necessary.
    if (argc != 3) {
        fprintf(stderr, "Usage: ./reference_decompressor out.bin.lzw out.bin\n");
        cleanup();
        return 1;
    }

    // Read in input (compressed) data.
    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input file.\n");
        cleanup();
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    input_data = calloc(input_file_size, 1);
    if (!input_data) {
        fprintf(stderr, "Error: Could not allocate memory for input data.\n");
        cleanup();
        return 1;
    }
    size_t bytes_read = fread(input_data, 1, input_file_size, input_file);
    if (bytes_read != input_file_size) {
        fprintf(stderr, "Error: Could not read entire input file.\n");
        cleanup();
        return 1;
    }
    if (input_file_size % 2 != 0) {
        fprintf(stderr, "Error: Input file size must be an even number of bytes.\n");
        cleanup();
        return 1;
    }

    // Open output (uncompressed) file for writing.
    output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fprintf(stderr, "Error: Could not open output file.\n");
        cleanup();
        return 1;
    }

    // Allocate memory for data structures.
    dictionary = calloc(MAX_DICTIONARY_SIZE, 1);
    if (!dictionary) {
        fprintf(stderr, "Error: Could not allocate enough memory for dictionary.\n");
        cleanup();
        return 1;
    }
    dictionary_item_sizes = calloc(MAX_DICTIONARY_SIZE, sizeof(uint32_t));
    if (!dictionary_item_sizes) {
        fprintf(stderr, "Error: Could not allocate enough memory for dictionary item lengths.\n");
        cleanup();
        return 1;
    }
    dictionary_items = calloc(4000000, 1); // 4 MB should be enough to hold all of the dictionary items (and that is the amount of space available on the FPGA CPU's heap, anyways).
    if (!dictionary_items) {
        fprintf(stderr, "Error: Could not allocate enough memory for dictionary items.\n");
        cleanup();
        return 1;
    }

    // Build the initial dictionary, which contains all 1-byte values.
    for (int index = 0; index < 256; index++) {
        dictionary[index] = (uint8_t *) (dictionary_items + dictionary_items_size_bytes);
        dictionary_item_sizes[index] = 1;
        dictionary_items[dictionary_items_size_bytes] = index;
        dictionary_items_size_bytes += 1;
        dictionary_length++;
    }

    // Read the first two bytes of the file and check that they contain the length of the file in bytes.
    uint16_t first_two_bytes;
    memcpy(&first_two_bytes, input_data, 2);
    if (first_two_bytes != input_file_size) {
        fprintf(stderr, "ERROR: The first two bytes of the file should be a little-endian unsigned integer containing the length of the file.\n");
        cleanup();
        return 1;
    }

    // Decompress (see https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch#Decoding).
    uint16_t input_index;
    memcpy(&input_index, input_data + 2, 2); // Read in the first input token. Each input token is an index in the dictionary.
    for (uint32_t i = 4; i <= input_file_size; i += 2) {
        //printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //display_dictionary();
        // Output the string at input_index in the dictionary.
        fwrite(dictionary[input_index], 1, dictionary_item_sizes[input_index], output_file);
        // Create a new entry in the dictionary.
        dictionary[dictionary_length] = (uint8_t *) (dictionary_items + dictionary_items_size_bytes);
        dictionary_item_sizes[dictionary_length] = dictionary_item_sizes[input_index];
        memcpy(dictionary[dictionary_length], dictionary[input_index], dictionary_item_sizes[input_index]);
        dictionary_items_size_bytes += dictionary_item_sizes[input_index];
        // If we're on the last iteration, quit before trying to read the next token.
        if (i == input_file_size) {
            break;
        }
        // Read the next token and use it to build the dictionary, if necessary.
        uint16_t next_index;
        memcpy(&next_index, input_data + i, 2);
        if (next_index < dictionary_length) {
            // If the next token is in the dictionary, concatenate the first byte of its entry onto the end of the entry that we just added to the dictionary.
            memcpy(dictionary[dictionary_length] + dictionary_item_sizes[dictionary_length], dictionary[next_index], 1);
            dictionary_item_sizes[dictionary_length] += 1;
            dictionary_items_size_bytes++;
        }
        else {
            // If the next token is not in the dictionary, then concatenate the first byte of the current string onto the entry that we just added to the dictionary.
            *(dictionary[dictionary_length] + dictionary_item_sizes[input_index]) = *dictionary[dictionary_length];
            dictionary_item_sizes[dictionary_length]++;
            dictionary_items_size_bytes++;
        }
        dictionary_length++;
        // Next.
        input_index = next_index;
    }

    // Cleanup.
    cleanup();
    return 0;
}
