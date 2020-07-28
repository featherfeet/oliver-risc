#!/bin/bash

cd rtl
iverilog -o ../icarus_output *.v gpu/*.v indicators/*.v sdram/*.v
cd ..
