#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH_PIXELS 1920
#define SCREEN_HEIGHT_PIXELS 1080
#define SCREEN_WIDTH_COLUMNS 240
#define SCREEN_HEIGHT_ROWS 67

#define CHARACTER_CELL_WIDTH_PIXELS (SCREEN_WIDTH_PIXELS / SCREEN_WIDTH_COLUMNS)
#define CHARACTER_CELL_HEIGHT_PIXELS (SCREEN_HEIGHT_PIXELS / SCREEN_HEIGHT_ROWS)

#define NUMBER_OF_CHARACTERS 128

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./font_rom_generator unifont.hex font_rom.v font_rom.mem\n");
        printf("unifont.hex is the input Unifont font file. font_rom.v is the name of the output Verilog file. font_rom.mem is the name of the output Verilog readmemh() file used by font_rom.v.\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *verilog_output_file = fopen(argv[2], "w");
    FILE *mem_output_file = fopen(argv[3], "w");

    // Write the Verilog module header.
    fprintf(verilog_output_file, "module font_rom(input CLOCK_150, input[6:0] character, input[$clog2(%u) - 1:0] character_cell_x, input[$clog2(%u) - 1:0] character_cell_y, output reg pixel_value);\n", CHARACTER_CELL_WIDTH_PIXELS, CHARACTER_CELL_HEIGHT_PIXELS);
    fprintf(verilog_output_file, "\treg[0:127] font_storage[0:%u - 1];\n", NUMBER_OF_CHARACTERS);
    fprintf(verilog_output_file, "\tinitial begin\n");
    fprintf(verilog_output_file, "\t\t$readmemh(\"rtl/gpu/font_rom.mem\", font_storage);\n");
    fprintf(verilog_output_file, "\tend\n");
    fprintf(verilog_output_file, "\talways @(posedge CLOCK_150)\n");
    fprintf(verilog_output_file, "\tbegin\n");
    fprintf(verilog_output_file, "\t\tif ((character_cell_y * 'd%u + character_cell_x) > 'd127)\n", CHARACTER_CELL_WIDTH_PIXELS);
    fprintf(verilog_output_file, "\t\t\tpixel_value <= 'b0;\n");
    fprintf(verilog_output_file, "\t\telse\n");
    fprintf(verilog_output_file, "\t\t\tpixel_value <= font_storage[character][character_cell_y * 'd%u + character_cell_x];\n", CHARACTER_CELL_WIDTH_PIXELS);
    fprintf(verilog_output_file, "\tend\n");
    fprintf(verilog_output_file, "endmodule");
    // Write the body of the Verilog model.
    for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
        unsigned int ascii_value;
        char hex_string_bitmap[65];
        fscanf(input_file, "%x:%s\n", &ascii_value, hex_string_bitmap);

        printf("ASCII value %d has bitstring %s.\n", ascii_value, hex_string_bitmap);

        if (strlen(hex_string_bitmap) == 32) {
            fprintf(mem_output_file, "%s\n", hex_string_bitmap);
        }
        else {
            fprintf(mem_output_file, "00000000000000000000000000000000\n");
        }
    }

    fclose(input_file);
    fclose(verilog_output_file);
    fclose(mem_output_file);
    return 0;
}
