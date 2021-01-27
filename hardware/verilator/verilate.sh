#!/bin/bash

verilator --trace -Wno-timescalemod -Wno-fatal --cc test.v --exe --build sim_main.cpp
