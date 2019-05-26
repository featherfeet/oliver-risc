#!/bin/bash

cd rtl
iverilog -o ../icarus_output *.v
cd ..
