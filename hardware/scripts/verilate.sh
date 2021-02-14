#!/bin/bash

cd rtl
verilator --trace --trace-depth 1 -Wno-timescalemod -Wno-fatal -Igpu/ --cc verilator_test.v --exe --build verilator_main.cpp
#verilator -Wno-timescalemod -Wno-fatal -Igpu/ --cc verilator_test.v --exe --build verilator_main.cpp
cd ..
rtl/obj_dir/Vverilator_test
