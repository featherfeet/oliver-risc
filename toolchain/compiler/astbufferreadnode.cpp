#include "processor.h"
#include "astbufferreadnode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTBufferReadNode::ASTBufferReadNode(TermNodeOperation operation, std::string variable_name, ASTExpressionNode *offset_expression) {
    this->operation = operation;
    this->variable_name = variable_name;
    this->offset_expression = offset_expression;
}

ASTNodeType ASTBufferReadNode::getNodeType() {
    return BUFFER_READ_NODE;
}

std::string ASTBufferReadNode::getHumanReadable() {
    return fmt::format("Buffer read from variable `{}`.", variable_name);
}

ASTExpressionNode *ASTBufferReadNode::getOffsetExpression() {
    return offset_expression;
}

std::string ASTBufferReadNode::getVariableName() {
    return variable_name;
}

TermNodeOperation ASTBufferReadNode::getOperation() {
    return operation;
}

ASTBufferReadNode::~ASTBufferReadNode() {
    delete offset_expression;
}
