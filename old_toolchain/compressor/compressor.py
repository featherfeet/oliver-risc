#!/usr/bin/env python3

"""LZW compressor for arbitrary binary data."""

import sys
import math

# Check arguments.
if len(sys.argv) != 3:
    print("Usage: ./compressor.py out.bin out.bin.lzw")
    sys.exit(1)

# Read in input data.
input_data = open(sys.argv[1], "rb").read()
print("Input data size:  {} bytes".format(len(input_data)))

# LZW algorithm, see https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch#Encoding
# Build starting dictionary with all strings of length 1.
dictionary = []
for i in range(256):
    dictionary.append(bytes([i]))
# Compress.
output_data = []
while len(input_data) > 0:
    # Find longest match for current input in the dictionary.
    longest_match_length = -1
    for index, string in enumerate(dictionary):
        if len(string) > longest_match_length and input_data.startswith(string):
            longest_match_index = index
            longest_match = string
    # Add to output data and update dictionary.
    output_data.append(longest_match_index)
    input_data = input_data[len(longest_match):]
    if len(input_data) > 0:
        dictionary.append(longest_match + bytes([input_data[0]]))

# Calculate the minimum number of bytes required to encode dictionary indices.
bytes_per_item = math.ceil(math.ceil(math.log2(len(dictionary))) / 8.0)

if bytes_per_item != 2:
    print("\033[1;31mERROR: This LZW implementation currently only supports dictionaries with 2-byte indices. Cannot compress this file.\033[0m")
    exit()

# Print out stats.
output_data_size = 2 + (len(output_data) * bytes_per_item)
print("Output data size: {} bytes".format(output_data_size))

# Write out output data.
output_file = open(sys.argv[2], "wb")
output_file.write((output_data_size).to_bytes(bytes_per_item, byteorder = "little"))
for item in output_data:
    output_file.write((item).to_bytes(bytes_per_item, byteorder = "little"))
output_file.close()

# Print out dictionary.
"""
print("[0-255]: [0-255]")
for i in range(256, len(dictionary)):
    item = dictionary[i]
    print("{}: ".format(i), end = '')
    for ch in item:
        if int(ch) >= ord('A') and int(ch) <= ord('z'):
            print(bytes([ch]).decode(), end = ' ')
        else:
            print(int(ch), end = ' ')
    print()
"""
