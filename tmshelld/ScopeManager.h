#pragma once
#include "../common/common.h"
#include <boost/asio.hpp>
#include <chrono>

#include "VariableValue.h"

namespace tmshell {

using Scope = StructValue;

class ScopeManager {
public:
  static ScopeManager& getInstance() {
    static ScopeManager instance; 
    return instance;
  }

  
  
private:  


private:
  ScopeManager() {}

public:
  ScopeManager(ScopeManager const&) = delete;
  void operator=(ScopeManager const&) = delete;
  
};

}