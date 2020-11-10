#include "astvariabledeclarationnode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name) {
    this->node_type = INTEGER_DECLARATION;
    this->variable_name = variable_name;
    this->integer_value = 0;
}

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value) {
    this->node_type = INTEGER_DECLARATION;
    this->variable_name = variable_name;
    this->integer_value = value;
}

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name, std::string value) {
    this->node_type = STRING_DECLARATION;
    this->variable_name = variable_name;
    this->string_value = value;
}

ASTNodeType ASTVariableDeclarationNode::getNodeType() {
    return VARIABLE_DECLARATION_NODE;
}

ASTVariableDeclarationNodeType ASTVariableDeclarationNode::getVariableDeclarationNodeType() {
    return node_type;
}

std::string ASTVariableDeclarationNode::getHumanReadable() {
    if (node_type == INTEGER_DECLARATION) {
        return fmt::format("Declare `{}` as {}.", variable_name, integer_value);
    }
    else if (node_type == STRING_DECLARATION) {
        return fmt::format("Declare `{}` as `{}`.", variable_name, string_value);
    }
    return "UNKNOWN";
}

std::string ASTVariableDeclarationNode::getVariableName() {
    return variable_name;
}

OPERAND_C_TYPE ASTVariableDeclarationNode::getIntegerValue() {
    return integer_value;
}

std::string ASTVariableDeclarationNode::getStringValue() {
    return string_value;
}
