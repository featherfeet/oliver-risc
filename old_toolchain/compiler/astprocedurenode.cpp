#include "astprocedurenode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTProcedureNode::ASTProcedureNode(std::string procedure_name, ASTBeginEndBlockNode *begin_end_block, bool is_isr) {
    this->procedure_name = procedure_name;
    this->begin_end_block = begin_end_block;
    this->is_isr = is_isr;
}

ASTNodeType ASTProcedureNode::getNodeType() {
    return PROCEDURE_NODE;
}

std::string ASTProcedureNode::getHumanReadable() {
    return fmt::format("Procedure `{}`.", procedure_name);
}

std::string ASTProcedureNode::getProcedureName() {
    return procedure_name;
}

ASTBeginEndBlockNode *ASTProcedureNode::getBeginEndBlock() {
    return begin_end_block;
}

bool ASTProcedureNode::getIsISR() {
    return is_isr;
}

ASTProcedureNode::~ASTProcedureNode() {
    delete begin_end_block;
}
