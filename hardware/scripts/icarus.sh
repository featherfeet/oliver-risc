#!/bin/bash

cd rtl
iverilog -o ../icarus_output -I gpu *.v gpu/*.v sdram/*.v -l libraries/altera_mf.v -l libraries/220model.v
cd ..
