#include "astprocedurenode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTProcedureNode::ASTProcedureNode(std::string procedure_name, ASTBeginEndBlockNode *begin_end_block) {
    this->procedure_name = procedure_name;
    this->begin_end_block = begin_end_block;
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

ASTProcedureNode::~ASTProcedureNode() {
    delete begin_end_block;
}
