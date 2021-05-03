#include "ActionExecutor.h"

namespace tmshell {

std::string runAction(std::string const & action) {
  ParserInstance parser(action);
  auto * tree = parser.parseAction();
  if (!parser.isComleted()) {
    throw ExecutionError(parser.getLastError());
  }
  
  ActionExecutor executor;
  tree->accept(&executor);
  ASSERT(executor.stack.size() == 1, "stack size after action execution is not 1");
  
  return executor.log;
}

} // namespace tmshell