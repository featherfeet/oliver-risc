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

        data_section << "    output_address = 0" << std::endl;
        data_section << "    output_value = 0" << std::endl;

        code_section << "    // Start root node." << std::endl;
        for (int i = 0; i < children.size(); i++) {
            generateAsm(children[i]);
        }
        code_section << "    // End root node." << std::endl;
    }

    else if (node->getNodeType() == VARIABLE_DECLARATION_NODE) {
        data_section << "    // Start variable declaration node." << std::endl;
        ASTVariableDeclarationNode *declaration = (ASTVariableDeclarationNode *) node;
        data_section << fmt::format("    {} = {}", declaration->getVariableName(), declaration->getValue()) << std::endl;
        data_section << "    // End variable declaration node." << std::endl;
    }

    else if (node->getNodeType() == VARIABLE_ASSIGNMENT_NODE) {
        code_section << "    // Start variable assignment node." << std::endl;
        ASTVariableAssignmentNode *assignment = (ASTVariableAssignmentNode *) node;

        generateAsm(assignment->getExpressionNode());

        std::string variable_name = assignment->getVariableName();
        code_section << fmt::format("    STORE A,{}", assignment->getVariableName()) << std::endl;

        code_section << "    // End variable assignment node." << std::endl;
    }

    else if (node->getNodeType() == EXPRESSION_NODE) {
        code_section << "    // Start expression node." << std::endl;
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
        code_section << "    // End expression node." << std::endl;
    }

    else if (node->getNodeType() == CONDITIONAL_NODE) {
        code_section << "    // Start conditional node." << std::endl;
        ASTConditionalNode *conditional = (ASTConditionalNode *) node;

        generateAsm(conditional->getCondition());

        std::string skip_label = fmt::format("label{}", label_counter);
        ConditionNodeComparison comparison = conditional->getCondition()->getComparison();
        if (comparison == NOT_EQUALS) {
            code_section << fmt::format("    JMPE {}", skip_label) << std::endl;
        }
        else if (comparison == EQUALS) {
            code_section << fmt::format("    JMPL {}", skip_label) << std::endl;
            code_section << fmt::format("    JMPG {}", skip_label) << std::endl;
        }
        else if (comparison == LESS_THAN) {
            code_section << fmt::format("    JMPE {}", skip_label) << std::endl;
            code_section << fmt::format("    JMPG {}", skip_label) << std::endl;
        }
        else if (comparison == LESS_THAN_OR_EQUAL_TO) {
            code_section << fmt::format("    JMPG {}", skip_label) << std::endl;
        }
        else if (comparison == GREATER_THAN) {
            code_section << fmt::format("    JMPE {}", skip_label) << std::endl;
            code_section << fmt::format("    JMPL {}", skip_label) << std::endl;
        }
        else if (comparison == GREATER_THAN_OR_EQUAL_TO) {
            code_section << fmt::format("    JMPL {}", skip_label) << std::endl;
        }

        generateAsm(conditional->getBeginEndBlock());

        code_section << fmt::format("    {}:", skip_label) << std::endl;
        label_counter++;
        code_section << "    // End conditional node." << std::endl;
    }

    else if (node->getNodeType() == CONDITION_NODE) {
        code_section << "    // Start condition node." << std::endl;
        ASTConditionNode *condition = (ASTConditionNode *) node;

        generateAsm(condition->getExpression1());
        code_section << "    MOV A,C" << std::endl;

        generateAsm(condition->getExpression2());

        code_section << "    CMP C,A" << std::endl;
        code_section << "    // End condition node." << std::endl;
    }

    else if (node->getNodeType() == BEGIN_END_BLOCK_NODE) {
        code_section << "    // Start begin . . . end block node." << std::endl;
        ASTBeginEndBlockNode *begin_end_block = (ASTBeginEndBlockNode *) node;
        std::vector<ASTStatementNode*> children = begin_end_block->getChildren();

        for (int i = 0; i < children.size(); i++) {
            generateAsm(children[i]);
        }
        code_section << "    // End begin . . . end block node." << std::endl;
    }

    else if (node->getNodeType() == FUNCTION_CALL_NODE) {
        code_section << "    // Start function call node." << std::endl;
        ASTFunctionCallNode *function_call = (ASTFunctionCallNode *) node;

        if (function_call->getFunctionName() == "OUT") {
            code_section << "    LOAD output_address,A" << std::endl;
            code_section << "    LOAD output_value,B" << std::endl;
            code_section << "    OUT A,B" << std::endl;
        }
        else if (function_call->getFunctionName() == "HALT") {
            code_section << "    HALT" << std::endl;
        }
        else {
            std::cout << "\033[1;31mERROR: Custom functions are currently not supported.\033[0m" << std::endl;
        }

        code_section << "    // End function call node." << std::endl;
    }

    else if (node->getNodeType() == WHILE_LOOP_NODE) {
        code_section << "    // Start while loop node." << std::endl;
        ASTWhileLoopNode *while_loop = (ASTWhileLoopNode *) node;

        std::string start_label = fmt::format("label{}", label_counter);
        label_counter++;
        code_section << fmt::format("    {}:", start_label) << std::endl;

        generateAsm(while_loop->getCondition());

        std::string skip_label = fmt::format("label{}", label_counter);
        label_counter++;
        ConditionNodeComparison comparison = while_loop->getCondition()->getComparison();
        if (comparison == NOT_EQUALS) {
            code_section << fmt::format("    JMPE {}", skip_label) << std::endl;
        }
        else if (comparison == EQUALS) {
            code_section << fmt::format("    JMPL {}", skip_label) << std::endl;
            code_section << fmt::format("    JMPG {}", skip_label) << std::endl;
        }
        else if (comparison == LESS_THAN) {
            code_section << fmt::format("    JMPE {}", skip_label) << std::endl;
            code_section << fmt::format("    JMPG {}", skip_label) << std::endl;
        }
        else if (comparison == LESS_THAN_OR_EQUAL_TO) {
            code_section << fmt::format("    JMPG {}", skip_label) << std::endl;
        }
        else if (comparison == GREATER_THAN) {
            code_section << fmt::format("    JMPE {}", skip_label) << std::endl;
            code_section << fmt::format("    JMPL {}", skip_label) << std::endl;
        }
        else if (comparison == GREATER_THAN_OR_EQUAL_TO) {
            code_section << fmt::format("    JMPL {}", skip_label) << std::endl;
        }

        generateAsm(while_loop->getBeginEndBlock());

        code_section << "    CMP A,A" << std::endl;
        code_section << fmt::format("    JMPE {}", start_label) << std::endl;
        code_section << fmt::format("    {}:", skip_label) << std::endl;
    }
}
