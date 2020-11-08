#!/bin/bash

build/compiler "$1" output.asm
build/assembler output.asm out.bin
../roms/romgenerator/romgenerator out.bin ../roms/romgenerator/rom.v ../roms/romgenerator/rom.mem

rm output.asm
