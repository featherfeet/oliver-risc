#include "astbufferwritenode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTBufferWriteNode::ASTBufferWriteNode(std::string variable_name, OPERAND_C_TYPE offset_constant_value, ASTExpressionNode *value_expression) {
    this->variable_name = variable_name;
    this->offset_constant_value = offset_constant_value;
    this->value_expression = value_expression;
    this->type = CONSTANT;
}

ASTBufferWriteNode::ASTBufferWriteNode(std::string variable_name, std::string offset_variable_value, ASTExpressionNode *value_expression) {
    this->variable_name = variable_name;
    this->offset_variable_value = offset_variable_value;
    this->value_expression = value_expression;
    this->type = VARIABLE;
}

ASTNodeType ASTBufferWriteNode::getNodeType() {
    return BUFFER_WRITE_NODE;
}

std::string ASTBufferWriteNode::getHumanReadable() {
    if (type == CONSTANT) {
        return fmt::format("Buffer write to variable `{}` at offset `{}`.", variable_name, offset_constant_value);
    }
    return fmt::format("Buffer write to variable `{}` at offset `{}`.", variable_name, offset_variable_value);
}

OPERAND_C_TYPE ASTBufferWriteNode::getOffsetConstantValue() {
    return offset_constant_value;
}

std::string ASTBufferWriteNode::getOffsetVariableValue() {
    return offset_variable_value;
}

ASTExpressionNode *ASTBufferWriteNode::getValueExpression() {
    return value_expression;
}

std::string ASTBufferWriteNode::getVariableName() {
    return variable_name;
}

TermNodeType ASTBufferWriteNode::getType() {
    return type;
}

ASTBufferWriteNode::~ASTBufferWriteNode() {
    delete value_expression;
}
