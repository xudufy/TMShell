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

IVariableValue* ScopeManager::getSymbol(const std::string & name) {
  for (auto i = scopes.size()-1; i>=0; i-- ) {
    if (scopes[i].checkField(name)) {
      return scopes[i].getField(name);
    }
  }

  if (GlobalScope::getInstance().checkField(name)) {
    return GlobalScope::getInstance().getField(name);
  }

  throw ExecutionError("Variable " + name + " not found.");

}

void ScopeManager::setSymbol(std::string const & name, const IVariableValue & value) {
  for (auto i = scopes.size()-1; i>=0; i-- ) {
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
  if (!success) {
    throw ExecutionError("Variable " + name + " defined more than once in global.");
  }
}



}