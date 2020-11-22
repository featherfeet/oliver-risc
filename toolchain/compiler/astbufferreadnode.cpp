#include "processor.h"
#include "astbufferreadnode.h"

#include <sstream>
#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTBufferReadNode::ASTBufferReadNode(TermNodeOperation operation, std::string variable_name, OPERAND_C_TYPE constant_value) {
    this->operation = operation;
    this->variable_name = variable_name;
    this->constant_value = constant_value;
    this->type = CONSTANT;
}

ASTBufferReadNode::ASTBufferReadNode(TermNodeOperation operation, std::string variable_name, std::string variable_value) {
    this->operation = operation;
    this->variable_name = variable_name;
    this->variable_value = variable_value;
    this->type = VARIABLE;
}

ASTNodeType ASTBufferReadNode::getNodeType() {
    return BUFFER_READ_NODE;
}

TermNodeType ASTBufferReadNode::getType() {
    return type;
}

std::string ASTBufferReadNode::getHumanReadable() {
    std::stringstream human_readable;
    if (operation == ADDITION) {
        human_readable << "+ ";
    }
    else if (operation == SUBTRACTION) {
        human_readable << "- ";
    }
    else if (operation == MULTIPLICATION) {
        human_readable << "* ";
    }
    else if (operation == DIVISION) {
        human_readable << "/ ";
    }
    else if (operation == MODULUS) {
        human_readable << "% ";
    }

    if (type == CONSTANT) {
        human_readable << fmt::format("{}[{}]", variable_name, constant_value);
    }
    else if (type == VARIABLE) {
        human_readable << fmt::format("{}[{}]", variable_name, variable_value);
    }
    return human_readable.str();
}

std::string ASTBufferReadNode::getVariableName() {
    return variable_name;
}

TermNodeOperation ASTBufferReadNode::getOperation() {
    return operation;
}

OPERAND_C_TYPE ASTBufferReadNode::getConstantValue() {
    return constant_value;
}

std::string ASTBufferReadNode::getVariableValue() {
    return variable_value;
}
