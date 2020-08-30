#!/bin/bash

FILENAME=$1

cd compiler/build
./main "../../$1" output.asm
cd ../../assembler/build
./main ../../compiler/build/output.asm out.bin
cd ../../romgenerator
make run
