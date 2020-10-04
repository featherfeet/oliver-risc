#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include "processor.h"
#include "asmgenerator.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

AssemblyGenerator::AssemblyGenerator() {
}

std::string AssemblyGenerator::generateStackVariableRead(std::string variable_name, std::string destination_register) {
    std::stringstream code;
    if (variable_name == "output_address" || variable_name == "output_value") {
        code << fmt::format("    LOAD {},{}", variable_name, destination_register) << std::endl;
    }
    else {
        // Generate code to load from address (G + variable_offset) in RAM to the specified destination register. Remember that G is the register that stores the stack pointer.
        code << fmt::format("    CLOAD {},A", current_stackframe->getVariableOffset(variable_name)) << std::endl;
        code << "    ADD G,A" << std::endl;
        code << fmt::format("    RLOAD A,{}", destination_register) << std::endl;
    }
    return code.str();
}

std::string AssemblyGenerator::generateStackVariableWrite(std::string source_register, std::string variable_name) {
    std::stringstream code;
    if (variable_name == "output_address" || variable_name == "output_value") {
        code << fmt::format("    STORE {},{}", source_register, variable_name) << std::endl;
    }
    else {
        // Generate code to store a value from the source register to address (G + variable_offset) in RAM. Remember that G is the register that stores the stack pointer.
        code << fmt::format("    CLOAD {},A", current_stackframe->getVariableOffset(variable_name)) << std::endl;
        code << "    ADD G,A" << std::endl;
        code << fmt::format("    RSTORE {},A", source_register) << std::endl;
    }
    return code.str();
}

std::string AssemblyGenerator::generateStackVariableWrite(OPERAND_C_TYPE constant_value, std::string variable_name) {
    std::stringstream code;
    if (variable_name == "output_address" || variable_name == "output_value") {
        code << fmt::format("    CLOAD {},A", constant_value) << std::endl;
        code << fmt::format("    STORE A,{}", variable_name) << std::endl;
    }
    else {
        // Generate code to store a value from the source register to address (G + variable_offset) in RAM. Remember that G is the register that stores the stack pointer.
        code << fmt::format("    CLOAD {},A", current_stackframe->getVariableOffset(variable_name)) << std::endl;
        code << "    ADD G,A" << std::endl;
        code << fmt::format("    CLOAD {},B", constant_value) << std::endl;
        code << "    RSTORE B,A" << std::endl;
    }
    return code.str();
}

std::string AssemblyGenerator::getGeneratedAssembly(ASTNode *node) {
    auto generated_assembly = generateAsm(node);
    return std::get<0>(generated_assembly) + std::get<1>(generated_assembly);
}

