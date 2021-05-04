#include "GlobalScope.h"

using namespace tmshell;

std::unique_ptr<IVariableValue> GlobalScope::getField(const std::string& fieldName) {
  std::lock_guard<std::recursive_mutex> lock(objmtx);
  return StructValue::getField(fieldName)->copy();
}

bool GlobalScope::checkField(const std::string& fieldName) {
  std::lock_guard<std::recursive_mutex> lock(objmtx);
  return StructValue::checkField(fieldName);
}

bool GlobalScope::addField(const std::string& fieldName, const IVariableValue & value) {
  std::lock_guard<std::recursive_mutex> lock(objmtx);
  return StructValue::addField(fieldName, value);
}

bool GlobalScope::setField(const std::string& fieldName, const IVariableValue & value) {
  std::lock_guard<std::recursive_mutex> lock(objmtx);
  return StructValue::setField(fieldName, value);
}