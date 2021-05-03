#pragma once
#include "../common/common.h"

#include <unordered_map>

#include "VariableValue.h"

namespace tmshell {

class ActionExecutor;

class BuiltinFunc {
public:
  explicit BuiltinFunc(ActionExecutor * e);

  BuiltinFunc(BuiltinFunc const&) = delete;
  void operator=(BuiltinFunc const&) = delete;

public:
  std::unique_ptr<IVariableValue> call(const std::string & funcName, const std::vector<IVariableValue *> & args);
  std::unique_ptr<IVariableValue> call(const std::string & funcName);

public: //public for test purpose
  VoidValue alert(const std::string & msg);

  VoidValue log(const std::string & msg);

  BoolValue signal(const std::string & name);

  BoolValue shell_open(const std::string & path);

  BoolValue run(const std::string & path);
  
  BoolValue disconnect();

  [[ noreturn ]] VoidValue _return();
private:
  ActionExecutor * env;
  static std::unordered_map<std::string, std::vector<std::string>> funcMap;
  static std::mutex initMutex;
  
};

} // namespace tmshell