#!/bin/bash

#vvp -M ./verilog-vga-simulator -m vgasim icarus_output -lxt2
vvp -M ./verilog-vga-simulator -m vgasim icarus_output -none
#vvp icarus_output -none
#gtkwave dump.lxt savefile.gtkw
