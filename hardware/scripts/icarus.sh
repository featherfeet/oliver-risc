#!/bin/bash

cd rtl
iverilog -o ../icarus_output -I gpu -I alu defines.v test.v top.v rom.v keyboard.v fifo.v clock_generator.v gpu/*.v sdram/*.v -l libraries/altera_mf.v -l libraries/220model.v
cd ..
