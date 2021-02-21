// Assembly program for making self-decompressing programs for the CPU.
// To make a self-decompressing program, first compile your actual program to a binary (this sequence of commands should be run from the toolchain/ directory):
// $ ./toolchain.sh program.pl0
// Then rename that program's binary:
// $ mv out.bin program.bin
// Then compress that binary:
// $ compressor/compressor.py program.bin program.bin.lzw
// Then assemble this file:
// $ cargo run --manifest-path rust_assembler/Cargo.toml -- ../programs/decompressor.asm decompressor.bin
// Then concatenate the binary of this program with your program's compressed binary:
// $ cat decompressor.bin program.bin.lzw > program_self_decompressing.bin

// A reference C implementation of this decompressor is in toolchain/compressor/reference_decompressor/reference_decompressor.c.

// Memory layout:
//     'dictionary_item_sizes' starts at address 4_000_100. Each element of the array is an unsigned integer that is 4 bytes long.
//     'dictionary' starts at address 4_100_000. Each element of the array is a pointer that is 4 bytes long.
//     'dictionary_items' starts at address 4_200_000.
//     'output_data' starts at address 4_300_000.
//     'input_index' is in register B.
//     'dictionary_length' is in register F.
//     'dictionary_items_size_bytes' is in register G.

.data:
    input_data = 0
    input_file_size = 0
    temp0 = 0
    code_section_start_offset = 0 // Kinda a hack. Getting the address of this variable and adding 4 to it tells us where the .data: section ends, which is useful to calculate absolute addresses.
.code:
    // Build the initial dictionary of all one-byte values.
    CLOAD 0,B // index
    initialize_dictionary_loop:
        // dictionary[index] = dictionary_items + index
        CLOAD 4200000,D // dictionary_items
        ADD B,D
        MOV A,C
        CLOAD 4,D
        MULT B,D
        CLOAD 4100000,D // dictionary
        ADD A,D
        RSTORE C,A
        // dictionary_item_sizes[index] = 1
        CLOAD 4000100,C
        CLOAD 4,D
        MULT B,D
        ADD A,C
        CLOAD 1,C
        RSTORE C,A
        // dictionary_items[dictionary_items_size_bytes] = index
        CLOAD 4200000,D
        ADD G,D
        RSTORE B,A // The overlap between writes doesn't matter because we are looping forwards.
        // dictionary_items_size_bytes++
        CLOAD 1,C
        ADD G,C
        MOV A,G
        // Increment index (B).
        CLOAD 1,C
        ADD B,C
        MOV A,B
        // End the loop when index (B) gets to 255.
        CLOAD 256,C
        CMP B,C
        JMPL initialize_dictionary_loop
    CLOAD 256,F // dictionary_length = 256

    // Load the size of the input from the first two bytes of the input data.
    CLOAD start_of_input_data,B
    CLOAD [code_section_start_offset],A
    CLOAD 4,C
    ADD A,C
    ADD A,B
    STORE A,input_data // input_data is a pointer (address) to the start of the input data.
    RLOAD A,B
    CLOAD 65535,C
    AND B,C
    STORE A,input_file_size // input_file_size stores the size of the input data in bytes.

    // memcpy(&input_index, input_data + 2, 2), where register B is used to store input_index.
    LOAD input_data,A
    CLOAD 2,C
    ADD A,C
    RLOAD A,B
    CLOAD 65535,A
    AND A,B
    MOV A,B

    // Main decompression loop.
    decompression_loop:
        // Output the string at input_index in the dictionary.
            // Get dictionary[input_index] into register C and dictionary_item_sizes[input_index] into register A.
            STORE F,temp0
            CLOAD 4,C
            MULT B,C
            MOV A,D
            CLOAD 4100000,C
            ADD D,C
            MOV A,C
            CLOAD 4000100,C
            ADD D,C
            CLOAD 4300000,E // output_data
            copy_loop_1:
                RLOAD C,D
                RSTORE D,E
                CLOAD 1,F
                STORE A,temp1
                ADD E,F
                MOV A,E
                LOAD temp1,A
                SUB A,F
                CLOAD 0,D
                CMP 
            LOAD temp0,F

    HALT

    start_of_input_data: // Since the compressed data will be concatenated onto the end of the binary created from this assembly program, this label will be the start address of the input data.
