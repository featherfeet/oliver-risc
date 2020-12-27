#!/usr/bin/env python3

import re
import csv

csv_reader = csv.reader(open("ps2_keyboard_scancodes.csv")) # CSV file using data from the table at https://techdocs.altium.com/display/FPGA/PS2+Keyboard+Scan+Codes.

print("    match key {")

for i, line in enumerate(csv_reader):
    raw_key_cell = line[0]
    raw_scancode_cell = line[1]
    raw_scancode_text = raw_scancode_cell[raw_scancode_cell.index('(') + 1 : raw_scancode_cell.index(')')]
    if raw_key_cell == "Pause/Break":
        raw_scancode_text = "E11477E1F014E077"
    if len(raw_key_cell) == 1:
        key_name = "b'{}'".format(raw_key_cell)
    else:
        key_name = "KEY_" + raw_key_cell.upper().replace(' ', '_')
    hex_bytes = re.findall("..", raw_scancode_text) # Splits the scancode text into two-character strings.
    hex_bytes = ["0x" + hex_pair for hex_pair in hex_bytes]
    print("        {} => vec!{},".format(key_name, str(hex_bytes).replace("'", '')))

print("    }")
