#include <iostream>
#include "stackframe.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

Stackframe::Stackframe() {
    variable_offsets["_"] = address_counter; // Reserve space on the stack for where the return-jump address is stored.
    address_counter += OPERAND_SIZE;
}

void Stackframe::addVariable(std::string name, size_t size) {
    variable_offsets[name] = address_counter;
    address_counter += size;
}

OPERAND_C_TYPE Stackframe::getVariableOffset(std::string name) {
    if (variable_offsets.find(name) == variable_offsets.end()) {
        std::cout << fmt::format("\033[1;31mERROR:\033[0m Unknown variable `{}` referenced.", name) << std::endl;
        std::exit(1);
    }
    return variable_offsets[name];
}

OPERAND_C_TYPE Stackframe::getTotalSize() {
    return address_counter;
}

bool Stackframe::containsVariable(std::string name) {
    return variable_offsets.count(name);
}
