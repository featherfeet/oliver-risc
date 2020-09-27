#ifndef STACKFRAME_H
#define STACKFRAME_H

#include "processor.h"
#include <map>
#include <string>

class Stackframe {
    std::map<std::string, OPERAND_C_TYPE> variable_offsets;

    public:
        void addVariable(std::string name, size_t size);
        OPERAND_C_TYPE getVariableOffset(std::string name);
        OPERAND_C_TYPE getTotalSize();
};

#endif // STACKFRAME_H
