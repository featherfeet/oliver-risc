#include "disassembler.h"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    disassemble(Size, Data);
    return 0;
}