std::tuple<std::string, std::string> AssemblyGenerator::generateAsm(ASTNode *node) {
    std::stringstream data_section;
    std::stringstream code_section;

    if (node->getNodeType() == ROOT_NODE) {
        ASTRootNode *rootNode = (ASTRootNode *) node;
        std::vector<ASTStatementNode*> children = rootNode->getChildren();

        current_stackframe = new Stackframe();

        data_section << ".data:" << std::endl;
        data_section << "    output_address = 0" << std::endl;
        data_section << "    output_value = 0" << std::endl;

        code_section << ".code:" << std::endl;
        code_section << "    // Start root node." << std::endl;
        code_section << "    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0)." << std::endl;

        for (int i = 0; i < children.size(); i++) {
            auto generated_assembly = generateAsm(children[i]);
            data_section << std::get<0>(generated_assembly);
            code_section << std::get<1>(generated_assembly);
        }

        delete current_stackframe;
        code_section << "    // End root node." << std::endl;
    }

    else if (node->getNodeType() == VARIABLE_DECLARATION_NODE) {
        ASTVariableDeclarationNode *declaration = (ASTVariableDeclarationNode *) node;
        /*
        data_section << "    // Start variable declaration node." << std::endl;
        data_section << fmt::format("    {} = 0", declaration->getVariableName()) << std::endl;
        data_section << "    // End variable declaration node." << std::endl;
        code_section << "    // Start variable declaration node." << std::endl;
        // Variable may need to be re-initialized if this declaration is inside a loop, so we have to CLOAD it every time.
        code_section << fmt::format("    CLOAD {},A", declaration->getValue()) << std::endl;
        code_section << fmt::format("    STORE A,{}", declaration->getVariableName()) << std::endl;
        code_section << "    // End variable declaration node." << std::endl;
        */
        current_stackframe->addVariable(declaration->getVariableName(), OPERAND_SIZE);
        code_section << generateStackVariableWrite(declaration->getValue(), declaration->getVariableName());
    }

    else if (node->getNodeType() == VARIABLE_ASSIGNMENT_NODE) {
        code_section << "    // Start variable assignment node." << std::endl;
        ASTVariableAssignmentNode *assignment = (ASTVariableAssignmentNode *) node;

        // Generate assembly code that evaluates the expression and stores the result in register C.
        auto generated_expression_assembly = generateAsm(assignment->getExpressionNode());
        data_section << std::get<0>(generated_expression_assembly);
        code_section << std::get<1>(generated_expression_assembly);

        code_section << generateStackVariableWrite("C", assignment->getVariableName()) << std::endl;

        code_section << "    // End variable assignment node." << std::endl;
    }

    else if (node->getNodeType() == EXPRESSION_NODE) {
        code_section << "    // Start expression node." << std::endl;
        ASTExpressionNode *expression = (ASTExpressionNode *) node;
        std::vector<ASTTermNode*> terms = expression->getTerms();

        // Generate assembly that evaluates the expression. Register C is used as the accumulator.
        code_section << "    CLOAD 0,C" << std::endl;

        for (int i = 0; i < terms.size(); i++) {
            ASTTermNode *term = terms[i];

            if (term->getType() == CONSTANT) {
                code_section << fmt::format("    CLOAD {},D", term->getConstantValue()) << std::endl;
            }
            else if (term->getType() == VARIABLE) {
                code_section << generateStackVariableRead(term->getVariableName(), "D") << std::endl;
            }
            if (term->getOperation() == ADDITION) {
                code_section << "    ADD C,D" << std::endl;
                code_section << "    MOV A,C" << std::endl;
            }
            else if (term->getOperation() == SUBTRACTION) {
                code_section << "    SUB C,D" << std::endl;
                code_section << "    MOV A,C" << std::endl;
            }
            else if (term->getOperation() == MULTIPLICATION) {
                code_section << "    MULT C,D" << std::endl;
                code_section << "    MOV A,C" << std::endl;
            }
            else if (term->getOperation() == DIVISION) {
                code_section << "    DIV C,D" << std::endl;
                code_section << "    MOV A,C" << std::endl;
            }
            else if (term->getOperation() == MODULUS) {
                code_section << "    DIV C,D" << std::endl;
                code_section << "    MOV A,C" << std::endl;
            }
        }
        code_section << "    // End expression node." << std::endl;
    }

    else if (node->getNodeType() == CONDITIONAL_NODE) {
        code_section << "    // Start conditional node." << std::endl;
        ASTConditionalNode *conditional = (ASTConditionalNode *) node;

        auto generated_condition_assembly = generateAsm(conditional->getCondition());
        data_section << std::get<0>(generated_condition_assembly);
        code_section << std::get<1>(generated_condition_assembly);

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

        auto generated_block_assembly = generateAsm(conditional->getBeginEndBlock());
        data_section << std::get<0>(generated_block_assembly);
        code_section << std::get<1>(generated_block_assembly);

        code_section << fmt::format("    {}:", skip_label) << std::endl;
        code_section << "    // End conditional node." << std::endl;
    }

    else if (node->getNodeType() == CONDITION_NODE) {
        code_section << "    // Start condition node." << std::endl;
        ASTConditionNode *condition = (ASTConditionNode *) node;

        // Generate assembly that evaluates the first expression in the condition into register C, then store C in E.
        auto generated_expression1_assembly = generateAsm(condition->getExpression1());
        data_section << std::get<0>(generated_expression1_assembly);
        code_section << std::get<1>(generated_expression1_assembly);
        code_section << "    MOV C,E" << std::endl;

        // Generate assembly that evaluates the second expression in the condition into register C.
        auto generated_expression2_assembly = generateAsm(condition->getExpression2());
        data_section << std::get<0>(generated_expression2_assembly);
        code_section << std::get<1>(generated_expression2_assembly);

        code_section << "    CMP E,C" << std::endl;
        code_section << "    // End condition node." << std::endl;
    }

    else if (node->getNodeType() == BEGIN_END_BLOCK_NODE) {
        code_section << "    // Start begin . . . end block node." << std::endl;
        ASTBeginEndBlockNode *begin_end_block = (ASTBeginEndBlockNode *) node;
        std::vector<ASTStatementNode*> children = begin_end_block->getChildren();

        for (int i = 0; i < children.size(); i++) {
            auto generated_statement_assembly = generateAsm(children[i]);
            data_section << std::get<0>(generated_statement_assembly);
            code_section << std::get<1>(generated_statement_assembly);
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
            // Subtract the number of bytes that the function's stack will take from G (the stack pointer). This has the effect of allocating space on the stack for the function's variables.
            code_section << fmt::format("    CLOAD {},A", stack_allocations[procedure_call->getProcedureName()]) << std::endl;
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

        auto generated_condition_assembly = generateAsm(while_loop->getCondition());
        data_section << std::get<0>(generated_condition_assembly);
        code_section << std::get<1>(generated_condition_assembly);

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

        auto generated_block_assembly = generateAsm(while_loop->getBeginEndBlock());
        data_section << std::get<0>(generated_block_assembly);
        code_section << std::get<1>(generated_block_assembly);

        code_section << "    CMP A,A" << std::endl;
        code_section << fmt::format("    JMPE {}", start_label) << std::endl;
        code_section << fmt::format("    {}:", skip_label) << std::endl;
    }

    else if (node->getNodeType() == PROCEDURE_NODE) {
        ASTProcedureNode *procedure = (ASTProcedureNode*) node;
        // Initialize a Stackframe object to track variables in the procedure.
        Stackframe *previous_stackframe = current_stackframe;
        current_stackframe = new Stackframe();
        // Generate code for the procedure.
        code_section << "    // Start procedure node." << std::endl;
        // Generate instructions that cause the CPU to skip executing the procedure when IP passes through here. This way, the procedure only gets executed if the program jumps directly to the start_procedure_{procedurename} label.
        code_section << fmt::format("    CMP A,A") << std::endl;
        code_section << fmt::format("    JMPE end_procedure_{}", procedure->getProcedureName()) << std::endl;
        code_section << fmt::format("    start_procedure_{}:", procedure->getProcedureName()) << std::endl;
        // Generate instructions for the body of the procedure.
        auto generated_block_assembly = generateAsm(procedure->getBeginEndBlock());
        data_section << std::get<0>(generated_block_assembly);
        code_section << std::get<1>(generated_block_assembly);
        // Generate instructions to exit the procedure and return to the calling stack frame.
        code_section << fmt::format("    MOV G,B") << std::endl; // Save stack pointer value before incrementing it.
        code_section << fmt::format("    CLOAD {},A", current_stackframe->getTotalSize()) << std::endl; // Add the number of bytes that the function's stack took to the stack pointer. This has the effect of de-allocating the stack memory used by the function.
        code_section << fmt::format("    ADD A,G") << std::endl;
        code_section << fmt::format("    MOV A,G") << std::endl;
        code_section << fmt::format("    RLOAD B,IP") << std::endl; // Return from the procedure by jumping IP back to where the stack pointer was before incrementing it.
        // End label.
        code_section << fmt::format("    end_procedure_{}:", procedure->getProcedureName()) << std::endl;
        code_section << "    // End procedure node." << std::endl;
        stack_allocations[procedure->getProcedureName()] = current_stackframe->getTotalSize(); // Store the amount of RAM that the function's stack takes up in a global table. This will be used to allocate memory for the function when it is called.
        delete current_stackframe;
        current_stackframe = previous_stackframe;
    }

    return std::make_tuple(data_section.str(), code_section.str());
}
