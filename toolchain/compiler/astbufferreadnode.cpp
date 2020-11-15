#include "processor.h"
#include "astbufferreadnode.h"

#include <sstream>
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

    human_readable << fmt::format("{}[]", variable_name);
    return human_readable.str();
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
