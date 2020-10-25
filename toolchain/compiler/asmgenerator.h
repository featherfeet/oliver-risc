#include "processor.h"
#include "ast.h"
#include "stackframe.h"
#include <map>
#include <string>

class AssemblyGenerator {
    int label_counter = 0;
    int string_counter = 0;
    Stackframe *global_stackframe = nullptr;
    Stackframe *current_stackframe = nullptr;
    std::map<std::string, OPERAND_C_TYPE> stack_allocations; // Table that relates procedure names to how much stack space they take up.
    std::string generateStackVariableRead(std::string variable_name, std::string destination_register);
    std::string generateStackVariableWrite(std::string source_register, std::string variable_name);
    std::string generateStackVariableWrite(OPERAND_C_TYPE constant_value, std::string variable_name);
    std::string generateStackVariableStringLoad(std::string string_name, std::string variable_name);
    std::tuple<std::string, std::string> generateAsm(ASTNode *node);

    public:
        AssemblyGenerator();
        std::string getGeneratedAssembly(ASTNode *node);
};
