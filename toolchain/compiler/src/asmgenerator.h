#include "ast.h"
#include "stackframe.h"
#include <string>
#include <sstream>

class AssemblyGenerator {
    int label_counter = 0;
    std::stringstream data_section;
    std::stringstream code_section;
    Stackframe *current_stackframe = nullptr;

    public:
        AssemblyGenerator();
        void generateAsm(ASTNode *node);
        std::string getGeneratedAssembly();
};
