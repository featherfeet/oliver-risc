#include "ast.h"
#include "processor.h"
#include <string>
#include <memory>

ASTRootNode::addStatement(std::shared_ptr<ASTStatementNode> node) {
    children.push_back(node);
}

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name) {
    this->variable_name = variable_name;
    this->value = 0;
}

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value) {
    this->variable_name = variable_name;
    this->value = value;
}

ASTTermNode(TermNodeSign sign, OPERAND_C_TYPE constant_value) {
    this->sign = sign;
    this->constant_value = constant_value;
    this->type = CONSTANT;
}

ASTTermNode(TermNodeSign sign, std::string variable_name) {
    this->sign = sign;
    this->variable_name = variable_name;
    this->type = VARIABLE;
}

void ASTExpressionNode::addTerm(std::shared_ptr<ASTTermNode> term) {
    terms.push_back(term);
}

ASTVariableAssignmentNode(std::string variable_name, std::shared_ptr<ASTExpressionNode> value) {
    this->variable_name = variable_name;
    this->value = value;
}
