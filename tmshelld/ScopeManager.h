#pragma once
#include "../common/common.h"
#include <boost/asio.hpp>


#include "VariableValue.h"
#include "GlobalScope.h"

namespace tmshell {

class ScopeManager {
public:
  ScopeManager();

  void enterScope();
  void exitScope();
  
  void addSymbol(std::string const & name, const IVariableValue & value);
  void addGlobal(std::string const & name, const IVariableValue & value);  
  IVariableValue* getSymbol(const std::string & name);
  void setSymbol(std::string const & name, const IVariableValue & value);

private:
  std::vector<Scope> scopes;

};

}