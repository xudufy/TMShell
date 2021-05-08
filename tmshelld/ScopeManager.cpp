#include "ScopeManager.h"
#include "GlobalScope.h"
#include "ExecutionError.h"

namespace tmshell {

ScopeManager::ScopeManager() {
  scopes.emplace_back();
}

void ScopeManager::enterScope(){
  scopes.emplace_back();
}

void ScopeManager::exitScope(){
  if (scopes.size() <= 1) {
    throw ExecutionError("Cannot exit root scope.");
  }

  scopes.pop_back();
}


void ScopeManager::addSymbol(std::string const & name, const IVariableValue & value) {
  bool success = scopes.back().addField(name, value);
  if (!success) {
    throw ExecutionError("Variable " + name + " defined more than once.");
  }
}

std::unique_ptr<IVariableValue> ScopeManager::getSymbol(const std::string & name) {
  for (auto i = scopes.size(); i-- >0;) {
    if (scopes[i].checkField(name)) {
      return scopes[i].getField(name)->copy();
    }
  }

  if (GlobalScope::getInstance().checkField(name)) {
    return GlobalScope::getInstance().getField(name);
  }

  throw ExecutionError("Variable " + name + " not found.");

}

void ScopeManager::setSymbol(std::string const & name, const IVariableValue & value) {
  for (auto i = scopes.size(); i-- >0;) {
    bool success = scopes[i].setField(name, value);
    if (success) {
      return;
    }
  }

  if (GlobalScope::getInstance().setField(name, value)) {
    return;
  }

  throw ExecutionError("Variable " + name + " not found.");
}

void ScopeManager::addGlobal(std::string const & name, const IVariableValue & value) {
  bool success = GlobalScope::getInstance().addField(name, value);
  ASSERT(success, "sm.addglobal");
}

static void setStructValue(StructValue *sv, std::list<std::string> & ids, IVariableValue const & value) {
  if (ids.size() == 1) {
    sv->StructValue::setField(*ids.begin(), value);
  } else {
    IVariableValue * member = sv->StructValue::getField(*ids.begin());
    if (IVariableValue::is<StructValue>(member)) {
      ids.pop_front();
      setStructValue(dynamic_cast<StructValue*>(member), ids, value);
    } else {
      throw ExecutionError("Struct member assignment type error.");
    }
  }
}

void ScopeManager::setStructSymbol(std::vector<std::string> const & ids, IVariableValue const & value) {
  ASSERT(ids.size() >= 1, "setStructSymbol count error");
  std::list<std::string> ids_temp(ids.begin(), ids.end());
  for (auto i = scopes.size(); i-- >0;) {
    if (scopes[i].checkField(ids[0])) {
      setStructValue(&scopes[i], ids_temp, value);
      return;
    }
  }
  GlobalScope::getInstance().lock();

  setStructValue(&GlobalScope::getInstance(), ids_temp, value);

  GlobalScope::getInstance().unlock();

}

}