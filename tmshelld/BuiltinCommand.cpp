#include "../common/common.h"
#include "BuiltinCommand.h"
#include "ActionExecutor.h"
#include "EventStorage.h"
#include "ExecutionError.h"
#include "WindowsSubsys.h"
#include "RegisterExecutor.h"
#include "InternalClock.h"
#include "EventStorage.h"


namespace tmshell {

const std::unordered_map<std::string, int> BuiltinCommand::commandMap{
  {"jump", 1},
  {"speed", 1},
  {"reset", 1},
  {"ls", 1},
  {"remove", 2},
  {"run", 1},
  {"signal", 1},
};

BuiltinCommand::BuiltinCommand(BaseExecutor * e):env(e){}

void BuiltinCommand::call(std::string const & funcName, std::vector<std::string> const & args, bool checkOnly) {
  if (commandMap.count(funcName) == 0) {
    throw ExecutionError("command " + funcName + " not found.");
  }

  auto & argc = commandMap.at(funcName);
  if (args.size() < argc) {
    throw ExecutionError("command " + funcName + " need more argments.");
  }

#define TMSHELL_CALL__L(A) if (funcName == #A) {A(args, checkOnly);return;}
  TMSHELL_CALL__L(jump)
  TMSHELL_CALL__L(speed)
  TMSHELL_CALL__L(reset)
  TMSHELL_CALL__L(ls)
  TMSHELL_CALL__L(remove)
  TMSHELL_CALL__L(run)
  TMSHELL_CALL__L(signal)
#undef TMSHELL_CALL__L

}

void BuiltinCommand::call(std::string const & funcName, bool checkOnly) {
  return call(funcName, {}, checkOnly);
}

std::unique_ptr<IVariableValue> BuiltinCommand::evalLocalExpr(std::string const & in) {
  if (in.find_first_of("{()}") != std::string::npos) {
    throw ExecutionError("{()} is not supported in command args");
  }

  ParserInstance parser(in);
  auto * tree = parser.parseAction();
  if (!parser.isComleted()) {
    throw ExecutionError("parse failed at" + in);
  }

  tree->accept(env); // reuse current scope and stack.
  auto result = env->pop_stack();
  return result;
}

void BuiltinCommand::jump(const std::vector<std::string> & args, bool checkOnly) {
  auto value_ref = evalLocalExpr(args[0]); // make sure it won't be freed before this function return.
  auto value_ptr = value_ref.get();
  if (!IVariableValue::is<TimePointValue>(value_ptr)) {
    throw ExecutionError("jump <TimePoint> type incorrect" + args[0]);
  }

  if (checkOnly) return;

  auto value = dynamic_cast<TimePointValue *>(value_ptr)->get();
  InternalClock::getInstance().setTime(value);
}

void BuiltinCommand::speed(const std::vector<std::string> & args, bool checkOnly) {
  std::stringstream ss(args[0]);
  double scale = 1;
  try {
    int temp;
    ss>>temp;
    scale = temp / 1000.0;
  } catch (std::exception const &) {
    throw ExecutionError("speed <int>:" + args[0] + "is not int." );
  }

  if (scale == 0 || scale>10 || scale<-10) {
    throw ExecutionError("speed <int>:" + args[0] + "0, <-10000, > 10000 is forbidden.");
  }
  
  if (checkOnly) return;
  InternalClock::getInstance().setScaler(scale);

}

void BuiltinCommand::reset(const std::vector<std::string> & args, bool checkOnly) {
  if (args[0] != "time") {
    throw ExecutionError("usage: reset time");
  }

  if (checkOnly) return;
  InternalClock::getInstance().reset();
}

void BuiltinCommand::remove(const std::vector<std::string> & args, bool checkOnly) {
  if (args[0] != "signal" && args[0] != "event") {
    throw ExecutionError("usage: remove [signal | event] <int>");
  }

  size_t index;
  if (args[0] == "event") {
    try {
      std::stringstream ss(args[1]);
      ss>>index;
    } catch (std::exception const &) {
      throw ExecutionError("usage: remove [signal | event] <int>" );
    }
  }
  
  if (checkOnly) return;
  
  auto& ev_s = EventStorage::getInstance();
  ev_s.lock();
  if (args[0] == "signal") {
    ev_s.str_events.remove_if([&args](const StringEvent & se) {return se.signal == args[1];});
  } else if (args[0] == "event") {
    ev_s.str_events.remove_if([index](const StringEvent & se) {return se.unique_id == index;});
    ev_s.tm_events.remove_if([index](const TimerEvent & se) {return se.unique_id == index;});
  }
  ev_s.unlock();
  
}

void BuiltinCommand::ls(const std::vector<std::string> & args, bool checkOnly) {
  if (args[0] != "event" && args[0] != "global") {
    throw ExecutionError("usage: ls [signal | event | global]");
  }

  if (checkOnly) return;
  if (args[0] == "event") {
    auto& ev_s = EventStorage::getInstance();
    ev_s.lock();
    for (auto item : ev_s.str_events) {
      env->addLog(item.to_string());
    }
    for (auto item : ev_s.tm_events) {
      env->addLog(item.to_string());
    }
    ev_s.unlock();
    return;
  }

  if (args[0] == "global") {
    auto& gs = GlobalScope::getInstance();
    gs.lock();
    env->addLog(gs.to_string());
    gs.unlock(); 
  }


}

void BuiltinCommand::run(const std::vector<std::string> & args, bool checkOnly) {
  try {
    WindowsSubsys::getInstance().file_read(args[0]);
  } catch (std::exception const & e) {
    throw ExecutionError(e.what());
  }

  if (checkOnly) return;

  env->builtinFuncCtx.run(args[0]); //can still throw exceptions.
}

void BuiltinCommand::signal(const std::vector<std::string> & args, bool checkOnly) {
  if (checkOnly) return;
  env->builtinFuncCtx.signal(args[0]);
}

}
