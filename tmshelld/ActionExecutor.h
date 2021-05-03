#pragma once
#include "../common/common.h"
#include "LoggedBaseVisitor.h"
#include "VariableValue.h"
#include "ScopeManager.h"
#include "BuiltinFunction.h"

namespace tmshell {

//out: return the log of this run;
std::string runAction(std::string const & action);

class ActionExecutor : public LoggedBaseVisitor {
private:
  std::vector<std::unique_ptr<IVariableValue>> stack;
  ScopeManager scope;
  BuiltinFunc builtinFuncCtx;

public:
  friend std::string runAction(std::string const &);
  
  ActionExecutor():builtinFuncCtx(this) {}

};


} // namespace tmshell