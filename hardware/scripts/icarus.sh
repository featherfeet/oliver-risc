#!/bin/bash

cd rtl
iverilog -o ../icarus_output defines.v top.v test.v
cd ..
