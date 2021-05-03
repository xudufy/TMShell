#pragma once
#include "../common/common.h"
#include "LoggedBaseVisitor.h"
#include "VariableValue.h"
#include "ScopeManager.h"

namespace tmshell {

class TypeChecker : public LoggedBaseVisitor {
private:
  std::vector<std::unique_ptr<IVariableValue>> stack;
  ScopeManager scope;
};

} 
