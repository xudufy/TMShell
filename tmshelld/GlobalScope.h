#pragma once
#include "../common/common.h"
#include <chrono>
#include <mutex>

#include "VariableValue.h"

namespace tmshell {

class GlobalScope: public StructValue{
public:
  static GlobalScope& getInstance() {
    static GlobalScope instance; 
    return instance;
  }

  IVariableValue* getField(const std::string& fieldName);
  bool checkField(const std::string& fieldName);
  bool addField(const std::string& fieldName, const IVariableValue* value);
  bool setField(const std::string& fieldName, const IVariableValue* value);

private:
  GlobalScope(): StructValue("scope"){}

public:
  GlobalScope(GlobalScope const&) = delete;
  void operator=(GlobalScope const&) = delete;
  
private:
  std::mutex objmtx;
};

}