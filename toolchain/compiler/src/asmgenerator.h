#include "ast.h"
#include "stackframe.h"
#include <string>

class AssemblyGenerator {
    int label_counter = 0;
    Stackframe *current_stackframe = nullptr;
    std::tuple<std::string, std::string> generateAsm(ASTNode *node);

    public:
        AssemblyGenerator();
        std::string getGeneratedAssembly(ASTNode *node);
};
