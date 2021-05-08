#pragma once
#include "../common/common.h"

#include <unordered_map>

#include "VariableValue.h"

namespace tmshell {

class LoggedBaseVisitor;

class BuiltinFunc {
public:
  explicit BuiltinFunc(LoggedBaseVisitor * e);

  BuiltinFunc(BuiltinFunc const&) = delete;
  void operator=(BuiltinFunc const&) = delete;

public:
  std::unique_ptr<IVariableValue> call(const std::string & funcName, const std::vector<IVariableValue *> & args, bool checkOnly = false);
  std::unique_ptr<IVariableValue> call(const std::string & funcName, bool checkOnly = false);

public:
  VoidValue alert(const std::string & msg);

  VoidValue log(const std::string & msg);

  BoolValue signal(const std::string & name);

  BoolValue shell_open(const std::string & path);

  BoolValue run(const std::string & path);
  
  BoolValue disconnect();

  [[ noreturn ]] void _return();
private:
  LoggedBaseVisitor * env;
  const static std::unordered_map<std::string, std::vector<std::string>> funcMap;
  
};

} // namespace tmshell