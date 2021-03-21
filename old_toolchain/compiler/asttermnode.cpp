#include "asttermnode.h"

#include <sstream>

ASTTermNode::ASTTermNode(TermNodeOperation operation, OPERAND_C_TYPE constant_value) {
    this->operation = operation;
    this->constant_value = constant_value;
    this->type = CONSTANT;
}

ASTTermNode::ASTTermNode(TermNodeOperation operation, std::string variable_name) {
    this->operation = operation;
    this->variable_name = variable_name;
    this->type = VARIABLE;
}

ASTNodeType ASTTermNode::getNodeType() {
    return TERM_NODE;
}

std::string ASTTermNode::getHumanReadable() {
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
    if (type == VARIABLE) {
        human_readable << variable_name;
    }
    else {
        human_readable << constant_value;
    }
    return human_readable.str();
}

TermNodeOperation ASTTermNode::getOperation() {
    return operation;
}

TermNodeType ASTTermNode::getType() {
    return type;
}

OPERAND_C_TYPE ASTTermNode::getConstantValue() {
    return constant_value;
}

std::string ASTTermNode::getVariableName() {
    return variable_name;
}
