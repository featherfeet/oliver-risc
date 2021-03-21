#include "astvariableassignmentnode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTVariableAssignmentNode::ASTVariableAssignmentNode(std::string variable_name, ASTExpressionNode *value) {
    this->variable_name = variable_name;
    this->value = value;
}

ASTNodeType ASTVariableAssignmentNode::getNodeType() {
    return VARIABLE_ASSIGNMENT_NODE;
}

ASTExpressionNode *ASTVariableAssignmentNode::getExpressionNode() {
    return value;
}

std::string ASTVariableAssignmentNode::getHumanReadable() {
    return fmt::format("Assign variable `{}`.", variable_name);
}

std::string ASTVariableAssignmentNode::getVariableName() {
    return variable_name;
}

ASTVariableAssignmentNode::~ASTVariableAssignmentNode() {
    delete value;
}
