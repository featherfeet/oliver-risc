#include "astbufferwritenode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTBufferWriteNode::ASTBufferWriteNode(std::string variable_name, ASTExpressionNode *offset_expression, ASTExpressionNode *value_expression) {
    this->variable_name = variable_name;
    this->offset_expression = offset_expression;
    this->value_expression = value_expression;
}

ASTNodeType ASTBufferWriteNode::getNodeType() {
    return BUFFER_WRITE_NODE;
}

std::string ASTBufferWriteNode::getHumanReadable() {
    return fmt::format("Buffer write to variable `{}`.", variable_name);
}

ASTExpressionNode *ASTBufferWriteNode::getOffsetExpression() {
    return offset_expression;
}

ASTExpressionNode *ASTBufferWriteNode::getValueExpression() {
    return value_expression;
}

std::string ASTBufferWriteNode::getVariableName() {
    return variable_name;
}

ASTBufferWriteNode::~ASTBufferWriteNode() {
    delete offset_expression;
    delete value_expression;
}
