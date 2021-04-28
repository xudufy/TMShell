#include "../parser/TMSlang.h"
#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>

#include "../common/StringErrorListener.h"
using namespace boost::filesystem;

using namespace tmshell;
using namespace antlr4;

int main(int argc, char* argv[]) {
  if (argc == 1) { //interactive mode
    std::string partialCommand;
    ANTLRInputStream input(partialCommand);
    
    while(true) {
      std::string line;
      std::getline(std::cin, line);
      line+='\n';
      partialCommand+=line;
      input.load(partialCommand);
      TMSlangLexer lexer(&input);
      CommonTokenStream tokens(&lexer);
      TMSlangParser parser(&tokens);
      parser.setErrorHandler(std::make_shared<BailErrorStrategy>());
      parser.removeErrorListeners();
      StringErrorListener log;
      parser.addErrorListener(&log);

      TMSlangParser::Execute_lineContext* tree=nullptr;   
      try
      {
        tree = parser.execute_line();
      }
      catch(const InputMismatchException& e)
      {
        std::cout<<parser.getExpectedTokens().toString(parser.getVocabulary())<<std::endl;
      }
      catch(const ParseCancellationException& e)
      {
        try {
            std::rethrow_if_nested(e);
        } catch(const RecognitionException& e) {
          BailErrorStrategy().reportError(&parser, e);
        }
      }



      if (tree!=nullptr) { //success
        std::cout << tree->toStringTree() << std::endl;
        partialCommand.clear();
      } else if (log.offendingToken == "<EOF>") {
        std::cout << ">>> ";
      } else {
          std::cout << log.msg << std::endl;
          partialCommand.clear();
      }

    }
  } else { //file mode
      for (int i = 1; i < argc; i++) {
           
      }
  }


  return 0;
}