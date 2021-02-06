#ifndef STACKFRAME_H
#define STACKFRAME_H

#include "processor.h"
#include <map>
#include <string>

class Stackframe {
    OPERAND_C_TYPE address_counter = 0;
    std::map<std::string, OPERAND_C_TYPE> variable_offsets;
    std::string procedure_name;

    public:
        Stackframe(std::string procedure_name);
        void addVariable(std::string name, size_t size);
        OPERAND_C_TYPE getVariableOffset(std::string name);
        OPERAND_C_TYPE getTotalSize();
        bool containsVariable(std::string name);
        std::string getProcedureName();
};

#endif // STACKFRAME_H
