#include "astprocedurereturnnode.h"

ASTNodeType ASTProcedureReturnNode::getNodeType() {
    return PROCEDURE_RETURN_NODE;
}

std::string ASTProcedureReturnNode::getHumanReadable() {
    return "Return from procedure.";
}
