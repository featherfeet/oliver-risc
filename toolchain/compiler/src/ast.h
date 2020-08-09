#ifndef AST_H
#define AST_H

#include <vector>
#include <memory>
#include "processor.h"

enum ASTNodeType {
    ROOT_NODE,
    VARIABLE_DECLARATION_NODE,
    VARIABLE_ASSIGNMENT_NODE,
    EXPRESSION_NODE,
    TERM_NODE
};


class ASTStatementNode {
};

class ASTRootNode {
    std::vector<std::shared_ptr<ASTStatementNode>> children;
    public:
        void addStatement(std::shared_ptr<ASTStatementNode> node);
};

class ASTVariableDeclarationNode : public ASTStatementNode {
    std::string variable_name;
    OPERAND_C_TYPE value;

    public:
        ASTVariableDeclarationNode(std::string variable_name);
        ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value);
};

enum TermNodeSign {
    POSITIVE,
    NEGATIVE
};

enum TermNodeType {
    VARIABLE,
    CONSTANT
};

class ASTTermNode {
    TermNodeSign sign;
    TermNodeType type;
    OPERAND_C_TYPE constant_value;
    std::string variable_name;

    public:
        ASTTermNode(TermNodeSign sign, OPERAND_C_TYPE constant_value);
        ASTTermNode(TermNodeSign sign, std::string variable_name);
};

class ASTExpressionNode {
    std::vector<std::shared_ptr<ASTTermNode>> terms;

    public:
        void addTerm(std::shared_ptr<ASTTermNode> term);
};

class ASTVariableAssignmentNode : public ASTStatementNode {
    std::string variable_name;
    std::shared_ptr<ASTExpressionNode> value;

    public:
        ASTVariableAssignmentNode(std::string variable_name, std::shared_ptr<ASTExpressionNode> value);
};

#endif // AST_H
