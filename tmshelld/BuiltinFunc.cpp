#include "BuiltinFunc.h"
#include "LoggedBaseVisitor.h"
#include "ActionExecutor.h"
#include "EventStorage.h"
#include "ExecutionError.h"
#include "WindowsSubsys.h"
#include "RegisterExecutor.h"

namespace tmshell {

std::unordered_map<std::string, std::vector<std::string>> BuiltinFunc::funcMap;
std::mutex BuiltinFunc::initMutex;

BuiltinFunc::BuiltinFunc(LoggedBaseVisitor * e):env(e){
  std::lock_guard<std::mutex> lock(initMutex);
  if (funcMap.size() == 0) {
    funcMap.insert({"alert", {"void", "string"}});
    funcMap.insert({"log", {"void", "string"}});
    funcMap.insert({"signal", {"bool","string"}});
    funcMap.insert({"shell_open", {"bool", "string"}});
    funcMap.insert({"run", {"bool", "string"}});
    funcMap.insert({"disconnect", {"bool"}});
    funcMap.insert({"return", {"void"}});
  }
}

std::unique_ptr<IVariableValue> BuiltinFunc::call(std::string const & funcName, std::vector<IVariableValue *> const & args, bool checkOnly) {
  if (funcMap.count(funcName) == 0) {
    throw ExecutionError("function name not found");
  }

  auto& funcspec = funcMap.at(funcName);
  std::vector<std::string> argv(funcspec.begin()+1, funcspec.end());
  auto argc = argv.size();
  if (argc != args.size()) {
    throw ExecutionError("function " + funcName + " arg count not match.");
  }

  std::vector<std::unique_ptr<IVariableValue>> _delete_when_return;
  std::vector<IVariableValue *> after_conversion;

  for (size_t i=0; i<argc; i++) {
    if (args.at(i)->getTypeName() != argv.at(i) 
        && argv.at(i) != "string") { // anything can be converted to string automatically
      throw ExecutionError("function " + funcName + " arg " + std::to_string(i) + " type not match:" + args.at(i)->getTypeName());
    }

    if (args.at(i)->getTypeName() != argv.at(i)) { //convert to string
      auto* arg = args.at(i);
      auto str_value = std::make_unique<StringValue>(arg->to_string());
      after_conversion.push_back(str_value.get());
      _delete_when_return.push_back(std::move(str_value));
    } else {
      after_conversion.push_back(args.at(i));
    }
  }

  if (checkOnly) {
    std::string returnType = funcspec.at(0);
    if (returnType == "bool") {
      return std::make_unique<BoolValue>(true);
    }
    return std::make_unique<VoidValue>();
  }

  if (funcName == "alert") {
    auto out = alert(dynamic_cast<StringValue *>(after_conversion[0])->get());
    return std::make_unique<decltype(out)>(std::move(out));
  } else if (funcName == "log") {
    auto out = log(dynamic_cast<StringValue *>(after_conversion[0])->get());
    return std::make_unique<decltype(out)>(std::move(out));
  } else if (funcName == "signal") {
    auto out = signal(dynamic_cast<StringValue *>(after_conversion[0])->get());
    return std::make_unique<decltype(out)>(std::move(out));
  
  } else if (funcName == "shell_open" ) {
    auto out = shell_open(dynamic_cast<StringValue *>(after_conversion[0])->get());
    return std::make_unique<decltype(out)>(std::move(out));
  
  } else if (funcName == "run") {
    auto out = run(dynamic_cast<StringValue *>(after_conversion[0])->get());
    return std::make_unique<decltype(out)>(std::move(out));
  
  }  else if (funcName == "disconnect") {
    auto out = disconnect();
    return std::make_unique<decltype(out)>(std::move(out));
  
  } else if (funcName == "return") {
    _return(); // no return;
  }
  
  return std::make_unique<BoolValue>(true);
}

std::unique_ptr<IVariableValue> BuiltinFunc::call(std::string const & funcName, bool checkOnly) {
  return call(funcName, {}, checkOnly);
}

VoidValue BuiltinFunc::alert(const std::string & msg) {
  WindowsSubsys::getInstance().alert(msg);
  return VoidValue();
}

VoidValue BuiltinFunc::log(const std::string & msg) {
  env->addLog(msg);
  return VoidValue();
}


BoolValue BuiltinFunc::signal(const std::string & name) {
  EventStorage & es = EventStorage::getInstance();
  std::vector<std::string> actions;
  es.lock();
  for (auto it: es.str_events) {
    actions.push_back(it.action);
  }
  es.unlock();

  if (actions.size() == 0) {
    env->addLog("signal " + name + " does not connect to any actions.");
  }

  bool allSuccess = true;
  for (auto action: actions) {
    try {
      runAction(action);
    } catch (ExecutionError const & e) {
      env->addLog(e.what());
      allSuccess = false;
    }
  }
  
  return allSuccess;
}


BoolValue BuiltinFunc::shell_open(const std::string & path) {
  std::string error_msg;
  bool success = WindowsSubsys::getInstance().shell_open(path, error_msg);
  if (!success) {
    env->addLog("shell_open failed:"+ error_msg + " at " + path);
  }
  return success;
}


BoolValue BuiltinFunc::run(const std::string & path) {
  try {
    std::string file_content;
    try {
      file_content = WindowsSubsys::getInstance().file_read(path);
    } catch (std::exception const & e) {
      throw ExecutionError("error when open file: " + path + ":" + e.what());
    }
    tmshell::runRegister(path);
  } catch (ExecutionError const & e) {
    env->addLog(e.what());
    return false;
  }
  return true;
}

BoolValue BuiltinFunc::disconnect() {
  //TODO
  return true;
}

[[ noreturn ]] void BuiltinFunc::_return() {
  throw JumpOutSignal();
}

}
