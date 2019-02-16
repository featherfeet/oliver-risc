#!/bin/bash

iverilog -o icarus_output rtl/*.v && vvp icarus_output -lxt2 && gtkwave dump.lxt
