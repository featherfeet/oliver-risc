#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Help:\n");
        printf("./romgenerator out.bin rom.v rom.mem\n");
        printf("Converts from a binary (from the assembler) called out.bin to a Verilog file called rom.v and a hex memory file called rom.mem. Rom.v will use the Verilog readmemh() function load the .mem file.\n");
        return 1;
    }
    // Read in input binary file
    FILE *binary = fopen(argv[1], "rb");
    fseek(binary, 0, SEEK_END);
    long binary_size = ftell(binary);
    fseek(binary, 0, SEEK_SET);
    uint8_t *binary_data = malloc(binary_size);
    fread(binary_data, binary_size, 1, binary);
    // Open output Verilog file.
    FILE *verilog = fopen(argv[2], "w");
    // Open output .mem file.
    FILE *mem = fopen(argv[3], "w");
    // Write the Verilog module header.
    fprintf(verilog, "module rom(input CLOCK_50, input[31:0] address, output reg [7:0] output_byte, output done);\n");
    fprintf(verilog, "\tassign done = (address == 32'd%u);\n", binary_size - 1);
    fprintf(verilog, "\treg[0:7] rom_memory[0:%d - 1];\n", binary_size);
    fprintf(verilog, "\tinitial begin\n");
    fprintf(verilog, "\t\t$readmemh(\"rtl/rom.mem\", rom_memory);\n");
    fprintf(verilog, "\tend\n");
    fprintf(verilog, "\talways @(posedge CLOCK_50)\n");
    fprintf(verilog, "\tbegin\n");
    fprintf(verilog, "\t\toutput_byte <= rom_memory[address];\n");
    fprintf(verilog, "\tend\n");
    fprintf(verilog, "endmodule");
    // Write the .mem file with the hex data for the ROM.
    for (int i = 0; i < binary_size; i++) {
        fprintf(mem, "%02X\n", binary_data[i]);
    }
    // Close files.
    fclose(verilog);
    fclose(mem);
    fclose(binary);
    return 0;
}
