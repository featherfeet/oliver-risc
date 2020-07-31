#!/bin/bash

cd rtl
iverilog -o ../icarus_output -I gpu *.v gpu/*.v indicators/*.v sdram/*.v
cd ..
