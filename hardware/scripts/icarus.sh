#!/bin/bash

cd rtl
iverilog -o ../icarus_output -I gpu -I alu *.v gpu/*.v sdram/*.v -l libraries/altera_mf.v -l libraries/220model.v
cd ..
