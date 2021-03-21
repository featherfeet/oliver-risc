#ifndef AST_VARIABLE_DECLARATION_NODE_H
#define AST_VARIABLE_DECLARATION_NODE_H

#include "processor.h"
#include "ast.h"
#include "aststatementnode.h"

#include <string>

enum ASTVariableDeclarationNodeType {
    INTEGER_DECLARATION,
    STRING_DECLARATION
};

class ASTVariableDeclarationNode : public ASTStatementNode {
    std::string variable_name;
    OPERAND_C_TYPE integer_value;
    std::string string_value;
    ASTVariableDeclarationNodeType node_type;

    public:
        ASTVariableDeclarationNode(std::string variable_name);
        ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value);
        ASTVariableDeclarationNode(std::string variable_name, std::string value);
        ASTNodeType getNodeType();
        ASTVariableDeclarationNodeType getVariableDeclarationNodeType();
        std::string getHumanReadable();
        std::string getVariableName();
        OPERAND_C_TYPE getIntegerValue();
        std::string getStringValue();
};

#endif // AST_VARIABLE_DECLARATION_NODE_H
