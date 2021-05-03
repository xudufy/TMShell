#include "RegisterExecutor.h"

namespace tmshell {

std::string runRegister(std::string const & input) {
  ParserInstance parser(input);
  auto* tree = parser.parseProgram();
  if (!parser.isComleted()) {
    throw ExecutionError(parser.getLastError());
  }

  TypeChecker tcker;
  tree->accept(&tcker);

  RegisterExecutor re;
  tree->accept(&re);

  return re.log;  
} 

} // namespace tmshell