#pragma once
#include "../common/common.h"
#include <chrono>
#include <mutex>

#include "VariableValue.h"

namespace tmshell {

class Scope : public StructValue {
public:
  Scope():StructValue("scope"){}
  //other default members should be set implicitly.
};

class GlobalScope: public Scope{
public:
  static GlobalScope& getInstance() {
    static GlobalScope instance; 
    return instance;
  }

  //To ensure thread safe, we must return a copy.
  //SHOULD NOT BE VIRTUAL.
  std::unique_ptr<IVariableValue> getField(const std::string& fieldName);
  bool checkField(const std::string& fieldName);
  bool addField(const std::string& fieldName, const IVariableValue & value);
  bool setField(const std::string& fieldName, const IVariableValue & value);

  void lock() {
    objmtx.lock();
  }

  void unlock() {
    objmtx.unlock();
  }

private:
  GlobalScope(){}

public:
  GlobalScope(GlobalScope const&) = delete;
  void operator=(GlobalScope const&) = delete;
  
private:
  std::recursive_mutex objmtx;
};

}