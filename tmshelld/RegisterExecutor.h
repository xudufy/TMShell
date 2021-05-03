#pragma once
#include "../common/common.h"
#include "LoggedBaseVisitor.h"
#include "VariableValue.h"
#include "ScopeManager.h"
#include "TypeChecker.h"
namespace tmshell {

std::string runRegister(std::string const & input);

class RegisterExecutor : public LoggedBaseVisitor {
private:
  std::vector<std::unique_ptr<IVariableValue>> stack;
  ScopeManager scope;
  
public:
  friend std::string runRegister(std::string const &);
};


} // namespace tmshell