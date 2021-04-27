#include "../parser/TMSlang.h"
#include <iostream>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

using namespace tmshell;
using namespace antlr4;

int main(int argc, char* argv[]) {
   
    ANTLRInputStream input(std::cin);
    TMSlangLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    TMSlangParser parser(&tokens);

    TMSlangParser::ProgramContext* tree = parser.program();
    
    std::cout<<tree->getText()<<std::endl;
    std::cout << argv[0] << " " << file_size(argv[0]) << '\n';

    return 0;
}