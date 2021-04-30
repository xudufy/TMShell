#include "GlobalScope.h"

using namespace tmshell;

IVariableValue* GlobalScope::getField(const std::string& fieldName) {
  std::lock_guard<std::mutex> lock(objmtx);
  return StructValue::getField(fieldName);
}

bool GlobalScope::checkField(const std::string& fieldName) {
  std::lock_guard<std::mutex> lock(objmtx);
  return StructValue::getField(fieldName);
}

bool GlobalScope::addField(const std::string& fieldName, const IVariableValue* value) {
  std::lock_guard<std::mutex> lock(objmtx);
  return StructValue::addField(fieldName, value);
}

bool GlobalScope::setField(const std::string& fieldName, const IVariableValue* value) {
  std::lock_guard<std::mutex> lock(objmtx);
  return StructValue::setField(fieldName, value);
}