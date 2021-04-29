#include "VariableValue.h"

using namespace tmshell;

const char* IVariableValue::BaseVar[] = {"int", "string", "time_point",
                                                "duration", "periodic"};

IVariableValue::IVariableValue(const std::string& type):_typeName(type) {
}

StructValue::StructValue(const std::string& typeName)
  :IVariableValue(typeName),
  _field()
{
}


StructValue::StructValue(const StructValue& that)
  : IVariableValue(that.getTypeName()),
  _field()
{
  for (auto iter = that._field.begin(); iter!= that._field.end(); ++iter) {
    std::string k = iter->first;
    IVariableValue* v = iter->second.get();
    this->_field[k] = v->copy();
  }
}

StructValue::StructValue(StructValue&& that):
  IVariableValue(that.getTypeName()),
  _field(std::move(that._field))
{
}

StructValue::~StructValue() {
  _field.clear();
}

StructValue& StructValue::operator=(const StructValue& that) {
  return StructValue(that);
}

StructValue& StructValue::operator=(StructValue&& that) {
  return StructValue(that);
}

StructValue& ofPriodic(TimePoint start, TimePoint end, Duration repeat) {
  StructValue newobj(IVariableValue::BaseVar[4]);
  newobj.addField("start", &TimePointValue(start));
  newobj.addField("end", &TimePointValue(end));
  newobj.addField("repeat", &DurationValue(repeat));
  return newobj;
}

IVariableValue* StructValue::getField(const std::string& fieldName) const {
  if (_field.count(fieldName) == 0) {
    return nullptr;
  } else {
    return _field.at(fieldName).get();
  }
}

bool StructValue::checkField(const std::string& fieldName) const {
  return _field.count(fieldName) > 0;
}

bool StructValue::addField(const std::string& fieldName, const IVariableValue* value) {
  if (checkField(fieldName)) {
    return false;
  } else {
    _field[fieldName] = value->copy();
  }
}

bool StructValue::setField(const std::string& fieldName, const IVariableValue* value) {
  if (!checkField(fieldName)) {
    return false;
  } else {
    _field[fieldName] = value->copy();
  }
}
