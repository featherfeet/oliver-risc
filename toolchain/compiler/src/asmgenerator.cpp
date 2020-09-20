#include <iostream>
#include <string>
#include "processor.h"
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
        code_section << "    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0)." << std::endl;
        for (int i = 0; i < children.size(); i++) {
            generateAsm(children[i]);
        }
        code_section << "    // End root node." << std::endl;
    }

    else if (node->getNodeType() == VARIABLE_DECLARATION_NODE) {
        ASTVariableDeclarationNode *declaration = (ASTVariableDeclarationNode *) node;
        data_section << "    // Start variable declaration node." << std::endl;
        data_section << fmt::format("    {} = 0", declaration->getVariableName()) << std::endl;
        data_section << "    // End variable declaration node." << std::endl;
        code_section << "    // Start variable declaration node." << std::endl;
        // Variable may need to be re-initialized if this declaration is inside a loop, so we have to CLOAD it every time.
        code_section << fmt::format("    CLOAD {},A", declaration->getValue()) << std::endl;
        code_section << fmt::format("    STORE A,{}", declaration->getVariableName()) << std::endl;
        code_section << "    // End variable declaration node." << std::endl;
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
            if (term->getOperation() == ADDITION) {
                code_section << "    ADD A,B" << std::endl;
            }
            else if (term->getOperation() == SUBTRACTION) {
                code_section << "    SUB A,B" << std::endl;
            }
            else if (term->getOperation() == MULTIPLICATION) {
                code_section << "    MULT A,B" << std::endl;
            }
            else if (term->getOperation() == DIVISION) {
                code_section << "    DIV A,B" << std::endl;
            }
            else if (term->getOperation() == MODULUS) {
                code_section << "    DIV A,B" << std::endl;
                code_section << "    MOV B,A" << std::endl;
            }
        }
        code_section << "    // End expression node." << std::endl;
    }

    else if (node->getNodeType() == CONDITIONAL_NODE) {
        code_section << "    // Start conditional node." << std::endl;
        ASTConditionalNode *conditional = (ASTConditionalNode *) node;

        generateAsm(conditional->getCondition());

        std::string skip_label = fmt::format("label{}", label_counter);
        label_counter++;
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

    else if (node->getNodeType() == PROCEDURE_CALL_NODE) {
        code_section << "    // Start procedure call node." << std::endl;
        ASTProcedureCallNode *procedure_call = (ASTProcedureCallNode *) node;

        if (procedure_call->getProcedureName() == "OUT") {
            code_section << "    LOAD output_address,A" << std::endl;
            code_section << "    LOAD output_value,B" << std::endl;
            code_section << "    OUT A,B" << std::endl;
        }
        else if (procedure_call->getProcedureName() == "HALT") {
            code_section << "    HALT" << std::endl;
        }
        else {
            // Code to call a custom procedure (see how the stack works at http://faculty.cooper.edu/smyth/cs225/ch6/fncs.htm). G is used as the stack pointer register.
            // Add OPERAND_SIZE bytes to G (the stack pointer).
            code_section << fmt::format("    CLOAD {},A", OPERAND_SIZE) << std::endl;
            code_section << "    SUB G,A" << std::endl;
            code_section << "    MOV A,G" << std::endl;
            // Store IP (plus 2 instructions to avoid repeating the CMP/JMPE instructions on return) in the stack pointer register.
            code_section << fmt::format("    CLOAD {},A", 2 * INSTRUCTION_SIZE) << std::endl;
            code_section << "    ADD IP,A" << std::endl;
            code_section << "    RSTORE A,G" << std::endl; // Store A (which now has the value IP + 2 * INSTRUCTION_SIZE) into memory at the location specified by the stack pointer (G).
            // Start the procedure.
            code_section << "    CMP A,A" << std::endl;
            code_section << fmt::format("    JMPE start_procedure_{}", procedure_call->getProcedureName()) << std::endl;
        }

        code_section << "    // End procedure call node." << std::endl;
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

    else if (node->getNodeType() == PROCEDURE_NODE) {
        ASTProcedureNode *procedure = (ASTProcedureNode*) node;

        code_section << "    // Start procedure node." << std::endl;
        // Generate instructions that cause the CPU to skip executing the procedure when IP passes through here.
        code_section << fmt::format("    CMP A,A") << std::endl;
        code_section << fmt::format("    JMPE end_procedure_{}", procedure->getProcedureName()) << std::endl;
        code_section << fmt::format("    start_procedure_{}:", procedure->getProcedureName()) << std::endl;
        // Generate instructions for the body of the procedure.
        generateAsm(procedure->getBeginEndBlock());
        // Generate instructions to exit the procedure and return to the calling stack frame.
        code_section << fmt::format("    MOV G,B") << std::endl; // Save stack pointer value before incrementing it.
        code_section << fmt::format("    CLOAD {},A", OPERAND_SIZE) << std::endl; // Add OPERAND_SIZE bytes to the stack pointer.
        code_section << fmt::format("    ADD A,G") << std::endl;
        code_section << fmt::format("    MOV A,G") << std::endl;
        code_section << fmt::format("    RLOAD B,IP") << std::endl; // Return from the procedure by jumping IP back to where the stack pointer was before incrementing it.
        // End label.
        code_section << fmt::format("    end_procedure_{}:", procedure->getProcedureName()) << std::endl;
        code_section << "    // End procedure node." << std::endl;
    }
}
