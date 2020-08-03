#!/bin/bash

cd rtl
iverilog -o ../icarus_output -I gpu -l libraries/altera_mf.v *.v gpu/*.v sdram/*.v
cd ..
