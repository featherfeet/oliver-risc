#!/bin/bash

cd rust_assembler
cargo run ../../programs/decompressor.asm
cd ..
./toolchain.sh ../programs/sd_card_test.pl0
cd compressor
./compressor.py ../out.bin ../out.bin.lzw
cd ..
cat rust_assembler/out.bin out.bin.lzw > final.bin
cd rust_emulator
cargo run ../final.bin
