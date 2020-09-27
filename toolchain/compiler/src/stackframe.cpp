#include <iostream>
#include "stackframe.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

void Stackframe::addVariable(std::string name, size_t size) {
    variable_offsets[name] = size;
}

OPERAND_C_TYPE Stackframe::getVariableOffset(std::string name) {
    if (variable_offsets.find(name) == variable_offsets.end()) {
        std::cout << fmt::format("\033[1;31mERROR:\033[0m Unknown variable `{}` referenced.", name) << std::endl;
        std::exit(1);
    }
    return variable_offsets[name];
}

OPERAND_C_TYPE Stackframe::getTotalSize() {
    OPERAND_C_TYPE total_size = 0;
    for (auto variable_offset : variable_offsets) {
        total_size += variable_offset.second;
    }
    return total_size;
}
