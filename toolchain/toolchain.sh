#!/bin/bash

build/compiler "$1" output.asm
cargo run --manifest-path rust_assembler/Cargo.toml -- output.asm out.bin
../roms/romgenerator/romgenerator out.bin ../roms/romgenerator/rom.v ../roms/romgenerator/rom.mem

rm output.asm
