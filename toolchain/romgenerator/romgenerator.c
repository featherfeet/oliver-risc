#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Help:\n");
        printf("./romgenerator out.bin rom.v\n");
        printf("Converts from a binary (from the assembler) called out.bin to a Verilog file called rom.v. Rom.v will contain a lookup table module, like so:\n");
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
    // Write the Verilog module header.
    fprintf(verilog, "module rom(input[31:0] address, output reg [7:0] output_byte, output done);\n");
    fprintf(verilog, "\tassign done = (address == 32'd%d) ? 1'b1 : 1'b0;\n", binary_size - 1);
    fprintf(verilog, "\talways @(address)\n");
    fprintf(verilog, "\tbegin\n");
    // Write the body of the Verilog model.
    fprintf(verilog, "\t\tcase (address)\n");
    for (int i = 0; i < binary_size; i++) {
        fprintf(verilog, "\t\t\t32'd%d:\n", i);
        fprintf(verilog, "\t\t\t\toutput_byte = 8'd%d;\n", binary_data[i]);
    }
    fprintf(verilog, "\t\t\tdefault:\n");
    fprintf(verilog, "\t\t\t\toutput_byte = 8'd0;\n");
    fprintf(verilog, "\t\tendcase\n");
    fprintf(verilog, "\tend\n");
    fprintf(verilog, "endmodule");
    // Close files.
    fclose(verilog);
    fclose(binary);
    return 0;
}
