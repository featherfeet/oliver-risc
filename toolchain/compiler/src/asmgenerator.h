#include "ast.h"
#include <string>
#include <sstream>

class AssemblyGenerator {
    int label_counter = 0;
    std::stringstream data_section;
    std::stringstream code_section;

    public:
        AssemblyGenerator();
        void generateAsm(ASTNode *node);
        std::string getGeneratedAssembly();
};
