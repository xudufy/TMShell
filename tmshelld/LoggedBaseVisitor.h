#pragma once
#include "../common/common.h"
#include "../parser/TMSlang.h"
#include "ExecutionError.h"
#include "VariableValue.h"
#include "ScopeManager.h"
#include "BuiltinFunc.h"

namespace tmshell {

class LoggedBaseVisitor : public TMSlangVisitor{
public:
  void addLog(const std::string & msg);

protected:
  void error(antlr4::ParserRuleContext * context, const std::string & reason);

  void error(antlr4::ParserRuleContext * context, const std::exception & e);

  std::string getText(antlr4::ParserRuleContext * context);

public:
  std::string log;
  
};

class BaseExecutor : public LoggedBaseVisitor {
protected:
  std::vector<std::unique_ptr<IVariableValue>> stack;
  
  ScopeManager defaultScope;
  
  // allow switch ScopeManager in TypeChecker.
  ScopeManager & scope = defaultScope; 
  BuiltinFunc builtinFuncCtx;

public:

  void push_stack(IVariableValue const & to_push) {
    stack.emplace_back(std::move(to_push.copy()));
  }

  //the value will be copied to vector.
  template<typename T, int = get_type_id_v<T>>
  void push_stack_v(T to_push_v) {
    SimpleVariableValue<T> dummy(to_push_v);
    push_stack(dummy);
  }

  void push_stack_v() {
    VoidValue v;
    push_stack(v);
  }

  std::unique_ptr<IVariableValue> pop_stack() {
    ASSERT(stack.size()>0, "stack exhausted.");
    auto ptr = std::move(stack.back());
    stack.pop_back();
    return ptr; 
  }

public:
  friend std::string runAction(std::string const &, int);
  friend class BuiltinFunc;
  friend class BuiltinCommand;
  
  explicit BaseExecutor():builtinFuncCtx(this) {}

};

} // namespace tmshell