#include "astprocedurecallnode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTProcedureCallNode::ASTProcedureCallNode(std::string procedure_name) {
    this->procedure_name = procedure_name;
}

ASTNodeType ASTProcedureCallNode::getNodeType() {
    return PROCEDURE_CALL_NODE;
}

std::string ASTProcedureCallNode::getHumanReadable() {
    return fmt::format("Call procedure `{}`.", procedure_name);
}

std::string ASTProcedureCallNode::getProcedureName() {
    return procedure_name;
}
