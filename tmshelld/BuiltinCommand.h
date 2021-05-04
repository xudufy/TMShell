#pragma once
#include "../common/common.h"

#include <unordered_map>

#include "VariableValue.h"

namespace tmshell {

class BaseExecutor;

class BuiltinCommand {
public:
  explicit BuiltinCommand(BaseExecutor * e);

  BuiltinCommand(BuiltinCommand const&) = delete;
  void operator=(BuiltinCommand const&) = delete;

public:
  void call(const std::string & funcName, const std::vector<std::string> & args, bool checkOnly = false);
  void call(const std::string & funcName, bool checkOnly = false);

public: //public for test purpose
  void jump(const std::vector<std::string> & args, bool checkOnly);

  void speed(const std::vector<std::string> & args, bool checkOnly);

  void reset(const std::vector<std::string> & args, bool checkOnly);

  void remove(const std::vector<std::string> & args, bool checkOnly);

  void ls(const std::vector<std::string> & args, bool checkOnly);

  void run(const std::vector<std::string> & args, bool checkOnly);

  void signal(const std::vector<std::string> & args, bool checkOnly);

private:
  std::unique_ptr<IVariableValue> evalLocalExpr(std::string const & in);

private:
  BaseExecutor * env;
  static std::unordered_map<std::string, int> commandMap; //commandName, minimum arg count.
  static std::mutex initMutex;
  
};

} // namespace tmshell