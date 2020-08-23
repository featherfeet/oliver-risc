#include <iostream>
#include <string>
#include "asmgenerator.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

AssemblyGenerator::AssemblyGenerator() {
    data_section << ".data:" << std::endl;
    code_section << ".code:" << std::endl;
}

std::string AssemblyGenerator::getGeneratedAssembly() {
    return data_section.str() + code_section.str();
}

void AssemblyGenerator::generateAsm(ASTNode *node) {
    if (node->getNodeType() == ROOT_NODE) {
        ASTRootNode *rootNode = (ASTRootNode *) node;
        std::vector<ASTStatementNode*> children = rootNode->getChildren();

        for (int i = 0; i < children.size(); i++) {
            generateAsm(children[i]);
        }
    }

    else if (node->getNodeType() == VARIABLE_DECLARATION_NODE) {
        ASTVariableDeclarationNode *declaration = (ASTVariableDeclarationNode *) node;
        data_section << fmt::format("    {} = {}", declaration->getVariableName(), declaration->getValue()) << std::endl;
    }

    else if (node->getNodeType() == VARIABLE_ASSIGNMENT_NODE) {
        ASTVariableAssignmentNode *assignment = (ASTVariableAssignmentNode *) node;

        generateAsm(assignment->getExpressionNode());
        code_section << fmt::format("    STORE A,{}", assignment->getVariableName()) << std::endl;
    }

    else if (node->getNodeType() == EXPRESSION_NODE) {
        ASTExpressionNode *expression = (ASTExpressionNode *) node;
        std::vector<ASTTermNode*> terms = expression->getTerms();

        code_section << "    CLOAD 0,A" << std::endl;

        for (int i = 0; i < terms.size(); i++) {
            ASTTermNode *term = terms[i];

            if (term->getType() == CONSTANT) {
                code_section << fmt::format("    CLOAD {},B", term->getConstantValue()) << std::endl;
            }
            else if (term->getType() == VARIABLE) {
                code_section << fmt::format("    LOAD {},B", term->getVariableName()) << std::endl;
            }
            if (term->getSign() == POSITIVE) {
                code_section << "    ADD A,B" << std::endl;
            }
            else if (term->getSign() == NEGATIVE) {
                code_section << "    SUB A,B" << std::endl;
            }
        }
    }
}
