#pragma once
#include "../common/common.h"
#include "../parser/TMSlang.h"
#include "ExecutionError.h"

namespace tmshell {

class LoggedBaseVisitor : public TMSlangBaseVisitor{
public:
  void addLog(const std::string & msg);

private:
  void error(antlr4::ParserRuleContext * context, const std::string & reason);

  void error(antlr4::ParserRuleContext * context, const std::exception & e);

  std::string getText(antlr4::ParserRuleContext * context);

public:
  std::string log;
  
};

} // namespace tmshell