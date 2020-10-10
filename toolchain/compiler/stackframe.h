#ifndef STACKFRAME_H
#define STACKFRAME_H

#include "processor.h"
#include <map>
#include <string>

class Stackframe {
    OPERAND_C_TYPE address_counter = 0;
    std::map<std::string, OPERAND_C_TYPE> variable_offsets;

    public:
        Stackframe();
        void addVariable(std::string name, size_t size);
        OPERAND_C_TYPE getVariableOffset(std::string name);
        OPERAND_C_TYPE getTotalSize();
        bool containsVariable(std::string name);
};

#endif // STACKFRAME_H
